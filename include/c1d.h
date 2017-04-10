/*
** Created by Pierre-Marie Danieau for libptr_manip
**
** This header prototypes the functions present in c1d.c
**
** Started the 10-04-2017
*/

#ifndef		__C1D_H__
# define	__C1D_H__

# include	<stdlib.h>
# include	<string.h>

typedef		char* c1d;

int		pm_c1d_contains(c1d str, char c);
c1d		pm_c1d_copy(const c1d copy);
c1d		pm_c1d_add_fields(c1d dest, int fields);
c1d		pm_c1d_concat_nproof(c1d dest; const src src);

#endif		/* __C1D_H__ */
