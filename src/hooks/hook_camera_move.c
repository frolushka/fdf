/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_camera_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 00:09:16 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/14 00:41:09 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hook_camera_move_x(t_cam *cam, float const a)
{
	if (cam->mode == CAM_ISO)
		return ;
	camera_move_x(cam, a);
}

void	hook_camera_move_y(t_cam *cam, float const a)
{
	if (cam->mode == CAM_ISO)
		return ;
	camera_move_y(cam, a);
}

void	hook_camera_move_z(t_cam *cam, float const a)
{
	if (cam->mode == CAM_ISO)
		return ;
	camera_move_z(cam, a);
}
