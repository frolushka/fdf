/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_mult.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 03:29:42 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/04 03:49:54 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

t_vec2	*vec2_mult(t_vec2 const *v, int const s)
{
	t_vec2	*vr;

	if (!(vr = vec2_init()))
		return (NULL);
	vr->x = v->x * s;
	vr->y = v->y * s;
	return (vr);
}