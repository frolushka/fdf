/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oclude_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 00:30:22 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/14 00:37:52 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

static void	oclude_x_1(t_vec2 *d1, t_vec2 *d2)
{
	if (d1->y > SCREEN_Y)
	{
		d1->x = d1->x + (int)((float)
			((d2->x - d1->x) * (SCREEN_Y - d1->y))
			/ (float)(d2->y - d1->y));
		d1->y = SCREEN_Y;
	}
	if (d2->y < 0)
	{
		d2->x = d2->x + (int)((float)
			((d2->x - d1->x) * d2->y)
			/ (float)(d1->y - d2->y));
		d2->y = 0;
	}
	if (d1->y < 0)
	{
		d1->x = d2->x + (int)((float)
			((d2->x - d1->x) * d2->y)
			/ (float)(d1->y - d2->y));
		d1->y = 0;
	}
}

void	oclude_x(t_vec2 *d1, t_vec2 *d2)
{
	if ((d1->y > 0 && d1->y < SCREEN_Y)
		&& (d2->y > 0 && d2->y < SCREEN_Y))
		return ;
	if (ft_abs(d2->x - d1->x) <= 2)
	{
		if(d1->y < 0 || d1->y > SCREEN_Y)
			d1->y = ((d1->y < 0) ? 0 : SCREEN_Y);
		if(d2->y < 0 || d2->y > SCREEN_Y)
			d2->y = ((d2->y < 0) ? 0 : SCREEN_Y);
		return ;
	}
	if (d2->y > SCREEN_Y)
	{
		d2->x = d1->x + (int)((float)
			((d2->x - d1->x) * (SCREEN_Y - d1->y))
			/ (float)(d2->y - d1->y));
		d2->y = SCREEN_Y;
	}
	oclude_x_1(d1, d2);
}