/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_get_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 22:42:08 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/14 20:55:34 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int inline	helper(int fd)
{
	close(fd);
	return (0);
}

int					get_size(char *fn, t_vec2 **res)
{
	char	*line;
	char	**tmp;
	int		sts;
	int		fd;

	if (!res || !(*res = vec2_new(-1, 0)) ||
		(fd = open(fn, O_RDONLY)) < 0)
		return (0);
	while ((sts = get_next_line(fd, &line)) == 1)
	{
		if (!(tmp = ft_strsplit(line, ' ')))
			return (free_all(&line, NULL, fd));
		sts = check_line_valid(tmp);
		(*res)->x < 0 ? (*res)->x = sts : 0;
		if (sts == 0 || sts != (*res)->x)
			return (free_all(&line, &tmp, fd));
		++(*res)->y;
		free_all(&line, &tmp, -1);
	}
	if (sts == -1)
		return (helper(fd));
	close(fd);
	return (1);
}
