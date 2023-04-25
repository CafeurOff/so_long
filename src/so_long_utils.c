/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:49:29 by lduthill          #+#    #+#             */
/*   Updated: 2023/04/25 11:51:12 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Check if the map is a .ber

int	ft_checkfile(char *t)
{
	int		i;
	int		j;
	char	*l;

	i = 0;
	j = ft_strlen(t) - 1;
	l = "reb.";
	while (j > 0 && l[i])
	{
		if (t[j--] != l[i++])
			return (0);
	}
	return (1);
}

// Get position x and y of player

void	player_pos(t_vars *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
				parsing_map(data, data->player_x, data->player_y);
				return ;
			}
			x++;
		}
		y++;
	}
}
