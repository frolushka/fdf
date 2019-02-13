/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_ll3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 07:10:16 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/04 07:32:44 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

t_mlx	*mlx_init_ll3d(int width, int height, char *header)
{
	t_mlx	*res;

	if (!(res = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	res->width = width;
	res->height = height;
	if (!(res->mlx = mlx_init()) ||
		!(res->win = mlx_new_window(res->mlx, width, height, header)) ||
		!(res->image = image_init(res, width, height)))
		return (NULL);
	return (res);
}
