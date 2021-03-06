/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */
/* dfos.h - Desktop File Operation Service.

   Copyright (C) 1999, 2000 Free Software Foundation

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public
   License along with this program; see the file COPYING.  If not,
   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.

   Author: Ettore Perazzoli <ettore@gnu.org>
*/

#ifndef _DFOS_H
#define _DFOS_H

typedef struct _DFOS DFOS;

#include "dfos-corba.h"
#include "dfos-xfer-progress-dialog.h"
#include "dfos-xfer.h"

#include "GNOME_Desktop_FileOperationService.h"


DFOS 	*dfos_new 	(void);
void	 dfos_destroy   (DFOS *dfos);

#endif /* _DFOS_H */
