/***************************************************************************/
/*                                                                         */
/*  t1driver.h                                                             */
/*                                                                         */
/*    High-level Type 1 driver interface (specification).                  */
/*                                                                         */
/*  Copyright 1996-2000 by                                                 */
/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
/*                                                                         */
/*  This file is part of the FreeType project, and may only be used,       */
/*  modified, and distributed under the terms of the FreeType project      */
/*  license, LICENSE.TXT.  By continuing to use, modify, or distribute     */
/*  this file you indicate that you have read the license and              */
/*  understand and accept it fully.                                        */
/*                                                                         */
/***************************************************************************/


#ifndef T1DRIVER_H
#define T1DRIVER_H

#ifdef FT_FLAT_COMPILE

#include "ftdriver.h"

#else

#include <freetype/internal/ftdriver.h>

#endif

  FT_EXPORT_VAR( const  FT_Driver_Class )  t1_driver_class;


#endif /* T1DRIVER_H */


/* END */
