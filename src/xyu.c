/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xyu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 21:57:30 by edraugr-          #+#    #+#             */
/*   Updated: 2019/02/13 22:20:44 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vec4	*vec4_fv3(const t_vec3 *v3, float w)
{
	t_vec4	*res;

	res = vec4_init();
	res->x = v3->x;
	res->y = v3->y;
	res->z = v3->z;
	res->w = w;
	return (res);
}

static void		fill_xuy_check_h(t_vec4 **res, const t_xyu *p,
	const t_dots *src, t_vec2 *i)
{
	res[i->x * src->yc + i->y] = vec4_fv3(&(p->ff_r[i->y /
		(src->xc / 8 + 1)]), src->wb[i->x * src->yc + i->y]->w);
	res[i->x * src->yc + i->y]->x += (i->x - 4);
	res[i->x * src->yc + i->y]->y += 10 * sinf(2 * ((100.0f *
		((float)M_PI)) / 180.0f) * ((float)i->x / (float)src->yc));
}

static void		fill_xuy_check(t_vec4 **res, const t_xyu *p,
	const t_dots *src, t_vec2 *i)
{
	if (i->x == 0)
		res[i->x * src->yc + i->y] = vec4_fv3(&(p->bb_r[i->y /
			(src->xc / 5 + 1)]), src->wb[i->x * src->yc + i->y]->w);
	if (i->x == 1)
		res[i->x * src->yc + i->y] = vec4_fv3(&(p->b_r[i->y /
			(src->xc / 7 + 1)]), src->wb[i->x * src->yc + i->y]->w);
	if (i->x == 2)
		res[i->x * src->yc + i->y] = vec4_fv3(&(p->m_r[i->y /
			(src->xc / 12 + 1)]), src->wb[i->x * src->yc + i->y]->w);
	if (i->x == 3)
		res[i->x * src->yc + i->y] = vec4_fv3(&(p->f_r[i->y /
			(src->xc / 10 + 1)]), src->wb[i->x * src->yc + i->y]->w);
	if (i->x >= 4 && i->x < src->yc - 1)
		fill_xuy_check_h(res, p, src, i);
	if (i->x == src->yc - 1)
	{
		res[i->x * src->yc + i->y] = vec4_fv3(&(p->bb_r[i->y
			/ (src->xc / 5 + 1)]), src->wb[i->x * src->yc + i->y]->w);
		res[i->x * src->yc + i->y]->x += i->x + 5;
	}
	free(i);
}

t_vec4			**get_xyu(t_xyu *p, const t_dots *src)
{
	t_vec4	**res;
	int		i;
	int		j;

	if (src->xc < 8 || src->yc < 12
		|| !p
		|| !(res = (t_vec4 **)malloc(sizeof(t_vec4 *)
		* src->xc * src->yc)))
		return (NULL);
	i = -1;
	while (++i < src->yc)
	{
		j = -1;
		while (++j < src->xc)
			fill_xuy_check(res, p, src, vec2_new(i, j));
	}
	free(p);
	return (res);
}

t_xyu			*xyu_init(void)
{
	t_xyu	*res;

	res = (t_xyu *)malloc(sizeof(t_xyu));
	if (!res)
		return (NULL);
	vec3_set(&(res->m_r[0]), 4, -8, 4);
	vec3_set(&(res->m_r[1]), 4, -8, 1);
	vec3_set(&(res->m_r[2]), 4, -6, 0);
	vec3_set(&(res->m_r[3]), 4, -3, 0);
	vec3_set(&(res->m_r[4]), 4, -1, 1);
	vec3_set(&(res->m_r[5]), 4, 0, 3);
	vec3_set(&(res->m_r[6]), 4, 0, 5);
	vec3_set(&(res->m_r[7]), 4, -1, 7);
	vec3_set(&(res->m_r[8]), 4, -3, 8);
	vec3_set(&(res->m_r[9]), 4, -6, 8);
	vec3_set(&(res->m_r[10]), 4, -8, 7);
	vec3_set(&(res->m_r[11]), 4, -8, 4);
	fill_xyu1(res);
	fill_xyu2(res);
	return (res);
}
