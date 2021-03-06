/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */

/* 
 * Copyright (C) 2000 Eazel, Inc
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * Author: Maciej Stachowiak <mjs@eazel.com>
 */

/* nautilus-sidebar-loser.c - loser sidebar view component. This
   component fails on demand, either controlled by env variables
   during startup, or using toolbar buttons or menu items.  */

#include <config.h>
#include "nautilus-sidebar-loser.h"

#include <bonobo/bonobo-control.h>
#include <gtk/gtksignal.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <libgnome/gnome-i18n.h>
#include <libgnomeui/gnome-stock.h>
#include <libnautilus/nautilus-bonobo-ui.h>
#include <libnautilus-extensions/nautilus-gtk-macros.h>
#include <stdio.h>
#include <stdlib.h>


/* A NautilusSidebarLoser's private information. */
struct NautilusSidebarLoserDetails {
	char *uri;
	NautilusView *nautilus_view;
};

static void nautilus_sidebar_loser_initialize_class (NautilusSidebarLoserClass *klass);
static void nautilus_sidebar_loser_initialize       (NautilusSidebarLoser      *view);
static void nautilus_sidebar_loser_destroy          (GtkObject                      *object);

NAUTILUS_DEFINE_CLASS_BOILERPLATE (NautilusSidebarLoser, nautilus_sidebar_loser, GTK_TYPE_LABEL)
     
static void loser_load_location_callback      (NautilusView         *nautilus_view,
					       const char           *location,
					       NautilusSidebarLoser *view);
static void loser_merge_bonobo_items_callback (BonoboObject         *control,
					       gboolean              state,
					       gpointer              user_data);
static void nautilus_sidebar_loser_fail       (void);
static void ensure_fail_env                   (void);

static void
nautilus_sidebar_loser_initialize_class (NautilusSidebarLoserClass *klass)
{
	GtkObjectClass *object_class;
	
	object_class = GTK_OBJECT_CLASS (klass);
	
	object_class->destroy = nautilus_sidebar_loser_destroy;
}

static void
nautilus_sidebar_loser_initialize (NautilusSidebarLoser *view)
{
	view->details = g_new0 (NautilusSidebarLoserDetails, 1);
	
	gtk_label_set_text (GTK_LABEL (view), g_strdup ("(none)"));
	
	view->details->nautilus_view = nautilus_view_new (GTK_WIDGET (view));
	
	gtk_signal_connect (GTK_OBJECT (view->details->nautilus_view), 
			    "load_location",
			    GTK_SIGNAL_FUNC (loser_load_location_callback), 
			    view);

	/* 
	 * Get notified when our bonobo control is activated so we
	 * can merge menu & toolbar items into Nautilus's UI.
	 */
        gtk_signal_connect (GTK_OBJECT (nautilus_view_get_bonobo_control
					(view->details->nautilus_view)),
                            "activate",
                            loser_merge_bonobo_items_callback,
                            view);
	
	gtk_widget_show (GTK_WIDGET (view));
}

static void
nautilus_sidebar_loser_destroy (GtkObject *object)
{
	NautilusSidebarLoser *view;
	
	view = NAUTILUS_SIDEBAR_LOSER (object);
	
	g_free (view->details->uri);
	g_free (view->details);
	
	NAUTILUS_CALL_PARENT_CLASS (GTK_OBJECT_CLASS, destroy, (object));
}

/**
 * nautilus_sidebar_loser_get_nautilus_view:
 *
 * Return the NautilusView object associated with this view; this
 * is needed to export the view via CORBA/Bonobo.
 * @view: NautilusSidebarLoser to get the nautilus_view from..
 * 
 **/
NautilusView *
nautilus_sidebar_loser_get_nautilus_view (NautilusSidebarLoser *view)
{
	return view->details->nautilus_view;
}

/**
 * nautilus_sidebar_loser_load_uri:
 *
 * Load the resource pointed to by the specified URI.
 * @view: NautilusSidebarLoser to get the nautilus_view from.
 * 
 **/
