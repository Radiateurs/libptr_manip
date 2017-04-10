/*
** Created by Pierre-Marie danieau for libptr_manip
**
** Started the 07-04-2017
*/

#include	"c2d.h"

c2d		pm_c2d_creat(char *str)
{
  c2d		dest;

  if (!(dest = malloc(sizeof(*dest) * 2)))
    return (NULL);
  dest[0] = strdup(str);
  dest[1] = NULL;
  return (dest);
}

int		pm_c2d_length(c2d origin)
{
  int		i = 0;

  if (origin == NULL)
    return (0);
  while (origin[i] != NULL)
    i++;
  return (i);
}

c2d		pm_c2d_copy(c2d origin)
{
  c2d		dest;
  int		i = 0;
  int		length;

  if (origin == NULL)
    return (NULL);
  length = pm_c2d_length(origin);
  if (!(dest = malloc(sizeof(*dest) * length + 1)))
    return (NULL);
  while (i < length)
    {
      dest[i] = strdup(origin[i]);
      i++;
    }
  dest[i] = NULL;
  return (dest);
}

c2d		pm_c2d_copy_add_fields_top(c2d origin, int fields)
{
  c2d		dest;
  int		i = 0;
  int		length;

  if (origin == NULL)
    return (NULL);
  length = pm_c2d_length(origin);
  if (!(dest = malloc(sizeof(*dest) * (length + 1 + fields))))
    return (NULL);
  while (i < length)
    {
      dest[i + fields] = strdup(origin[i]);
      i++;
    }
  dest[i + fields] = NULL;
  fields--;
  while (fields >= 0)
    {
      dest[fields] = NULL;
      fields--;
    }
  return (dest);
}

c2d		pm_c2d_copy_add_fields_down(c2d origin, int fields)
{
  c2d		dest;
  int		i = 0;
  int		length;
  
  if (origin == NULL)
    return (NULL);
  length = pm_c2d_length(origin);
  if (!(dest = malloc(sizeof(*dest) * (length + 1 + fields))))
    return (NULL);
  while (i < length)
    {
      dest[i] = strdup(origin[i]);
      i++;
    }
  while (i < length + fields + 1)
    {
      dest[i] = NULL;
      i++;
    }
  return (dest);
}

c2d		pm_c2d_add_field_top(c2d origin)
{
  c2d		dest;

  if (origin == NULL)
    return (NULL);
  if (!(dest = pm_c2d_copy_add_fields_top(origin, 1)))
    return (origin);
  pm_c2d_free(origin);
  return (dest);
}

c2d		pm_c2d_add_fields_top(c2d origin, int nb)
{
  c2d		dest;

  if (origin == NULL)
    return (NULL);
  if (!(dest = pm_c2d_copy_add_fields_top(origin, nb)))
    return (origin);
  pm_c2d_free(origin);
  return (dest);
}

c2d		pm_c2d_add_field_down(c2d origin)
{
  c2d		dest;

  if (origin == NULL)
    return (NULL);
  if (!(dest = pm_c2d_copy_add_fields_down(origin, 1)))
    return (origin);
  pm_c2d_free(origin);
  return (dest);
}

c2d		pm_c2d_add_fields_down(c2d origin, int nb)
{
  c2d		dest;

  if (origin == NULL)
    return (NULL);
  if (!(dest = pm_c2d_copy_add_fields_down(origin, nb)))
    return (NULL);
  pm_c2d_free(origin);
  return (dest);
}

c2d		pm_c2d_add_str_down(c2d origin, char *str)
{
  c2d		dest;
  int		pos;

  if (!str)
    return (NULL);
  if (!origin)
    return (pm_c2d_creat(str));
  pos = pm_c2d_length(origin);
  if (!(origin = pm_c2d_add_field_down(origin)))
    return (NULL);
  origin[pos] = strdup(str);
  return (origin);
}

c2d		pm_c2d_add_str_top(c2d origin, char *str)
{
  c2d		dest;
  int		pos;

  if (!str)
    return (NULL);
  if (!origin)
    return (pm_c2d_creat(str));
  pos = pm_c2d_length(origin);
  if (!(origin = pm_c2d_add_field_top(origin)))
    return (NULL);
  origin[0] = strdup(str);
  return (origin);
}

c2d		pm_c2d_append(c2d origin, c2d to_add)
{
  int		o_len, a_len;
  int		i = 0;

  if (!to_add)
    return (NULL);
  if (!origin && to_add)
    {
      if (!(origin = pm_c2d_copy(to_add)))
	return (NULL);
      return (origin);
    }
  o_len = pm_c2d_length(origin);
  a_len = pm_c2d_length(origin);
  if (!(origin = pm_c2d_add_fields_down(origin, a_len)))
    return (NULL);
  while (i < a_len)
    {
      origin[i + o_len] = strdup(to_add[i]);
      i++;
    }
  return (origin);
}

c2d		pm_c2d_copy_remove_fields_down(c2d origin, int fields)
{
  int		i = 0;
  c2d		dest;
  int		len;

  if (!origin)
    return (NULL);
  len = pm_c2d_length(origin);
  if (!(dest = malloc(sizeof(*dest) * len - fields + 1)))
    return (NULL);
  while (i < len - fields)
    {
      dest[i] = strdup(origin[i]);
      i++;
    }
  dest[i] = NULL;
  return (dest);
}

c2d		pm_c2d_copy_remove_fields_top(c2d origin, int fields)
{
  int		i = 0;
  c2d		dest;
  int		len;

  if (!origin)
    return (NULL);
  len = pm_c2d_length(origin);
  if (!(dest = malloc(sizeof(*dest) * len - fields  + 1)))
    return (NULL);
  while (i < len - fields)
    {
      dest[i] = strdup(origin[i + fields]);
      i++;
    }
  dest[i] = NULL;
  return (dest);
}

c2d		pm_c2d_remove_field_down(c2d origin)
{
  c2d		dest;

  if (!(dest = pm_c2d_copy_remove_fields_down(origin, 1)))
    return (NULL);
  pm_c2d_free(origin);
  return (dest);
}

c2d		pm_c2d_remove_field_top(c2d origin)
{
  c2d		dest;

  if (!(dest = pm_c2d_copy_remove_fields_top(origin, 1)))
    return (NULL);
  pm_c2d_free(origin);
  return (dest);
}

void		pm_c2d_free(c2d origin)
{
  int		len, i = 0;

  if (!origin)
    return ;
  len = pm_c2d_length(origin);
  while (i < len)
    {
      free(origin[i]);
      i++;
    }
  free(origin);
}

void		pm_c2d_dump(c2d origin)
{
  int		i, len;

  if (!origin)
    return ;
  i = 0;
  len = pm_c2d_length(origin);
  while (i < len)
    {
      puts(origin[i]);
      i++;
    }
}
