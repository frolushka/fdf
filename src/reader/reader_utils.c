/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 22:39:31 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/14 20:59:11 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			memset_free(void **ptr, int size)
{
	char	**cptr;
	int		i;

	cptr = (char **)ptr;
	i = -1;
	while (++i < size)
	{
		if (!cptr[i])
			return (0);
		ft_memdel((void **)&(cptr[i]));
	}
	return (1);
}

t_dots		*dots_free(t_dots **dots)
{
	if (*((*dots)->wb))
		memset_free((void **)((*dots)->wb),
		(*dots)->xc * (*dots)->yc * sizeof(t_vec4 *));
	if (*((*dots)->cb))
		memset_free((void **)((*dots)->cb),
		(*dots)->xc * (*dots)->yc * sizeof(t_vec3 *));
	if (*((*dots)->sb))
		memset_free((void **)((*dots)->sb),
		(*dots)->xc * (*dots)->yc * sizeof(t_vec2 *));
	if ((*dots)->wb)
		ft_memdel((void **)(*dots)->wb);
	if ((*dots)->cb)
		ft_memdel((void **)(*dots)->cb);
	if ((*dots)->sb)
		ft_memdel((void **)(*dots)->sb);
	ft_memdel((void **)dots);
	return (*dots);
}

int			get_color(const char *it, const int cm)
{
	int	i;
	int	k;
	int	res;

	i = 0;
	res = 0;
	while (it[i] && (it[i] == '-' || ft_isdigit(it[i])))
		++i;
	if (it[i] == ',')
	{
		i += 3;
		k = -1;
		while (++k < 6)
		{
			if (it[i + k] >= 'A' && it[i + k] <= 'F')
				res += it[i + k] - 'A' + 10;
			else
				res += ((it[i + k] >= 'a' && it[i + k] <= 'f') ?
					it[i + k] - 'a' + 10 : it[i + k] - '0');
			res = res << 4;
		}
	}
	else
		res = color_get_default(ft_atoi(it), cm);
	return (res);
}

int			free_all(char **line, char ***tmp, int fd)
{
	if (line)
		ft_strdel(line);
	if (tmp)
		ft_strsdel(tmp);
	if (fd > 0)
		close(fd);
	return (0);
}
