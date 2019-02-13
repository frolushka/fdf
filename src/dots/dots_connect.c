/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots_connect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 03:23:03 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/11 23:00:39 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	dots_connect(t_dots *d, const t_mlx *c)
// {
// 	int	i;
// 	int	j;
// 	int	xc;
// 	int	yc;

// 	xc = d->xc;
// 	yc = d->yc;
// 	i = -1;
// 	while (++i < yc)
// 	{
// 		j = -1;
// 		while (++j < xc)
// 		{
// 			((j != xc - 1)
// 			//		&& ((d->cb[i * xc + j]->z > 0) || (d->cb[i * xc + j + 1]->z > 0))
// 				)
// 				? image_draw_line(c, d->sb[i * xc + j],
// 					d->sb[i * xc + j + 1], vec2_new((int)d->wb[i * xc + j]->w,
// 					(int)d->wb[i * xc + j + 1]->w))
// 				: 0;
// 			((i != yc - 1)
// 			//		&& ((d->cb[i * xc + j]->z > 0) || (d->cb[i * xc + j + 1]->z > 0))
// 					)
// 				? image_draw_line(c, d->sb[i * xc + j],
// 					d->sb[(i + 1) * xc + j], vec2_new((int)d->wb[i * xc + j]->w,
// 					(int)d->wb[(i + 1) * xc + j]->w))
// 				: 0;
// 		}
// 	}
// }

static int	check_out(const t_dots *d, const int d1, const int d2)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = d->sb[d1]->x;
	x2 = d->sb[d2]->x;
	y1 = d->sb[d1]->y;
	y2 = d->sb[d2]->y;
	if ((x1 < (-SCREEN_X / 2) && x2 < (-SCREEN_X / 2))
		|| (x1 > (SCREEN_X / 2) && x2 > (SCREEN_X / 2))
		|| (y1 < (-SCREEN_Y / 2) && y2 < (-SCREEN_Y / 2))
		|| (y1 > (SCREEN_Y / 2) && y2 > (SCREEN_Y / 2))
		|| (d->cb[d1]->z < 0 && d->cb[d2]->z < 0))
		return (1);
	return (0);
}

static int	swap_if_d2_less(t_vec2 **d1, t_vec2 **d2,
	const float d1v, const float d2v)
{
	t_vec2 *t;

	if (d1v <= d2v)
		return (0);
	t = *d1;
	d1 = d2;
	d2 = &t;
	return (1);
}

static void	oclude_z(t_vec2 *d1, t_vec2 *d2, float z1, float z2)
{
	if (z1 > 0 && z2 > 0)
		return ;
	if (d2->y > d1->y)
		d2->y = d2->y + (int)((float)
			((d2->y - d1->y) * (z2))
			/ (float)(z1 - z2));
	else
		d2->y = d2->y + (int)((float)
			((d2->y - d1->y) * (z2))
			/ (float)(z1 - z2));
	if (d2->x > d1->x)
		d2->x = d2->x + (int)((float)
			((d2->x - d1->x) * z2)
			/ (float)(z1 - z2));
	else
		d2->x = d2->x + (int)((float)
			((d2->x - d1->x) * z2)
			/ (float)(z1 - z2));
}

static void	oclude_x(t_vec2 *d1, t_vec2 *d2)
{
	if ((d1->y > 0 && d1->y < SCREEN_Y)
		&& (d2->y > 0 && d2->y < SCREEN_Y))
		return ;
	if (abs(d2->x - d1->x) <= 2)
	{
		if(d1->y < 0 || d1->y > SCREEN_Y)
			d1->y = ((d1->y < 0) ? 0 : SCREEN_Y);
		if(d2->y < 0 || d2->y > SCREEN_Y)
			d2->y = ((d2->y < 0) ? 0 : SCREEN_Y);
		return ;
	}
	if (d2->y > SCREEN_Y)
	{
		d2->x = d1->x + (int)((float)
			((d2->x - d1->x) * (SCREEN_Y - d1->y))
			/ (float)(d2->y - d1->y));
		d2->y = SCREEN_Y;
	}
	if (d1->y > SCREEN_Y)
	{
		d1->x = d1->x + (int)((float)
			((d2->x - d1->x) * (SCREEN_Y - d1->y))
			/ (float)(d2->y - d1->y));
		d1->y = SCREEN_Y;
	}
	if (d2->y < 0)
	{
		d2->x = d2->x + (int)((float)
			((d2->x - d1->x) * d2->y)
			/ (float)(d1->y - d2->y));
		d2->y = 0;
	}
	if (d1->y < 0)
	{
		d1->x = d2->x + (int)((float)
			((d2->x - d1->x) * d2->y)
			/ (float)(d1->y - d2->y));
		d1->y = 0;
	}
}

