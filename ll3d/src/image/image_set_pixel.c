/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_set_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 05:37:56 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/11 23:24:19 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

void	image_set_pixel(t_image *img, int const x, int const y, int const c)
{
	int	p;
	int	*im;

	if (x <= -img->x / 2.0f || x >= img->x / 2.0f || y <= -img->y / 2.0f || y >= img->y / 2.0f)
		return ;
	p = (int)((x + img->x / 2.0f) + (y + img->y / 2.0f) * img->x) * img->bpp;
	im = (int *)(img->ptr + p);
	if (*im < c)
		*im = c;
}

// void	image_set_pixel(t_image *img, int const x, int const y, int const c)
// {
// 	if (x < 0 || x >= SCREEN_X || y < 0 || y >= SCREEN_Y)
// 		return ;
// 	((int *)(img->ptr + ((x + y * SCREEN_X) * img->bpp)))[0] = c;
// }
