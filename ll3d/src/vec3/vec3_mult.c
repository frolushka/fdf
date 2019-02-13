/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_mult.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 05:11:10 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/13 23:25:42 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

t_vec3	*vec3_mult(const t_vec3 *v, const float s)
{
	t_vec3	*vr;

	if (!(vr = vec3_init()))
		return (NULL);
	vr->x = v->x * s;
	vr->y = v->y * s;
	vr->z = v->z * s;
	return (vr);
}
