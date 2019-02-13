/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_camera_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 00:39:49 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/13 21:54:19 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	hook_camera_rotate_x(t_cam *cam, float const a)
{
	t_vec3	*axis;

	if (cam->mode == CAM_PER)
		camera_per_calc_piv(cam);
	axis = vec3_new(cam->cam->val[0][0], cam->cam->val[0][1], cam->cam->val[0][2]);
	camera_rotate_custom(cam, cam->piv, axis, a);
	free(axis);
}

void	hook_camera_rotate_y(t_cam *cam, float const a)
{
	t_vec3	*axis;

	if (cam->mode == CAM_PER)
		camera_per_calc_piv(cam);
	axis = vec3_new(0, 1, 0);
	camera_rotate_custom(cam, cam->piv, axis, -a);
	free(axis);
}
