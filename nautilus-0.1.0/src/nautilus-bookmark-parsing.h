/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */

/* nautilus-bookmark-parsing.h - routines to parse bookmarks from XML data.

   Copyright (C) 2000 Eazel, Inc.

   The Gnome Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The Gnome Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the Gnome Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.

   Authors: John Sullivan <sullivan@eazel.com>
*/

#ifndef NAUTILUS_BOOKMARK_PARSING_H
#define NAUTILUS_BOOKMARK_PARSING_H

#include <libnautilus-extensions/nautilus-bookmark.h>
#include <tree.h>

NautilusBookmark *      nautilus_bookmark_new_from_node (xmlNodePtr node);

#endif /* NAUTILUS_BOOKMARK_PARSING_H */
