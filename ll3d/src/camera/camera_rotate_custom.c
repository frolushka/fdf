/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotate_custom.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 01:22:04 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/09 11:28:02 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"
#include <stdio.h>

void		camera_rotate_custom(t_cam *cam, t_vec3 const *p, t_vec3 *axis, float const a)
{
	t_mtx4	*tmp;
	t_mtx4	*mr;
	float		xp;
	float		yp;
	float		zp;

	if (!(tmp = mtx4_copy(cam->cam)))
		return ;
	xp = tmp->val[3][0];
	yp = tmp->val[3][1];
	zp = tmp->val[3][2];
	tmp->val[3][0] -= p->x;
	tmp->val[3][1] -= p->y;
	tmp->val[3][2] -= p->z;
	if (!(mr = mtx4_get_rotation(axis->x, axis->y, axis->z, a * cam->sence)))
		return ;
	// mtx4_print(mr);
	mtx4x4_mult(tmp, mr, cam->cam);
	cam->cam->val[3][0] += p->x;
	cam->cam->val[3][1] += p->y;
	cam->cam->val[3][2] += p->z;
	free(tmp);
}