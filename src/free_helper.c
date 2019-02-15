/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 00:42:43 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/14 21:08:35 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_helper2(t_mouse *mouse)
{
	if (mouse->norm && *(mouse->norm))
		memset_free((void **)mouse->norm,
		mouse->dots->xc * mouse->dots->yc * sizeof(t_vec4 *));
	if (mouse->xyu && *(mouse->xyu))
		memset_free((void **)mouse->xyu,
		mouse->dots->xc * mouse->dots->yc * sizeof(t_vec4 *));
	if (mouse->norm)
		ft_memdel((void **)mouse->norm);
	if (mouse->xyu)
		ft_memdel((void **)mouse->xyu);
}

int			free_helper(t_mlx **mlx, t_dots **dots, t_cam **cam,
	t_mouse **mouse)
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
	{
		free_helper2(*mouse);
		ft_memdel((void **)mouse);
	}
	write(1, "something happend...\n", 21);
	return (0);
}