void
nautilus_sidebar_loser_load_uri (NautilusSidebarLoser *view,
				       const char               *uri)
{
	char *label_text;
	
	g_free (view->details->uri);
	view->details->uri = g_strdup (uri);

	label_text = g_strdup_printf (_("%s\n\nLoser sidebar."), uri);
	gtk_label_set_text (GTK_LABEL (view), label_text);
	g_free (label_text);
}

static void
loser_load_location_callback (NautilusView  *nautilus_view, 
			      const char *location,
			      NautilusSidebarLoser *view)
{
	g_assert (nautilus_view == view->details->nautilus_view);
	
	nautilus_sidebar_loser_maybe_fail ("pre-underway");
	
	/* It's mandatory to send an underway message once the
	 * component starts loading, otherwise nautilus will assume it
	 * failed. In a real component, this will probably happen in
	 * some sort of callback from whatever loading mechanism it is
	 * using to load the data; this component loads no data, so it
	 * gives the progress update here.
	 */
	nautilus_view_report_load_underway (nautilus_view);
	
	nautilus_sidebar_loser_maybe_fail ("pre-load");

	/* Do the actual load. */
	nautilus_sidebar_loser_load_uri (view, location);
	
	nautilus_sidebar_loser_maybe_fail ("pre-done");

	/* It's mandatory to call report_load_complete once the
	 * component is done loading successfully, or
	 * report_load_failed if it completes unsuccessfully. In a
	 * real component, this will probably happen in some sort of
	 * callback from whatever loading mechanism it is using to
	 * load the data; this component loads no data, so it gives
	 * the progress update here.
	 */
	nautilus_view_report_load_complete (nautilus_view);

	nautilus_sidebar_loser_maybe_fail ("post-done");
}

static void
bonobo_loser_callback (BonoboUIHandler *ui_handler, gpointer user_data, const char *path)
{
 	NautilusSidebarLoser *view;
	char *label_text;

        g_assert (NAUTILUS_IS_SIDEBAR_LOSER (user_data));

	view = NAUTILUS_SIDEBAR_LOSER (user_data);

	if (strcmp (path, "/File/Kill Sidebar View") == 0) {
		label_text = g_strdup_printf ("%s\n\nYou selected the Kill Sidebar View menu item.", view->details->uri);
		nautilus_sidebar_loser_fail ();

	} else {
		g_assert (strcmp (path, "/Main/Kill Sidebar View") == 0);
		label_text = g_strdup_printf (_("%s\n\nYou clicked the Kill Sidebar View toolbar button."), view->details->uri);

		nautilus_sidebar_loser_fail ();

	}
	
	gtk_label_set_text (GTK_LABEL (view), label_text);
	g_free (label_text);
}

