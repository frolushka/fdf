/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 05:54:16 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/04 07:32:30 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"
#include <stdio.h>

int	dots_print(t_dots *res)
{
	int	i;
	int	j;

	i = -1;
	while (++i < res->yc)
	{
		j = -1;
		while (++j < res->xc)
		{
			printf("(%.3f,%.3f,%.3f,%.3f)\t", res->wb[i * res->xc + j]->x, res->wb[i * res->xc + j]->y, res->wb[i * res->xc + j]->z, res->wb[i * res->xc + j]->w);
		}
		printf("\n");
	}
	return (0);
}
