/* saddr2str.c - SSAPaddr to string value */

#ifndef	lint
static char *rcsid = "$Header$";
#endif

/* 
 * $Header$
 *
 *
 * $Log$
 * Revision 1.1  1994/06/10 03:27:59  eichin
 * autoconfed isode for kerberos work
 *
 * Revision 1.1  94/06/10  03:16:29  eichin
 * autoconfed isode for kerberos work
 * 
 * Revision 1.1  1994/05/31 20:34:29  eichin
 * reduced-isode release from /mit/isode/isode-subset/src
 *
 * Revision 8.0  91/07/17  12:18:08  isode
 * Release 7.0
 * 
 * 
 */

/*
 *				  NOTICE
 *
 *    Acquisition, use, and distribution of this module and related
 *    materials are subject to the restrictions of a license agreement.
 *    Consult the Preface in the User's Manual for the full terms of
 *    this agreement.
 *
 */


/* LINTLIBRARY */

#include <stdio.h>
#include "general.h"
#include "manifest.h"
#include "isoaddrs.h"

/*  */

char   *saddr2str (sa)
register struct SSAPaddr *sa;
{
    struct PSAPaddr pas;
    register struct PSAPaddr *pa = &pas;

    if (!sa)
	return NULL;
    bzero ((char *) pa, sizeof *pa);
    pa -> pa_addr = *sa;		/* struct copy */

    return paddr2str (pa, NULLNA);
}
