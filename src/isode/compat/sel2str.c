/* sel2str.c - selector to string */

#ifndef	lint
static char *rcsid = "$Header$";
#endif

/* 
 * $Header$
 *
 *
 * $Log$
 * Revision 1.1  1994/06/10 03:28:02  eichin
 * autoconfed isode for kerberos work
 *
 * Revision 1.1  94/06/10  03:16:31  eichin
 * autoconfed isode for kerberos work
 * 
 * Revision 1.1  1994/05/31 20:34:31  eichin
 * reduced-isode release from /mit/isode/isode-subset/src
 *
 * Revision 8.0  91/07/17  12:18:09  isode
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

#include <ctype.h>
#include <stdio.h>
#include "general.h"
#include "manifest.h"
#include "isoaddrs.h"

/*  */

char   *sel2str (sel, len, quoted)
char   *sel;
int	len,
	quoted;
{
    register char *cp,
		  *dp,
    		  *ep;
    static int    i = 0;
    static char buf1[NASIZE * 2 + 1],
		buf2[NASIZE * 2 + 1],
    		buf3[NASIZE * 2 + 1],
    		buf4[NASIZE * 2 + 1];
    static char *bufs[] = { buf1, buf2, buf3, buf4 };

    cp = bufs[i++];
    i = i % 4;

    if (quoted) {
#ifndef	NOGOSIP
	if (len == 2) {
	    if (quoted < 0)
		goto ugly;
	    (void) sprintf (cp, "#%d",
			    (sel[0] & 0xff) << 8 | (sel[1] & 0xff));
	    goto out;
	}
#endif

	for (ep = (dp = sel) + len; dp < ep; dp++)
	    if (!isprint ((u_char) *dp))
		goto ugly;

	if (len > NASIZE * 2)
	    len = NASIZE * 2;

	(void) sprintf (cp, len ? "\"%*.*s\"" : "\"\"", len, len, sel);
    }
    else {
ugly: ;
	if (len > NASIZE)	/* XXX */
	    len = NASIZE;

	cp[explode (cp, (u_char *) sel, len)] = NULL;
    }
#ifndef	NOGOSIP
out: ;
#endif
	
    return cp;
}
