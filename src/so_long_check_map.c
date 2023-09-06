/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:13:19 by lduthill          #+#    #+#             */
/*   Updated: 2023/09/06 14:58:37 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	Here, we have a function to check if the map is sourrounded by walls
*/
*/

int	check_walls(t_vars *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->height) // While the height is not reached
	{
		if (y == 0 || y == x) // If the y is 0 or the y is the height
		{
			while (x < data->width)
			{
				if (data->map[y][x] != '1') // If the map is not sourrounded by walls, we return 1
					return (1);
				x++;
			}
		}
		else
		{
			if (data->map[y][0] != '1' || data->map[y][data->width - 1] != '1') // If the map is not sourrounded by walls, we return 1
				return (1);
		}
		y++;
	}
	return (0); // Else, we return 0
}

/*
	Here, we have a function to check if the map has a player, an exit and collectables
*/

void	check_collectable(t_vars *data)
{
	int	x;
	int	y;

	data->collectables = 0; // We initialize the number of collectables to 0
	data->exit = 0; // We initialize the number of exit to 0
	data->player = 0; // We initialize the number of player to 0
	y = 0;
	while (y < data->height) // While the height is not reached
	{
		x = 0;
		while (x < data->width) // While the width is not reached
		{
			if (data->map[y][x] == 'C') // If the map has a collectable, we add one to the number of collectables
				data->collectables++; 
			if (data->map[y][x] == 'E') // If the map has a exit, we add one to the number of exit
				data->exit++;
			if (data->map[y][x] == 'P') // If the map has a player, we add one to the number of player
				data->player++;
			x++;
		}
		y++;
	}
	data->nb_collect = data->collectables + 1; // We initialize the number of collectables to the number of collectables + 1
}

/*
	Here, we have a function to parse the map, and check if the map is finishable or not
*/

void	parsing_map(t_vars *data, int x, int y)
{
	if (data->map2[y][x] == '1' || data->map2[y][x] == 'X' ||
			data->nb_collect == 0) // If the map has a wall, a X or the number of collectables is 0, we return
		return ;
	if (data->map2[y][x] == 'C' || data->map2[y][x] == 'E') // If the map has a collectable or a exit
	{
		data->map2[y][x] = 'X'; // We put a X
		data->nb_collect--; // We remove one collectable
	}
	else
		data->map2[y][x] = 'X'; // Else, we put a X
	parsing_map(data, x + 1, y); // We recursive the function for check the next position
	parsing_map(data, x - 1, y); 
	parsing_map(data, x, y + 1);
	parsing_map(data, x, y - 1);
}

/*
	Here, we have a function to check if the map has only 0, 1, P, E and C
*/

int	check_letters(t_vars *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height) // While the height is not reached
	{
		x = 0;
		while (x < data->width) // While the width is not reached
		{
			if (!(data->map[y][x] == '0' || data->map[y][x] == '1'
					|| data->map[y][x] == 'P' || data->map[y][x] == 'E'
					|| data->map[y][x] == 'C')) // If the map has not only 0, 1, P, E and C, we return 1
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
