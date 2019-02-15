/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:17:26 by edraugr-          #+#    #+#             */
/*   Updated: 2019/02/14 21:24:15 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void	put_camera_info(const t_mlx *mlx, t_cam const *cam)
{
	char	a[1024];

	sprintf(a, "CAMERA MATRIX:");
	mlx_string_put(mlx->mlx, mlx->win, 1500, 50, 0xFFFFFF, a);
	sprintf(a, "%-8.3f %-8.3f %-8.3f %-8.3f", cam->cam->val[0][0],
	cam->cam->val[0][1], cam->cam->val[0][2], cam->cam->val[0][3]);
	mlx_string_put(mlx->mlx, mlx->win, 1500, 70, 0xFFFFFF, a);
	sprintf(a, "%-8.3f %-8.3f %-8.3f %-8.3f", cam->cam->val[1][0],
	cam->cam->val[1][1], cam->cam->val[1][2], cam->cam->val[1][3]);
	mlx_string_put(mlx->mlx, mlx->win, 1500, 90, 0xFFFFFF, a);
	sprintf(a, "%-8.3f %-8.3f %-8.3f %-8.3f", cam->cam->val[2][0],
	cam->cam->val[2][1], cam->cam->val[2][2], cam->cam->val[2][3]);
	mlx_string_put(mlx->mlx, mlx->win, 1500, 110, 0xFFFFFF, a);
	sprintf(a, "%-8.3f %-8.3f %-8.3f %-8.3f", cam->cam->val[3][0],
	cam->cam->val[3][1], cam->cam->val[3][2], cam->cam->val[3][3]);
	mlx_string_put(mlx->mlx, mlx->win, 1500, 130, 0xFFFFFF, a);
	sprintf(a, "SPEED:   %-7.3f   (keys 4+ 1-)", cam->speed);
	mlx_string_put(mlx->mlx, mlx->win, 1500, 170, 0xFFFFFF, a);
	sprintf(a, "SENCE:   %-7.3f   (keys 5+ 2-)", cam->sence);
	mlx_string_put(mlx->mlx, mlx->win, 1500, 190, 0xFFFFFF, a);
	sprintf(a, "FOCUS:   %-7.3f   (keys 6+ 3-)%s", cam->focus, cam->mode ==
	CAM_ISO ? " DISABLED" : "");
	mlx_string_put(mlx->mlx, mlx->win, 1500, 210, 0xFFFFFF, a);
	sprintf(a, "MODE:    %-7s (key f)", cam->mode == CAM_ISO ? "ISO" : "PER");
	mlx_string_put(mlx->mlx, mlx->win, 1500, 230, 0xFFFFFF, a);
}

static void	put_dots_info(const t_mlx *mlx, t_dots const *dots)
{
	char	a[1024];

	sprintf(a, "DOTS[%d][%d]:", dots->i / dots->xc, dots->i % dots->xc);
	mlx_string_put(mlx->mlx, mlx->win, 1500, 270, 0xFFFFFF, a);
	sprintf(a, "%-8.3f %-8.3f %-8.3f %-8.3f", dots->wb[dots->i]->x,
	dots->wb[dots->i]->y, dots->wb[dots->i]->z, dots->wb[dots->i]->w);
	mlx_string_put(mlx->mlx, mlx->win, 1500, 290, 0xFFFFFF, a);
	sprintf(a, "%-8.3f %-8.3f %-8.3f", dots->cb[dots->i]->x,
	dots->cb[dots->i]->y, dots->cb[dots->i]->z);
	mlx_string_put(mlx->mlx, mlx->win, 1500, 310, 0xFFFFFF, a);
	sprintf(a, "%-8d %-8d", dots->sb[dots->i]->x, dots->sb[dots->i]->y);
	mlx_string_put(mlx->mlx, mlx->win, 1500, 330, 0xFFFFFF, a);
}

void		redraw(const t_mlx *c, t_dots *dots, const t_cam *cam)
{
	image_clear(c->image);
	dots_solve(dots, cam);
	dots_connect(dots, c);
	mlx_put_image_to_window(c->mlx, c->win, c->image->image, 0, 0);
	put_camera_info(c, cam);
	put_dots_info(c, dots);
}
