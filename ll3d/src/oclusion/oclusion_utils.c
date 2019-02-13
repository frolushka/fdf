/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oclusion_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 00:32:40 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/14 00:38:11 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

int	check_out(const t_dots *d, const int d1, const int d2)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = d->sb[d1]->x;
	x2 = d->sb[d2]->x;
	y1 = d->sb[d1]->y;
	y2 = d->sb[d2]->y;
	if ((x1 < (-SCREEN_X / 2) && x2 < (-SCREEN_X / 2))
		|| (x1 > (SCREEN_X / 2) && x2 > (SCREEN_X / 2))
		|| (y1 < (-SCREEN_Y / 2) && y2 < (-SCREEN_Y / 2))
		|| (y1 > (SCREEN_Y / 2) && y2 > (SCREEN_Y / 2))
		|| (d->cb[d1]->z < 0 && d->cb[d2]->z < 0))
		return (1);
	return (0);
}

int	swap_if_d2_less(t_vec2 **d1, t_vec2 **d2,
	const float d1v, const float d2v)
{
	t_vec2 *t;

	if (d1v <= d2v)
		return (0);
	t = *d1;
	d1 = d2;
	d2 = &t;
	return (1);
}
