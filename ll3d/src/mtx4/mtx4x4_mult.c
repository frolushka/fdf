/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx4x4_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 03:19:32 by edraugr-          #+#    #+#             */
/*   Updated: 2019/02/04 05:06:33 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

t_mtx4	*mtx4x4_mult(t_mtx4 const *a, t_mtx4 const *b, t_mtx4 *dst)
{
	int	c;
	int	r;
	int	i;

	mtx4_clear(dst);
	r = -1;
	while (++r < 4)
	{
		c = -1;
		while (++c < 4)
		{
			i = -1;
			while (++i < 4)
				dst->val[r][c] += a->val[r][i] * b->val[i][c];
		}
	}
	return (dst);
}
