/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */
/* 
 * Copyright (C) 2000 Eazel, Inc
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * Authors: Eskil Heyn Olsen <eskil@eazel.com>
 *
 */

/* trilobite-service.h: Interface for objects representing
   the toplevel type for services ("trilobites").
 */

#ifndef TRILOBITE_PASSWORDQUERY_H
#define TRILOBITE_PASSWORDQUERY_H

#include <libgnome/gnome-defs.h>
#include <bonobo/bonobo-object.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define TRILOBITE_TYPE_PASSWORDQUERY           (trilobite_passwordquery_get_type ())
#define TRILOBITE_PASSWORDQUERY(obj)           (GTK_CHECK_CAST ((obj), TRILOBITE_TYPE_PASSWORDQUERY, TrilobitePasswordQuery))
#define TRILOBITE_PASSWORDQUERY_CLASS(klass)   (GTK_CHECK_CLASS_CAST ((klass), TRILOBITE_TYPE_PASSWORDQUERY, TrilobitePasswordQueryClass))
#define TRILOBITE_IS_PASSWORDQUERY(obj)        (GTK_CHECK_TYPE ((obj), TRILOBITE_TYPE_PASSWORDQUERY))
#define TRILOBITE_IS_PASSWORDQUERY_CLASS(klass)(GTK_CHECK_CLASS_TYPE ((klass), TRILOBITE_TYPE_PASSWORDQUERY))
	
typedef struct _TrilobitePasswordQuery TrilobitePasswordQuery;
typedef struct _TrilobitePasswordQueryClass TrilobitePasswordQueryClass;

struct _TrilobitePasswordQueryClass 
{
	BonoboObjectClass parent_class;


	gpointer servant_init;
	gpointer servant_fini;
	gpointer servant_vepv;
};

typedef struct _TrilobitePasswordQueryPrivate TrilobitePasswordQueryPrivate;

struct _TrilobitePasswordQuery
{
	BonoboObject                 parent;
	TrilobitePasswordQueryPrivate     *private;
};

GtkType                       trilobite_passwordquery_get_type   (void);
gboolean                      trilobite_passwordquery_construct  (TrilobitePasswordQuery *trilobite, 
								  Trilobite_PasswordQuery corba_trilobite);
TrilobitePasswordQuery*             trilobite_passwordquery_new        (void);
POA_Trilobite_PasswordQuery__epv*   trilobite_passwordquery_get_epv    (void);
void                                trilobite_passwordquery_destroy    (GtkObject *object);

/* This should be called from the service factory.
   It adds the interface and sets the following data :
   "trilobite-root-helper" - a TrilobiteRootHelper object, do not destroy */
void trilobite_passwordquery_add_interface (TrilobitePasswordQuery *trilobite, 
					    BonoboObject *service);

/* Sets the prompt */
void trilobite_passwordquery_set_prompt (TrilobitePasswordQuery *trilobite, 
					 const char *prompt);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* TRILOBITE_PASSWORDQUERY_H */