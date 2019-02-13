/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 22:35:18 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/22 22:42:03 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

// static int			free_all(char **line, char ***tmp, int fd)
// {
// 	if (line)
// 		ft_strdel(line);
// 	if (tmp)
// 		ft_strsdel(tmp);
// 	if (fd > 0)
// 		close(fd);
// 	return (0);
// }

// static int			get_color(char *it)
// {
// 	int	i;
// 	int	k;
// 	int	res;

// 	i = 0;
// 	res = 0;
// 	while (it[i] && (it[i] == '-' || ft_isdigit(it[i])))
// 		++i;
// 	if (it[i] == ',')
// 	{
// 		i += 3;
// 		k = -1;
// 		while (++k < 6)
// 		{
// 			res += it[i + k] > '9' ? it[i + k] - 'A' + 10 : it[i + k] - '0';
// 			res = res << 4;
// 		}
// 	}
// 	else
// 	{
// 		i = ft_atoi(it);
// 		(i < -60 ? res = 0x000000 : 0);
// 		(i >= -60 && i < -40 ? res = color_lerp(0x000000, 0x444444, (float)(60 + i) / 20) : 0);
// 		(i >= -40 && i < -20 ? res = color_lerp(0x444444, 0x2B1B02, (float)(40 + i) / 80) : 0);
// 		(i >= -20 && i < 0 ? res = color_lerp(0x2B1B02, 0x082D0F, (float)(20 + i) / 20) : 0);
// 		(i >= 0 && i < 40 ? res = color_lerp(0x082D0F, 0xFFFFFF, (float)i / 40) : 0);
// 		(i >= 40 ? res = 0xFFFFFF : 0);
// 	}
// 	return (res);
// }

// static int			check_line_valid(char **line)
// {
// 	int	i;
// 	int	j;
// 	int	k;

// 	i = -1;
// 	while (line[++i])
// 	{
// 		j = (line[i][0] == '-' ? 1 : 0);
// 		while (ft_isdigit(line[i][j]))
// 			++j;
// 		if (line[i][j] == ',')
// 		{
// 			++j;
// 			if ((line[i][j] && line[i][j] != '0') ||
// 				(line[i][j + 1] && line[i][j + 1] != 'X'))
// 				return (0);
// 			j += 2;
// 			k = -1;
// 			while (++k < 6)
// 			{
// 				if (!line[i][j + k] ||
// 					!((line[i][j + k] >= '0' && line[i][j + k] <= '9') ||
// 					(line[i][j + k] >= 'A' && line[i][j + k] <= 'F')))
// 					return (0);
// 			}
// 			if (line[i][j + k])
// 				return (0);
// 		}
// 		else if (line[i][j])
// 			return (0);
// 	}
// 	return (i);
// }

// static int			fill_dots(char *fn, t_dots **res)
// {
// 	char	*line;
// 	char	**tmp;
// 	int		i;
// 	int		j;
// 	int		fd;

// 	if (!((*res)->local = (t_vec4 **)malloc(sizeof(t_vec4 *) * (*res)->xc * (*res)->yc)) ||
// 		!((*res)->cam = (t_vec3 **)malloc(sizeof(t_vec3 *) * (*res)->xc * (*res)->yc)) ||
// 		!((*res)->screen = (t_vec2 **)malloc(sizeof(t_vec2 *) * (*res)->xc * (*res)->yc)) ||
// 		(fd = open(fn, O_RDONLY)) < 0)
// 		return (0);
// 	i = -1;
// 	while (++i < (*res)->yc)
// 	{
// 		if (get_next_line(fd, &line) < 1)
// 			return (free_all(NULL, NULL, fd));
// 		if (!(tmp = ft_strsplit(line, ' ')))
// 			return (&line, NULL, fd);
// 		j = -1;
// 		while (++j < (*res)->xc)
// 		{
// 			if (!((*res)->local[i * (*res)->xc + j] = vec4_init()) ||
// 				!((*res)->cam[i * (*res)->xc + j] = vec3_init()) ||
// 				!((*res)->screen[i * (*res)->xc + j] = vec2_init()))
// 			{
// 				(*res)->local[i * (*res)->xc + j] = NULL;
// 				ft_strdel(&line);
// 				close(fd);
// 				return (0);
// 			}
// 			(*res)->local[i * (*res)->xc + j]->x = j;
// 			(*res)->local[i * (*res)->xc + j]->y = i;
// 			(*res)->local[i * (*res)->xc + j]->z = ft_atoi(tmp[j]);
// 			(*res)->local[i * (*res)->xc + j]->w = get_color(tmp[j]);
// 		}
// 		ft_strdel(&line);
// 		line = NULL;
// 		ft_strsdel(&tmp);
// 	}
// 	close(fd);
// 	return (1);
// }

// static int			get_size(char *fn, t_vec2 **res)
// {
// 	char	*line;
// 	char	**tmp;
// 	int		sts;
// 	int		fd;

// 	if (!res || !(*res = vec2_new(-1, 0)) || (fd = open(fn, O_RDONLY)) < 0)
// 		return (0);
// 	while ((sts = get_next_line(fd, &line)) == 1)
// 	{
// 		if (!(tmp = ft_strsplit(line, ' ')))
// 		{
// 			ft_strdel(&line);
// 			close(fd);
// 			return (0);
// 		}
// 		sts = check_line_valid(tmp);
// 		(*res)->x < 0 ? (*res)->x = sts : 0;
// 		if (sts == 0 || sts != (*res)->x)
// 		{
// 			ft_strdel(&line);
// 			ft_strsdel(&tmp);
// 			close(fd);
// 			return (0);
// 		}
// 		++(*res)->y;
// 		ft_strdel(&line);
// 		ft_strsdel(&tmp);
// 	}
// 	if (sts == -1)
// 	{
// 		free(*res);
// 		close(fd);
// 		return (0);
// 	}
// 	close(fd);
// 	return (1);
// }

// int			read_dots(char *fn, t_dots **res)
// {
// 	t_vec2	*size;

// 	*res = NULL;
// 	if (!res || !fn || !get_size(fn, &size))
// 		return (0);
// 	if (!(*res = t_dots_init(size->x, size->y)))
// 	{
// 		free(size);
// 		return (0);
// 	}
// 	free(size);
// 	if (!(fill_dots(fn, res)))
// 	{
// 		t_dots_del(res);
// 		return (0);
// 	}
// 	return (1);
// }

// int			print_dots(t_dots *res)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (++i < res->yc)
// 	{
// 		j = -1;
// 		while (++j < res->xc)
// 		{
// 			printf("(%.3f,%.3f,%.3f,%.3f)\t", res->local[i * res->xc + j]->x, res->local[i * res->xc + j]->y, res->local[i * res->xc + j]->z, res->local[i * res->xc + j]->w);
// 		}
// 		printf("\n");
// 	}
// 	return (0);
// }