static void	oclude_y(t_vec2 *d1, t_vec2 *d2)
{
	if ((d1->x > 0 && d2->x < SCREEN_X)
		&& (d2->x > 0 && d2->x < SCREEN_X))
		return ;
	if (abs(d2->y - d1->y) <= 2)
	{
		if(d1->x < 0 || d1->x > SCREEN_X)
			d1->x = ((d1->x < 0) ? 0 : SCREEN_X);
		if(d2->x < 0 || d2->x > SCREEN_X)
			d2->x = ((d2->x < 0) ? 0 : SCREEN_X);
		return ;
	}
	if (d2->x > SCREEN_X)
	{
		d2->y = d2->y + (int)((float)
			((d2->y - d1->y) * (SCREEN_X - d2->x))
			/ (float)(d2->x - d1->x));
		d2->x = SCREEN_X;
	}
	if (d1->x > SCREEN_X)
	{
		d1->y = d2->y - (int)((float)
			((d2->y - d1->y) * (SCREEN_X - d2->x))
			/ (float)(d2->x - d1->x));
		d1->x = SCREEN_X;
	}
	if (d2->x < 0)
	{
		d2->y = d2->y + (int)((float)
			((d2->y - d1->y) * d2->x)
			/ (float)(d1->x - d2->x));
		d2->x = 0;
	}
	if (d1->x < 0)
	{
		d1->y = d2->y + (int)((float)
			((d2->y - d1->y) * d2->x)
			/ (float)(d1->x - d2->x));
		d1->x = 0;
	}
}

static void	draw_with_oclusion(const t_mlx *c, t_dots *d,
	int d1, int d2)
{
	t_vec2	*v1;
	t_vec2	*v2;
	t_vec2	*cv;

	if (check_out(d, d1, d2))
		return ;
	// if (d->cb[d2]->z < 0 || d->cb[d1]->z < 0)
	// 	return ;
	v1 = vec2_new(d->sb[d1]->x + SCREEN_X / 2, d->sb[d1]->y + SCREEN_Y / 2);
	v2 = vec2_new(d->sb[d2]->x + SCREEN_X / 2, d->sb[d2]->y + SCREEN_Y / 2);
	cv = vec2_new((int)d->wb[d1]->w, (int)d->wb[d2]->w);
	//swap_if_d2_less(&v1, &v2, d->cb[d1]->z, d->cb[d2]->z);
	if (d->cb[d1]->z > d->cb[d2]->z)
		oclude_z(v1, v2, d->cb[d1]->z, d->cb[d2]->z);
	else
		oclude_z(v2, v1, d->cb[d2]->z, d->cb[d1]->z);
	//ft_fmax(d->cb[d2]->z, d->cb[d1]->z),
		//ft_fmin(d->cb[d2]->z, d->cb[d1]->z));
	swap_if_d2_less(&v1, &v2, (float)v2->x, (float)v1->x);
	oclude_x(v1, v2);
	swap_if_d2_less(&v1, &v2, (float)v2->y, (float)v1->y);
	oclude_y(v1, v2);
	vec2_set(v1, v1->x - SCREEN_X / 2, v1->y - SCREEN_Y / 2);
	vec2_set(v2, v2->x - SCREEN_X / 2, v2->y - SCREEN_Y / 2);
	image_draw_line(c, v1, v2, cv);
	free(cv);
	free(v1);
	free(v2);
}

void	dots_connect(t_dots *d, const t_mlx *c)
{
	int	i;
	int	j;
	int	xc;
	int	yc;

	xc = d->xc;
	yc = d->yc;
	i = -1;
	while (++i < yc)
	{
		j = -1;
		while (++j < xc)
		{
			if (j != xc - 1)
				draw_with_oclusion(c, d, i * xc + j, i * xc + j + 1);
			if (i != yc - 1)
				draw_with_oclusion(c, d, i * xc + j, (i + 1) * xc + j);
		}
	}
}
