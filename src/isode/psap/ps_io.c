/* ps_io.c - presentation stream I/O dispatch */

#ifndef	lint
static char *rcsid = "$Header$";
#endif

/* 
 * $Header$
 *
 *
 * $Log$
 * Revision 1.1  1994/06/10 03:34:12  eichin
 * autoconfed isode for kerberos work
 *
 * Revision 1.1  1994/06/01 00:38:19  eichin
 * add psap too
 *
 * Revision 8.0  91/07/17  12:47:10  isode
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
#include "psap.h"

/*  */

int	ps_io (ps, io, data, n, in_line)
register PS	ps;
register IFP	io;
register PElementData data;
register PElementLen n;
int	in_line;
{
    register int    cc;

    if (io == NULLIFP)
	return ps_seterr (ps, PS_ERR_EOF, NOTOK);

    while (n > 0)
	switch (cc = (*io) (ps, data, n, in_line)) {
	    case NOTOK: 
		return NOTOK;

	    case OK: 
		return ps_seterr (ps, PS_ERR_EOF, NOTOK);

	    default: 
		data += cc, n -= cc;
		ps -> ps_byteno += cc;
		break;
	}

    return OK;
}
