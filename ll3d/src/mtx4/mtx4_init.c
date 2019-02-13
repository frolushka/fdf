/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx4_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 22:58:25 by edraugr-          #+#    #+#             */
/*   Updated: 2019/02/04 05:06:12 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

t_mtx4	*mtx4_init(float const val)
{
	t_mtx4	*res;
	int		i;
	int		j;

	if (!(res = (t_mtx4 *)malloc(sizeof(t_mtx4))))
		return (NULL);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			res->val[i][j] = val;
	}
	return (res);
}
