/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 23:19:43 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/11 16:01:29 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dots_solve(t_dots *dots, const t_cam *cam)
{
	int	i;
	int	c;

	i = -1;
	c = dots->xc * dots->yc;
	while (++i < c)
	{
		dots_fill_cb(dots->wb[i], cam->cam, dots->cb[i]);
		if (cam->mode == CAM_ISO)
			dots_fill_sb_iso(dots->cb[i], dots->sb[i], cam->focus);
		else
			dots_fill_sb_per(dots->cb[i], dots->sb[i], cam);
	}
}
