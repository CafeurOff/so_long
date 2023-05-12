/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:13:19 by lduthill          #+#    #+#             */
/*   Updated: 2023/05/11 15:29:33 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Check if the map is surronded by walls

int	check_walls(t_vars *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->height)
	{
		if (y == 0 || y == x)
		{
			while (x < data->width)
			{
				if (data->map[y][x] != '1')
					return (1);
				x++;
			}
		}
		else
		{
			if (data->map[y][0] != '1' || data->map[y][data->width - 1] != '1')
				return (1);
		}
		y++;
	}
	return (0);
}

// Check if the map have one collectible, one exit and one player

void	check_collectable(t_vars *data)
{
	int	x;
	int	y;

	data->collectables = 0;
	data->exit = 0;
	data->player = 0;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x] == 'C')
				data->collectables++;
			if (data->map[y][x] == 'E')
				data->exit++;
			if (data->map[y][x] == 'P')
				data->player++;
			x++;
		}
		y++;
	}
	data->nb_collect = data->collectables + 1;
}

// Parse the map

void	parsing_map(t_vars *data, int x, int y)
{
	if (data->map2[y][x] == '1' || data->map2[y][x] == 'X' ||
			data->nb_collect == 0)
		return ;
	if (data->map2[y][x] == 'C' || data->map2[y][x] == 'E')
	{
		data->map2[y][x] = 'X';
		data->nb_collect--;
	}
	else
		data->map2[y][x] = 'X';
	parsing_map(data, x + 1, y);
	parsing_map(data, x - 1, y);
	parsing_map(data, x, y + 1);
	parsing_map(data, x, y - 1);
}
