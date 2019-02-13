/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 00:42:43 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/14 00:47:21 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		free_helper(t_mlx **mlx, t_dots **dots, t_cam **cam, t_mouse **mouse)
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
	write(1, "something happed...\n", 20);
	return (0);
}