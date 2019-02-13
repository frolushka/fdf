/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move_z.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 05:51:38 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/13 23:15:11 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

static void	camera_move_z_1(float val[4][4], const float l)
{
	val[3][0] += val[2][0] * l;
	val[3][1] += val[2][1] * l;
	val[3][2] += val[2][2] * l;
}

void		camera_move_z(t_cam *cam, const float l)
{
	camera_move_z_1(cam->cam->val, l * cam->speed);
}
