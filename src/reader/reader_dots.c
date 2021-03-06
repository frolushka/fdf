/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_dots.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 22:38:40 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/13 17:56:15 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	read_dots(char *fn, t_dots **res)
{
	size_t	len;
	t_vec2	*size;

	*res = NULL;
	if (!res || !fn)
		return (0);
	len = ft_strlen(fn);
	if (ft_strcmp(fn + len - 4, ".fdf") || !get_size(fn, &size))
		return (0);
	if (size->x == -1 || !(*res = dots_init(size->x, size->y)))
	{
		free(size);
		return (0);
	}
	free(size);
	if (!(fill_dots(fn, res)))
		return (0);
	return (1);
}
