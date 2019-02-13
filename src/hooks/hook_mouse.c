/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:30:44 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/13 23:13:41 by sbednar          ###   ########.fr       */
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
		hook_camera_rotate_y(mouse->cam, (float)dx * MOUSE_TO_ANG);
	if (dy != 0)
		hook_camera_rotate_x(mouse->cam, (float)dy *
		(mouse->cam->mode == CAM_ISO ? 1 : -1) * MOUSE_TO_ANG);
	mouse->x = x;
	mouse->y = y;
	redraw(mouse->mlx, mouse->dots, mouse->cam);
	return (0);
}
