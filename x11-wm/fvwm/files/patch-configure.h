*** configure.h.orig	Mon Nov 28 15:08:47 1994
--- configure.h	Sun May 30 11:01:24 1999
***************
*** 1,7 ****
! #define FVWMDIR     "/usr/lib/X11/fvwm"
  /* #define FVWMDIR        "/local/homes/dsp/nation/modules"*/
! #define FVWM_ICONDIR   "/usr/include/X11/bitmaps:/usr/include/X11/pixmaps"
! #define FVWMRC         "/usr/lib/X11/fvwm/system.fvwmrc"
  
  /* Imake command needed to put modules in desired target location */
  /* Use the second version if it causes grief */
--- 1,7 ----
! #define FVWMDIR     "%%PREFIX%%/lib/X11/fvwm"
  /* #define FVWMDIR        "/local/homes/dsp/nation/modules"*/
! #define FVWM_ICONDIR   "%%PREFIX%%/include/X11/bitmaps:%%PREFIX%%/include/X11/pixmaps"
! #define FVWMRC         "%%PREFIX%%/lib/X11/fvwm/system.fvwmrc"
  
  /* Imake command needed to put modules in desired target location */
  /* Use the second version if it causes grief */
***************
*** 14,26 ****
   * If you want to install it in a different directory, uncomment and
   * edit the first line */
  /* #define FVWM_BIN_DIR BINDIR=/local/homes/dsp/nation/bin/4.1.3*/
! #define FVWM_BIN_DIR BINDIR=/usr/bin/X11
  /*#define FVWM_BIN_DIR*/
  
  /* Compiler over-ride for Imakefiles */
  /* Leave it as shown to get your default compiler */
! #define COMPILER CC=gcc 
! /* #define COMPILER */
  
  
  /***************************************************************************
--- 14,26 ----
   * If you want to install it in a different directory, uncomment and
   * edit the first line */
  /* #define FVWM_BIN_DIR BINDIR=/local/homes/dsp/nation/bin/4.1.3*/
! #define FVWM_BIN_DIR BINDIR=%%PREFIX%%/bin
  /*#define FVWM_BIN_DIR*/
  
  /* Compiler over-ride for Imakefiles */
  /* Leave it as shown to get your default compiler */
! /* #define COMPILER CC=gcc */
! #define COMPILER
  
  
  /***************************************************************************
***************
*** 69,82 ****
   *            undefine(`include') tofix that one. Some version of m4
   *            seem to give good error messages, others don't?
   ***************************************************************************/
! /* #define M4                          */
  
  /***************************************************************************
   *#define NO_PAGER 
   *   Omits the code for the built-in pager. The pager module FvwmPager
   *   can be used instead.
   ***************************************************************************/
! /* #define NO_PAGER                    */
  
  /***************************************************************************
   *#define NON_VIRTUAL
--- 69,82 ----
   *            undefine(`include') to fix that one. Some version of m4
   *            seem to give good error messages, others don't?
   ***************************************************************************/
! #define M4
  
  /***************************************************************************
   *#define NO_PAGER 
   *   Omits the code for the built-in pager. The pager module FvwmPager
   *   can be used instead.
   ***************************************************************************/
! #define NO_PAGER
  
  /***************************************************************************
   *#define NON_VIRTUAL
***************
*** 100,106 ****
   *   Caused fvwm built-in window-list to be omitted. The window-list
   *   module FvwmWinList can be used instead 
   ***************************************************************************/
! /* #define NO_WINDOWLIST               */
  
  /***************************************************************************
   *#define PRUNE
--- 100,106 ----
   *   Caused fvwm built-in window-list to be omitted. The window-list
   *   module FvwmWinList can be used instead 
   ***************************************************************************/
! #define NO_WINDOWLIST
  
  /***************************************************************************
   *#define PRUNE
***************
*** 186,192 ****
  #define CLOSE_STRING3   "destroy"
  #define CLOSE_STRING4   "quit"
  
! #ifdef __alpha
  #define NEEDS_ALPHA_HEADER
  #undef BROKEN_SUN_HEADERS
  #endif /* (__alpha) */
--- 186,192 ----
  #define CLOSE_STRING3   "destroy"
  #define CLOSE_STRING4   "quit"
  
! #if defined(__alpha) && !defined(__FreeBSD__)
  #define NEEDS_ALPHA_HEADER
  #undef BROKEN_SUN_HEADERS
  #endif /* (__alpha) */
