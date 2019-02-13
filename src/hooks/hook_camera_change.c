/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_camera_change.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 00:10:42 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/09 11:10:55 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hook_camera_change_speed(t_cam *cam, float const a)
{
	cam->speed += a * CAM_SP;
}

void	hook_camera_change_sence(t_cam *cam, float const a)
{
	cam->sence += a * CAM_SE;
}

void	hook_camera_change_focus(t_cam *cam, float const a)
{
	cam->focus += a * CAM_FO;
	(cam->focus > 100 ? cam->focus = 100 : 0);
	(cam->focus < 0.1f ? cam->focus = 0.1f : 0);
}
