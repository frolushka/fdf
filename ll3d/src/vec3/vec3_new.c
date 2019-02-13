/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 05:10:50 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/13 23:25:57 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

t_vec3	*vec3_new(const float x, const float y, const float z)
{
	t_vec3	*vr;

	if (!(vr = vec3_init()))
		return (NULL);
	vr->x = x;
	vr->y = y;
	vr->z = z;
	return (vr);
}
