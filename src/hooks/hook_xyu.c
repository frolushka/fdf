/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_xyu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 22:08:07 by edraugr-          #+#    #+#             */
/*   Updated: 2019/02/13 22:08:53 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	lerp_v4(const t_vec4 *b, t_vec4 *dst, const float t)
{
	dst->x = dst->x + t * (b->x - dst->x);
	dst->y = dst->y + t * (b->y - dst->y);
	dst->z = dst->z + t * (b->z - dst->z);
}

int 		hook_x(t_mouse *mouse)
{
	int i, j;

	i = -1;
	if (!mouse->xyu)
		return (0);
	while(++i < mouse->dots->yc)
	{
		j = -1;
		while(++j < mouse->dots->xc)
			lerp_v4(mouse->xyu[i * mouse->dots->yc + j], mouse->dots->wb[i * mouse->dots->yc + j], 0.1f);
	}
	redraw(mouse->mlx, mouse->dots, mouse->cam);
	return (0);
}

int 		hook_h(t_mouse *mouse)
{
	int i, j;

	i = -1;
	if (!mouse->xyu)
		return (0);
	while(++i < mouse->dots->yc)
	{
		j = -1;
		while(++j < mouse->dots->xc)
			lerp_v4(mouse->norm[i * mouse->dots->yc + j], mouse->dots->wb[i * mouse->dots->yc + j], 0.1f);
	}
	redraw(mouse->mlx, mouse->dots, mouse->cam);
	return (0);
}
