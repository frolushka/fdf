/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_fill_dots.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 22:41:41 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/06 03:18:52 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int inline	fill_res(t_dots **res, int const i, int const j,
	char const *tmp)
{
	int	y;

	y = ft_atoi(tmp);
	(*res)->wb[i * (*res)->xc + j]->x = (*res)->xc / -2.0f + 0.5f + j;
	(*res)->wb[i * (*res)->xc + j]->z = (*res)->yc / -2.0f + 0.5f + i;
	(*res)->wb[i * (*res)->xc + j]->y = y;
	if (y > (*res)->zmax)
		(*res)->zmax = y;
	else if (y < (*res)->zmin)
		(*res)->zmin = y;
	(*res)->wb[i * (*res)->xc + j]->w = get_color(tmp);
	return (0);
}

static int inline	init_arrays(t_dots **res)
{
	if (!((*res)->wb = (t_vec4 **)malloc(
		sizeof(t_vec4 *) * (*res)->xc * (*res)->yc)))
		return (1);
	if (!((*res)->cb = (t_vec3 **)malloc(
		sizeof(t_vec3 *) * (*res)->xc * (*res)->yc)))
	{
		free((*res)->cb);
		return (1);
	}
	if (!((*res)->sb = (t_vec2 **)malloc(
		sizeof(t_vec2 *) * (*res)->xc * (*res)->yc)))
	{
		free((*res)->wb);
		free((*res)->cb);
		return (1);
	}
	return (0);
}

static int inline	init_vecs(t_dots **res, int const i, int const j)
{
	if (!((*res)->wb[i * (*res)->xc + j] = vec4_init()))
		return (1);
	if (!((*res)->cb[i * (*res)->xc + j] = vec3_init()))
	{
		free(((*res)->wb[i * (*res)->xc + j]));
		return (1);
	}
	if (!((*res)->sb[i * (*res)->xc + j] = vec2_init()))
	{
		free((*res)->wb[i * (*res)->xc + j]);
		free((*res)->cb[i * (*res)->xc + j]);
		return (1);
	}
	return (0);
}

int					fill_dots(char *fn, t_dots **res)
{
	char	*line;
	char	**tmp;
	int		i;
	int		j;
	int		fd;

	if (init_arrays(res) || (fd = open(fn, O_RDONLY)) < 0)
		return (0);
	i = -1;
	while (++i < (*res)->yc)
	{
		if (get_next_line(fd, &line) < 1)
			return (free_all(NULL, NULL, fd));
		if (!(tmp = ft_strsplit(line, ' ')))
			return (free_all(&line, NULL, fd));
		j = -1;
		while (++j < (*res)->xc)
			if (init_vecs(res, i, j))
				return (free_all(&line, NULL, fd));
			else
				fill_res(res, i, j, tmp[j]);
		free_all(&line, &tmp, -1);
	}
	close(fd);
	return (1);
}
