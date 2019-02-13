/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move_y.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 05:51:00 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/05 23:34:25 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

static void	camera_move_y_1(float val[4][4], float const l)
{
	val[3][0] += val[1][0] * l;
	val[3][1] += val[1][1] * l;
	val[3][2] += val[1][2] * l;
}

void		camera_move_y(t_cam *cam, float const l)
{
	camera_move_y_1(cam->cam->val, l * cam->speed);
}
