/*
** Created by Pierre-Marie danieau for libptr_manip
**
** Started the 10-04-2017
*/

#include	"c1d.h"

int		pm_c1d_contains(c1d str, char c)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	return (i);
      i++;
    }
  return (-1);
}

c1d		pm_c1d_copy(const c1d copy)
{
  if (copy == NULL)
    return (NULL);
  return (strdup(copy));
}

c1d		pm_c1d_add_fields(c1d dest, int fields)
{
  int		i;
  c1d		ret;

  if (dest == NULL)
    return (malloc(sizeof(*ret) * (fields + 1)));
  if (!(ret = malloc(sizeof(*ret) * (strlen(dest) + fields + 1))))
    return (NULL);
  i = 0;
  while (dest[i] != '\0')
    {
      ret[i] = dest[i];
      i++;
    }
  ret[i] = '\0';
  free(dest);
  return (ret);
}

c1d		pm_c1d_concat_nproof(c1d dest, const c1d src)
{
  int		i;

  if (dest == NULL)
    return (pm_c1d_copy(src));
  if (!(dest = pm_c1d_add_fields(dest, strlen(src))))
    return (NULL);
  if (!(dest = strcat(dest, src)))
    return (NULL);
  return (dest);
}

c1d		pm_c1d_substr(c1d src, const char delim)
{
  return (strndup(src, pm_c1d_contains(src, delim)));
}
