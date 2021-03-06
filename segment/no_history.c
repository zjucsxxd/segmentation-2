/*
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that: (1) source distributions retain this entire copyright
 * notice and comment, and (2) distributions including binaries display
 * the following acknowledgement:  ``This product includes software
 * developed by the Computer Systems Laboratory, University of
 * California, Santa Barbara and its contributors'' in the documentation
 * or other materials provided with the distribution and in all
 * advertising materials mentioning features or use of this software.
 *
 * Neither the name of the University nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

/* LINTLIBRARY */

#include "ipw.h"

#include "bih.h"

#include "_nohist.h"

/* 
** NAME
**         no_history -- turn off history mechanism in bihwrite
**  
** 
** SYNOPSIS
**         void no_history(fd)
**         int fd;
**  
** 
** DESCRIPTION
**         no_history prevents the inclusion of a history record for
**         the current program in any basic image header subsequently
**         written to file descriptor {fd}.
**  
** 
** GLOBALS ACCESSED
**         _no_hist[fd]    flag associated with file descriptor {fd}
**  
** 
** APPLICATION USAGE
**         no_history may be called by programs that would otherwise
**         produce redundant history records (e.g., mux).
**  
** 
** SEE ALSO
**         IPW: xxhwrite
**  
** 
** NOTES
**         no_history must be called BEFORE bihwrite, or else it will
**         have no effect.
*/  

void
no_history(fd)
	int             fd;		/* image file descriptor	 */
{
	assert(OK_FD(fd));
	_no_hist[fd] = 1;
}

#ifndef	lint
static char     rcsid[] = "$Header: /share1/ipw-1.1/ipw-1.1/src/lib/libipw/bih/RCS/no_history.c,v 1.4 1997/02/17 04:19:00 ceretha Exp $";

#endif
