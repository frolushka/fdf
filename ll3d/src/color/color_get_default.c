/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_get_default.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:35:40 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/14 20:37:26 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

static int	get_default_color_m0(const int z)
{
	(void)z;
	return (COLOR_WHITE);
}

static int	get_default_color_m1(const int z)
{
	if (z >= 10)
		return (COLOR_WHITE);
	else if (z >= -20 && z < 10)
		return (color_lerp(COLOR_RED, COLOR_WHITE, (z + 20.0f) / 30));
	else
		return (COLOR_RED);
}

static int	get_default_color_m2(const int z)
{
	if (z >= 20)
		return (COLOR_WHITE);
	else if (z >= 5 && z < 20)
		return (COLOR_LGRAY);
	else if (z >= 0 && z < 5)
		return (COLOR_GREEN);
	else if (z >= -7 && z < 0)
		return (COLOR_BROWN);
	else if (z >= -20 && z < -7)
		return (COLOR_GRAY);
	else if (z >= -40 && z < -20)
		return (color_lerp(COLOR_BLACK, COLOR_GRAY, (z + 40.0f) / 20));
	else
		return (COLOR_BLACK);
}

int			color_get_default(const int z, const int cm)
{
	if (cm == 0)
		return (get_default_color_m2(z));
	else if (cm == 1)
		return (get_default_color_m1(z));
	else
		return (get_default_color_m0(z));
}
