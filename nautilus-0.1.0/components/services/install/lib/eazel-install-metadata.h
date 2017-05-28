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
 * Authors: J Shane Culpepper <pepper@eazel.com>
 */

/* eazel-install - services command line install/update/uninstall
 * component.  This program will parse the eazel-services-config.xml
 * file and install a services generated package-list.xml.
 */

#ifndef EAZEL_INSTALL_METADATA_H
#define EAZEL_INSTALL_METADATA_H

#include "eazel-install-types.h"
#include <libtrilobite/helixcode-utils.h>
#include <errno.h>
#include <sys/stat.h>
#include <gnome-xml/tree.h>
#include <gnome-xml/parser.h>

InstallOptions* init_default_install_configuration (const char* config_file);
TransferOptions* init_default_transfer_configuration (const char* config_file);

#endif /* EAZEL_INSTALL_METADATA_H */