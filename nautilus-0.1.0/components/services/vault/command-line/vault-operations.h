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
 * Authors: Ian McKellar <yakk@yakk.net.au>
 *
 */

#include <config.h>
#include <glib.h>
#include <libgnomevfs/gnome-vfs.h>

struct VaultOperation {
	gchar *name;
	gchar *syntax;
	gint minargs;
	gint maxargs;
	GnomeVFSResult (* function)(GList *args, gchar *uri, gboolean debug, gchar **error_context);
};

extern struct VaultOperation vault_operations[];