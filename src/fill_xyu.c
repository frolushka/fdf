/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_xyu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 21:58:10 by edraugr-          #+#    #+#             */
/*   Updated: 2019/02/13 21:58:25 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_xyu1(t_xyu *res)
{
	vec3_set(&(res->b_r[0]), 2, -7, 4);
	vec3_set(&(res->b_r[1]), 2, -6, 2);
	vec3_set(&(res->b_r[2]), 2, -4, 2);
	vec3_set(&(res->b_r[3]), 2, -2, 3);
	vec3_set(&(res->b_r[4]), 2, -2, 6);
	vec3_set(&(res->b_r[5]), 2, -6, 6);
	vec3_set(&(res->b_r[6]), 2, -7, 4);
	vec3_set(&(res->bb_r[0]), 0, -5, 4);
	vec3_set(&(res->bb_r[1]), 0, -4, 3);
	vec3_set(&(res->bb_r[2]), 0, -3, 4);
	vec3_set(&(res->bb_r[3]), 0, -4, 5);
	vec3_set(&(res->bb_r[4]), 0, -5, 4);
}

void	fill_xyu2(t_xyu *res)
{
	vec3_set(&(res->f_r[0]), 6, -6, 4);
	vec3_set(&(res->f_r[1]), 6, -5, 2);
	vec3_set(&(res->f_r[2]), 6, -3, 1);
	vec3_set(&(res->f_r[3]), 6, -1, 2);
	vec3_set(&(res->f_r[4]), 6, 0, 3);
	vec3_set(&(res->f_r[5]), 6, 0, 5);
	vec3_set(&(res->f_r[6]), 6, -1, 6);
	vec3_set(&(res->f_r[7]), 6, -3, 7);
	vec3_set(&(res->f_r[8]), 6, -5, 6);
	vec3_set(&(res->f_r[9]), 6, -6, 4);
	vec3_set(&(res->ff_r[0]), 8, -4, 4);
	vec3_set(&(res->ff_r[1]), 8, -3, 2.5f);
	vec3_set(&(res->ff_r[2]), 8, -2, 2);
	vec3_set(&(res->ff_r[3]), 8, 0, 3);
	vec3_set(&(res->ff_r[4]), 8, 0, 5);
	vec3_set(&(res->ff_r[5]), 8, -2, 6);
	vec3_set(&(res->ff_r[6]), 8, -3, 5.5f);
	vec3_set(&(res->ff_r[7]), 8, -4, 4);
}
