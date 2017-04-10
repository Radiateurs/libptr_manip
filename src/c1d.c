/*
** Created by Pierre-Marie danieau for libptr_manip
**
** Started the 10-04-2017
*/

#include	"c1d.h"

int		pm_c1d_contains(char *str, char c)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	return (1);
      i++;
    }
  return (0);
}
