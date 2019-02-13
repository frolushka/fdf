/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx4_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 22:58:25 by edraugr-          #+#    #+#             */
/*   Updated: 2019/02/13 23:32:57 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

t_mtx4	*mtx4_init(const float val)
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
