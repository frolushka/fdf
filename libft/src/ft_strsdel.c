/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:08:04 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/23 01:48:45 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strsdel(char ***as)
{
	int	i;

	i = -1;
	if (!as || !*as || !**as)
		return ;
	while ((*as)[++i])
		free((*as)[i]);
	free(*as);
	*as = NULL;
}
