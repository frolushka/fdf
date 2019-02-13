/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots_connect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 03:23:03 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/14 00:34:43 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dots_connect(t_dots *d, const t_mlx *c)
{
	int	i;
	int	j;
	int	xc;
	int	yc;

	xc = d->xc;
	yc = d->yc;
	i = -1;
	while (++i < yc)
	{
		j = -1;
		while (++j < xc)
		{
			if (j != xc - 1)
				oclusion_draw_line(c, d, i * xc + j, i * xc + j + 1);
			if (i != yc - 1)
				oclusion_draw_line(c, d, i * xc + j, (i + 1) * xc + j);
		}
	}
}
