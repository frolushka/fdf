/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx4_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:06:38 by edraugr-          #+#    #+#             */
/*   Updated: 2019/02/04 08:10:19 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"
#include <stdio.h>

void	mtx4_print(t_mtx4 const *src)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		printf("(");
		while (++j < 4)
		{
			printf(" %.6f ", src->val[i][j]);
		}
		printf(")\n");
	}
}
