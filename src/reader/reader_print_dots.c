/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_print_dots.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 22:38:06 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/06 00:54:43 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			print_dots(t_dots *res)
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
