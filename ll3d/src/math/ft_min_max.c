/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 22:24:33 by edraugr-          #+#    #+#             */
/*   Updated: 2019/02/11 22:31:08 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

float	ft_fmin(const float a, const float b)
{
	return (a > b ? b : a);
}

int		ft_min(const int a, const int b)
{
	return (a > b ? b : a);
}

float	ft_fmax(const float a, const float b)
{
	return (a < b ? b : a);
}

int		ft_max(const int a, const int b)
{
	return (a < b ? b : a);
}
