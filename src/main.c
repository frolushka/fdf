/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:21:58 by edraugr-          #+#    #+#             */
/*   Updated: 2019/02/13 22:05:04 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		free_helper(t_mlx **mlx, t_dots **dots, t_cam **cam, t_mouse **mouse)
{
	if (mlx && *mlx)
		mlx_free_ll3d(mlx);
	if (cam && *cam)
	{
		((*cam)->cam ? ft_memdel((void **)&((*cam)->cam)) : 0);
		ft_memdel((void **)cam);
	}
	if (dots && *dots)
		dots_free(dots);
	if (mouse && *mouse)
		ft_memdel((void **)mouse);
	write(1, "error\n", 6);
	return (0);
}

static t_cam	*camera_default(float z)
{
	t_cam *res;

	if (!(res = camera_init()))
		return (NULL);
	camera_rotate_x(res, 90);
	camera_rotate_y(res, 180);
	camera_move_z(res, -z);
	return (res);
}

static t_cam	*camera_setup(t_cam **cam, t_dots **dots)
{
	if (!(*cam = camera_default(sqrt(((*dots)->xc * (*dots)->xc / 4) +
		((*dots)->yc * (*dots)->yc / 4) + (((*dots)->zmax - (*dots)->zmin) *
		((*dots)->zmax - (*dots)->zmin) / 4)) + 5)))
		return (NULL);
	(*cam)->focus = 25;
	(*cam)->piv = vec3_new(0, ((*dots)->zmax + (*dots)->zmin) / 2.0f, 0);
	if (!((*cam)->add = camera_default((*dots)->zmax + 5)))
		return (*cam);
	(*cam)->add->focus = (SCREEN_X / 2.0f / 25) / tanf(M_PI / 6);
	(*cam)->add->mode = CAM_PER;
	(*cam)->add->add = *cam;
	return (*cam);
}

static void		default_init(t_mlx **mlx, t_dots **dots, t_cam **cam, t_mouse **mouse)
{
	*mlx = NULL;
	*dots = NULL;
	*cam = NULL;
	*mouse = NULL;
}

int 			main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_dots	*dots;
	t_cam	*cam;
	t_mouse	*mouse;

	if (argc != 2)
	{
		write(1, "usage: ./fdf name.fdf\n", 22);
		exit(0);
	}
	default_init(&mlx, &dots, &cam, &mouse);
	if (!(read_dots(argv[1], &dots)) ||
		!(mlx = mlx_init_ll3d(SCREEN_X, SCREEN_Y, SCREEN_NAME)) ||
		!(cam = camera_setup(&cam, &dots)) ||
		!(mouse = mouse_init(mlx, cam, dots)))
		exit(free_helper(&mlx, &dots, &cam, &mouse));
	dots->i = 0;
	if ((mouse->xyu = get_xyu(xyu_init(), dots)))
		mouse->norm = dots4_cpy((const t_vec4 **)dots->wb, dots->xc, dots->yc);
	redraw(mouse->mlx, mouse->dots, mouse->cam);
	//mlx_hook(mlx->win, 4, 0, hook_wheel, mouse);
	mlx_hook(mlx->win, 6, 0, hook_mouse_move, mouse);
	mlx_hook(mlx->win, 2, 0, hook_key, mouse);
	mlx_loop(mlx->mlx);
	return (0);
}
