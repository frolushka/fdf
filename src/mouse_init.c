/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:24:05 by edraugr-          #+#    #+#             */
/*   Updated: 2019/02/09 11:37:53 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mouse	*mouse_init(t_mlx *mlx, t_cam *cam, t_dots *dots)
{
	t_mouse	*res;

	if (!(res = (t_mouse *)malloc(sizeof(t_mouse))))
		return (NULL);
	res->x = 0;
	res->y = 0;
	res->cam = cam;
	res->dots = dots;
	res->mlx = mlx;
	return (res);
}
