/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_check_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 22:41:15 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/06 02:51:39 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int inline	check_color(char **line, int const i, int const j)
{
	int	k;

	k = -1;
	while (++k < 6)
		if (!line[i][j + k] ||
			!((line[i][j + k] >= '0' && line[i][j + k] <= '9') ||
			(line[i][j + k] >= 'A' && line[i][j + k] <= 'F') ||
			(line[i][j + k] >= 'a' && line[i][j + k] <= 'f')))
			return (1);
	if (line[i][j + k])
		return (1);
	return (0);
}

int					check_line_valid(char **line)
{
	int	i;
	int	j;

	i = -1;
	while (line[++i])
	{
		j = (line[i][0] == '-' ? 1 : 0);
		while (ft_isdigit(line[i][j]))
			++j;
		if (line[i][j] == ',')
		{
			if ((!line[i][++j] && line[i][j] != '0') ||
				(line[i][j + 1] &&
				(line[i][j + 1] != 'X' && line[i][j + 1] != 'x')))
				return (0);
			j += 2;
			if (check_color(line, i, j))
				return (0);
		}
		else if (line[i][j])
			return (0);
	}
	return (i);
}
