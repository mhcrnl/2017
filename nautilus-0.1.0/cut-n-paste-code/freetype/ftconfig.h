/***************************************************************************/
/*                                                                         */
/*  ftconfig.h                                                             */
/*                                                                         */
/*    ANSI-specific configuration file (specification only).               */
/*                                                                         */
/*  Copyright 1996-2000 by                                                 */
/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
/*                                                                         */
/*  This file is part of the FreeType project, and may only be used        */
/*  modified and distributed under the terms of the FreeType project       */
/*  license, LICENSE.TXT.  By continuing to use, modify, or distribute     */
/*  this file you indicate that you have read the license and              */
/*  understand and accept it fully.                                        */
/*                                                                         */
/***************************************************************************/


  /*************************************************************************/
  /*                                                                       */
  /* This header file contains a number of macro definitions that are used */
  /* by the rest of the engine. Most of the macros here are automatically  */
  /* determined at compile time, and you should not need to change it to   */
  /* port FreeType, except to compile the library with a non ANSI compiler */
  /*                                                                       */
  /* Note however that if some specific modifications are needed, we       */
  /* advise you to place a modified copy in your build directory.          */
  /*                                                                       */
  /* The build directory is usually "freetype/config/<system>", and        */
  /* contains system-specific files that are always included first when    */
  /* building the library..                                                */
  /*                                                                       */
  /* This ANSI version should stay in "freetype/config"                    */
  /*                                                                       */
  /*************************************************************************/

#ifndef FTCONFIG_H
#define FTCONFIG_H

/* Ok, basically it's a pain in the ass to try to get automake to work
   with files in more than one directory. Thus, I've bludgeoned the build
   setup to just put all the .c files in one dir, and similarly install
   all the .h files into one dir.

   FT_FLAT_COMPILE is defined in the actual freetype2 build, but has
   to be explicitly set somewhere so that clients can safely include
   freetype.h and expect to get the other dependent .h files. This is
   that place.

*/
#undef FT_FLAT_COMPILE /* avoid "redefinition of FT_FLAT_COMPILE" warnings */
#define FT_FLAT_COMPILE

/* Include the header file containing all developer build options */
#ifdef FT_FLAT_COMPILE

#include "ftoption.h"

#else

#include <freetype/config/ftoption.h>

#endif

  /*************************************************************************/
  /*                                                                       */
  /*               PLATFORM-SPECIFIC CONFIGURATION MACROS                  */
  /*                                                                       */
  /* These macros can be toggled to suit a specific system.  The current   */
  /* ones are defaults used to compile FreeType in an ANSI C environment   */
  /* (16bit compilers are also supported).  Copy this file to your own     */
  /* `freetype/arch/<system>'  directory, and edit it to port the engine.  */
  /*                                                                       */
  /*************************************************************************/


/* Define to empty if the keyword does not work.  */
/* #undef const */

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* We use <limits.h> values to know the sizes of the types.  */
#include <limits.h>

/* The number of bytes in an `int' type.  */
#if   UINT_MAX == 0xFFFFFFFF
#define FT_SIZEOF_INT  4
#elif UINT_MAX == 0xFFFF
#define FT_SIZEOF_INT  2
#elif UINT_MAX > 0xFFFFFFFF && UINT_MAX == 0xFFFFFFFFFFFFFFFF
#define FT_SIZEOF_INT  8
#else
#error "Unsupported number of bytes in `int' type!"
#endif

/* The number of bytes in a `long' type.  */
#if   ULONG_MAX == 0xFFFFFFFF
#define FT_SIZEOF_LONG  4
#elif ULONG_MAX > 0xFFFFFFFF && ULONG_MAX == 0xFFFFFFFFFFFFFFFF
#define FT_SIZEOF_LONG  8
#else
#error "Unsupported number of bytes in `long' type!"
#endif



/* Preferred alignment of data */
#define FT_ALIGNMENT  8


/* UNUSED is a macro used to indicate that a given parameter is not used */
/* this is only used to get rid of unpleasant compiler warnings..        */
#ifndef FT_UNUSED
#define FT_UNUSED( arg )  ( (arg)=(arg) )
#endif



  /*************************************************************************/
  /*                                                                       */
  /*                     AUTOMATIC CONFIGURATION MACROS                    */
  /*                                                                       */
  /*  These macros are computed from the ones defined above.  Don't touch  */
  /*  their definition, unless you know precisely what you're doing.  No   */
  /*  porter should need to mess with them.                                */
  /*                                                                       */
  /*************************************************************************/


  /*************************************************************************/
  /*                                                                       */
  /* IntN types                                                            */
  /*                                                                       */
  /*   Used to guarantee the size of some specific integers.               */
  /*                                                                       */
  typedef signed short    FT_Int16;
  typedef unsigned short  FT_UInt16;

#if FT_SIZEOF_INT == 4

  typedef signed int      FT_Int32;
  typedef unsigned int    FT_UInt32;

#elif FT_SIZEOF_LONG == 4

  typedef signed long     FT_Int32;
  typedef unsigned long   FT_UInt32;

#else
#error "no 32bit type found - please check your configuration files"
#endif

#if FT_SIZEOF_LONG == 8

  /* FT_LONG64 must be defined when a 64-bit type is available */
#define FT_LONG64
#define FT_INT64   long

#else


  /*************************************************************************/
  /*                                                                       */
  /* many compilers provide the non-ANSI 'long long' 64-bit type.  You can */
  /* activate it by defining the FTCALC_USE_LONG_LONG macro in `ftoption.h'*/
  /* Note that this will produce many -ansi warnings during library        */
  /* compilation, and that in many cases, the generated code will not be   */
  /* smaller or faster !!                                                  */
  /*                                                                       */
#ifdef FTCALC_USE_LONG_LONG

#ifndef FT_LONG64
#define FT_LONG64
#define FT_INT64   long long
#endif

#endif /* FTCALC_USE_LONG_LONG */
#endif


#ifdef FT_MAKE_OPTION_SINGLE_OBJECT
#define  LOCAL_DEF   static
#define  LOCAL_FUNC  static
#else
#define  LOCAL_DEF   extern
#define  LOCAL_FUNC  /* nothing */
#endif

#ifdef FT_MAKE_OPTION_SINGLE_LIBRARY_OBJECT
#define  BASE_DEF(x)    static  x
#define  BASE_FUNC(x)   static  x
#else
#define  BASE_DEF(x)    extern  x
#define  BASE_FUNC(x)   extern  x
#endif

#ifndef  FT_EXPORT_DEF
#define  FT_EXPORT_DEF(x)   extern  x
#endif

#ifndef  FT_EXPORT_FUNC
#define  FT_EXPORT_FUNC(x)  extern  x
#endif

#ifndef  FT_EXPORT_VAR
#define  FT_EXPORT_VAR(x)   extern  x
#endif

#endif /* FTCONFIG_H */


/* END */
