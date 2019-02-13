/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_set_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 05:37:56 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/13 23:21:43 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

void	image_set_pixel(t_image *img, const int x, const int y, const int c)
{
	int	p;
	int	*im;

	if (x <= -img->x / 2.0f || x >= img->x / 2.0f || y <= -img->y / 2.0f ||
		y >= img->y / 2.0f)
		return ;
	p = (int)((x + img->x / 2.0f) + (y + img->y / 2.0f) * img->x) * img->bpp;
	im = (int *)(img->ptr + p);
	if (*im < c)
		*im = c;
}