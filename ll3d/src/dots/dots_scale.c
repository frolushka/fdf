/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 04:14:04 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/06 04:19:00 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

void	dots_scale_y(t_dots *dots, float const s)
{
	int	i;
	int	c;

	i = -1;
	c = dots->xc * dots->yc;
	while (++i < c)
		if (s > 0)
			dots->wb[i]->y *= s;
		else
			dots->wb[i]->y /= -s;
}
