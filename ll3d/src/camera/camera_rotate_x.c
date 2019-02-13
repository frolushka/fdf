/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotate_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 05:53:36 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/13 23:16:07 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

void	camera_rotate_x(t_cam *cam, const float a)
{
	t_mtx4	*tmp;
	t_mtx4	*mr;

	if (!(tmp = mtx4_copy(cam->cam)))
		return ;
	if (!(mr = mtx4_get_rotation(cam->cam->val[0][0], cam->cam->val[0][1],
		cam->cam->val[0][2], a * cam->sence)))
		return ;
	mtx4x3_mult(tmp, mr, cam->cam);
	free(tmp);
}