static void
loser_merge_bonobo_items_callback (BonoboObject *control, gboolean state, gpointer user_data)
{
 	NautilusSidebarLoser *view;
	BonoboUIHandler *local_ui_handler;
	GdkPixbuf		*pixbuf;
	BonoboUIHandlerPixmapType pixmap_type;
	char *path;
	
	nautilus_sidebar_loser_maybe_fail ("pre-merge");

	g_assert (NAUTILUS_IS_SIDEBAR_LOSER (user_data));

	view = NAUTILUS_SIDEBAR_LOSER (user_data);
	local_ui_handler = bonobo_control_get_ui_handler (BONOBO_CONTROL (control));

	if (state) {
		/* Tell the Nautilus window to merge our bonobo_ui_handler items with its ones */
		bonobo_ui_handler_set_container (local_ui_handler, 
                                                 bonobo_control_get_remote_ui_handler (BONOBO_CONTROL (control)));

		/* Load test pixbuf */
		pixbuf = gdk_pixbuf_new_from_file ("/gnome/share/pixmaps/nautilus/i-directory-24.png");		
		if (pixbuf != NULL)
			pixmap_type = BONOBO_UI_HANDLER_PIXMAP_PIXBUF_DATA;
		else
			pixmap_type = BONOBO_UI_HANDLER_PIXMAP_NONE;

	       /* Create our loser menu item. */ 
		path = bonobo_ui_handler_build_path (NULL,
						     "File", 
						     "Kill Sidebar View",
						     NULL);
		bonobo_ui_handler_menu_new_item 
			(local_ui_handler,					/* BonoboUIHandler */
	        	 path,							/* menu item path, must start with /some-existing-menu-path and be otherwise unique */
	                 _("_Kill Sidebar View"),						/* menu item user-displayed label */
	                 _("Kill the Loser sidebar view"),		/* hint that appears in status bar */
	                 bonobo_ui_handler_menu_get_pos 
	                 	(local_ui_handler, 
	                         NAUTILUS_MENU_PATH_NEW_WINDOW_ITEM) + 1, 	/* position within menu; -1 means last */
	                 pixmap_type,						/* pixmap type */
	                 pixbuf,						/* pixmap data */
	                 'M',							/* accelerator key, couldn't bear the thought of using Control-S for anything except Save */
	                 GDK_CONTROL_MASK,					/* accelerator key modifiers */
	                 bonobo_loser_callback,				        /* callback function */
	                 view);                					/* callback function data */
		g_free (path);

                /* Create our loser toolbar button. */ 
                path = bonobo_ui_handler_build_path (NAUTILUS_TOOLBAR_PATH_MAIN_TOOLBAR, 
                				     "Kill Sidebar View",
                				     NULL);
	        bonobo_ui_handler_toolbar_new_item 
	        	(local_ui_handler,				/* BonoboUIHandler */
	        	 path,						/* button path, must start with /some-existing-toolbar-path and be otherwise unique */
	        	 _("Loser"),					/* button user-displayed label */
	        	 _("Kill the Loser sidebar view."),	        /* hint that appears in status bar */
	        	 -1,						/* position, -1 means last */
	        	 pixmap_type,					/* pixmap type */
	        	 pixbuf,					/* pixmap data */
	        	 0,						/* accelerator key */
	        	 0,						/* accelerator key modifiers */
	        	 bonobo_loser_callback,			        /* callback function */
	        	 view);						/* callback function's data */
	        g_free (path);
	} else {
		/* Do nothing. */
	}

	nautilus_sidebar_loser_maybe_fail ("post-merge");


        /* 
         * Note that we do nothing if state is FALSE. Nautilus sidebar views are activated
         * when installed, but never explicitly deactivated. When the view changes to another,
         * the sidebar view object is destroyed, which ends up calling bonobo_ui_handler_unset_container,
         * which removes its merged menu & toolbar items.
         */
}

static char *failure_mode = NULL;
static char *failure_point = NULL;
static gboolean env_checked = FALSE;

void
nautilus_sidebar_loser_maybe_fail (const char *location)
{
	ensure_fail_env ();
	
	if (strcasecmp (location, failure_point) == 0) {
		nautilus_sidebar_loser_fail ();
	}
}
				   


static void
nautilus_sidebar_loser_fail (void)
{
	ensure_fail_env ();
	
	if (strcasecmp (failure_mode, "hang") == 0) {
		while (1) {
		}
	} else if (strcasecmp (failure_mode, "exit") == 0) {
		exit (0);
	} else if (strcasecmp (failure_mode, "error-exit") == 0) {
		exit (-1);
	} else if (strcasecmp (failure_mode, "crash") == 0) {
		abort ();
	} else {
		puts ("XXX - would fail now, if NAUTILUS_SIDEBAR_LOSER_MODE were set properly.");
	}
}


static void
ensure_fail_env (void)
{
	if (!env_checked) {
		failure_mode = g_getenv ("NAUTILUS_SIDEBAR_LOSER_MODE");
		if (failure_mode == NULL) {
			failure_mode = "";
		}
		
		failure_point = g_getenv ("NAUTILUS_SIDEBAR_LOSER_PLACE");
		if (failure_point == NULL) {
			failure_point = "";
		}
		
		env_checked = TRUE;
	}
}
