/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 22:39:31 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/06 02:56:52 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					get_color(char const *it)
{
	int	i;
	int	k;
	int	res;

	i = 0;
	res = 0;
	while (it[i] && (it[i] == '-' || ft_isdigit(it[i])))
		++i;
	if (it[i] == ',')
	{
		i += 3;
		k = -1;
		while (++k < 6)
		{
			if (it[i + k] >= 'A' && it[i + k] <= 'F')
				res += it[i + k] - 'A' + 10;
			else if (it[i + k] >= 'a' && it[i + k] <= 'f')
				res += it[i + k] - 'a' + 10;
			else
				res += it[i + k] - '0';
			res = res << 4;
		}
	}
	else
		res = 0xFFFFFF;
	return (res);
}

int					free_all(char **line, char ***tmp, int fd)
{
	if (line)
		ft_strdel(line);
	if (tmp)
		ft_strsdel(tmp);
	if (fd > 0)
		close(fd);
	return (0);
}
