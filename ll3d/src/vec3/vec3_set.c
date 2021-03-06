/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 22:01:24 by edraugr-          #+#    #+#             */
/*   Updated: 2019/02/13 22:01:34 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

void	vec3_set(t_vec3 *v, const float x, const float y, const float z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}
