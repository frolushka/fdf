/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 22:44:24 by edraugr-          #+#    #+#             */
/*   Updated: 2019/02/13 22:12:19 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	hook_esc(void)
{
	//free all
	exit(0);
	return (0);
}

static void inline	hook_key_change(const int key, t_mouse *mouse)
{
	if (key == KEY_1)
		hook_camera_change_speed(mouse->cam, -1);
	else if (key == KEY_4)
		hook_camera_change_speed(mouse->cam, 1);
	if (key == KEY_2)
		hook_camera_change_sence(mouse->cam, -1);
	else if (key == KEY_5)
		hook_camera_change_sence(mouse->cam, 1);
	if (key == KEY_3)
		hook_camera_change_focus(mouse->cam, -1);
	else if (key == KEY_6)
		hook_camera_change_focus(mouse->cam, 1);
}

static void inline	hook_key_rotate(const int key, t_mouse *mouse)
{
	if (key == KEY_ARROWU)
		hook_camera_rotate_x(mouse->cam, 1);
	else if (key == KEY_ARROWD)
		hook_camera_rotate_x(mouse->cam, -1);
	if (key == KEY_ARROWL)
		hook_camera_rotate_y(mouse->cam, -1);
	else if (key == KEY_ARROWR)
		hook_camera_rotate_y(mouse->cam, 1);
}

static void inline	hook_key_move(const int key, t_mouse *mouse)
{
	if (mouse->cam->mode == CAM_ISO)
		return ;
	if (key == KEY_W)
		hook_camera_move_z(mouse->cam, 1);
	else if (key == KEY_S)
		hook_camera_move_z(mouse->cam, -1);
	if (key == KEY_D)
		hook_camera_move_x(mouse->cam, 1);
	else if (key == KEY_A)
		hook_camera_move_x(mouse->cam, -1);
	if (key == KEY_E)
		hook_camera_move_y(mouse->cam, 1);
	else if (key == KEY_Q)
		hook_camera_move_y(mouse->cam, -1);
}

int			hook_key(const int key, t_mouse *mouse)
{
	hook_key_move(key, mouse);
	hook_key_rotate(key, mouse);
	hook_key_change(key, mouse);
	if (key == KEY_ESC)
		hook_esc();
	if (key == KEY_F)
		mouse->cam = mouse->cam->add;
	if (key == KEY_8)
		mouse->dots->i = (mouse->dots->i + 1) % (mouse->dots->xc * mouse->dots->yc);
	if (key == KEY_7)
		mouse->dots->i = (mouse->dots->i + (mouse->dots->xc * mouse->dots->yc) - 1) % (mouse->dots->xc * mouse->dots->yc);
	if (key == KEY_R)
		dots_scale_y(mouse->dots, -1.1f);
	if (key == KEY_T)
		dots_scale_y(mouse->dots, 1.1f);
	if (key == KEY_C)
	{
		mouse->dots->cm = (mouse->dots->cm + 1) % 3;
		dots_color_update(mouse->dots);
	}
	if (key == KEY_X)
		hook_x(mouse);
	else if (key == KEY_H)
		hook_h(mouse);
	redraw(mouse->mlx, mouse->dots, mouse->cam);
	return (0);
}
