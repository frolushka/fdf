/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:30:44 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/09 11:44:25 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	hook_mouse_move(int x, int y, t_mouse *mouse)
{
	int		dx;
	int		dy;

	dx = x - mouse->x;
	dy = y - mouse->y;
	if (dx != 0)
		hook_camera_rotate_y(mouse->cam, dx);
	if (dy != 0)
		hook_camera_rotate_x(mouse->cam, dy);
	mouse->x = x;
	mouse->y = y;
	return (0);
}
