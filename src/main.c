/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:21:58 by edraugr-          #+#    #+#             */
/*   Updated: 2019/02/12 17:30:54 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static t_cam	*camera_default(void)
{
	t_cam *res;

	if (!(res = camera_init()))
		return (NULL);
	camera_rotate_x(res, 90);
	camera_rotate_y(res, 180);
	camera_move_z(res, -20);
	return (res);
}

int 			main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_dots	*dots;
	t_cam	*cam;
	t_mouse	*mouse;

	if (argc != 2)
	{
		printf("UDI NAXUY, GDE TZ???\n");
		return (0);
	}
	if (!(read_dots(argv[1], &dots)))
	{
		printf("VSE SLOMALOS' VIRUBAI\n");
		return (0);
	}
	mlx = mlx_init_ll3d(SCREEN_X, SCREEN_Y, SCREEN_NAME);
	cam = camera_init();

	// default position for cameras is same
	cam = camera_default();
	cam->focus = 25;
	cam->piv = vec3_new(0, (dots->zmax + dots->zmin) / 2.0f, 0);
	cam->add = camera_default();
	cam->add->focus = (SCREEN_X / 2.0f / 25) / tanf(M_PI / 6);
	cam->add->mode = CAM_PER;
	cam->add->add = cam;

	dots->i = 0;
	mouse = mouse_init(mlx, cam, dots);
	redraw(mouse->mlx, mouse->dots, mouse->cam);

	//mlx_hook(mlx->win, 4, 0, hook_wheel, mouse);
	// mlx_hook(mlx->win, 6, 0, hook_mouse_move, mouse);
	mlx_hook(mlx->win, 2, 0, hook_key, mouse);
	mlx_loop(mlx->mlx);
	return (0);
}
