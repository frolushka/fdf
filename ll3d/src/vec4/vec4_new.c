/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 05:11:54 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/13 23:26:57 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

t_vec4	*vec4_new(const float x, const float y, const float z,
	const float w)
{
	t_vec4	*vr;

	if (!(vr = vec4_init()))
		return (NULL);
	vr->x = x;
	vr->y = y;
	vr->z = z;
	vr->w = w;
	return (vr);
}
