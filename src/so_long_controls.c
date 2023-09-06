/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_controls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:49:50 by lduthill          #+#    #+#             */
/*   Updated: 2023/09/06 14:54:28 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	Here, we have a function to control the player
*/

int	key_controls(int keycode, t_vars *data)
{
	if (keycode == XK_Escape) // If the key is escape, we close the window
		close_window(data);
	if (keycode == XK_w) // If the key is w, we move the player up
		data->nb_mouvement += player_mouvement_y(data, -1);
	if (keycode == XK_s) // If the key is s, we move the player down
		data->nb_mouvement += player_mouvement_y(data, 1);
	if (keycode == XK_a) // If the key is a, we move the player left
		data->nb_mouvement += player_mouvement_x(data, -1);
	if (keycode == XK_d) // If the key is d, we move the player right
		data->nb_mouvement += player_mouvement_x(data, 1);
	endgame(data); // We check if the game is finished
	return (data->nb_mouvement); // We return the number of mouvement
}

/*
	Here, we have a function to move the player on the y axis
*/

int	player_mouvement_y(t_vars *data, int mouv)
{
	if (data->map[data->player_y + mouv][data->player_x] != '1') // If the next position is not a wall
	{
		if (data->map[data->player_y + mouv][data->player_x] == 'C') // If the next position is a collectable
			data->collectables -= 1; // We remove one collectable
		if (data->map[data->player_y][data->player_x] == 'F') // If the player is on the exit
			data->map[data->player_y][data->player_x] = 'E'; // We put the exit
		else 
			data->map[data->player_y][data->player_x] = '0'; // Else, we put a road
		data->player_y += mouv; // We move the player
		if (data->map[data->player_y][data->player_x] == 'E') // If the player is on the exit with a collectable
			data->map[data->player_y][data->player_x] = 'F'; // We put the player on the exit
		else
			data->map[data->player_y][data->player_x] = 'P'; // Else, we put the player on a road
		return (1);
	}
	return (0);
}

/*
	Here, we have a function to move the player on the x axis
*/

int	player_mouvement_x(t_vars *data, int mouv)
{
	if (data->map[data->player_y][data->player_x + mouv] != '1') // If the next position is not a wall
	{
		if (data->map[data->player_y][data->player_x + mouv] == 'C') // If the next position is a collectable
			data->collectables -= 1; // We remove one collectable
		if (data->map[data->player_y][data->player_x] == 'F') // If the player is on the exit with a collectable
			data->map[data->player_y][data->player_x] = 'E'; // We put the exit
		else
			data->map[data->player_y][data->player_x] = '0'; // Else, we put a road
		data->player_x += mouv; // We move the player
		if (data->map[data->player_y][data->player_x] == 'E') // If the player is on the exit without a collectable
			data->map[data->player_y][data->player_x] = 'F'; // We put the player on the exit
		else
			data->map[data->player_y][data->player_x] = 'P'; // Else, we put the player on a road
		return (1);
	}
	return (0);
}

/*
	Here, we have a function to check if the game is finished
*/

int	endgame(t_vars *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->height) // While the height is not reached
	{
		while (x < data->width) // While the width is not reached
		{
			if (data->collectables == 0 && \
					data->map[data->player_y][data->player_x] == 'F') // If the player is on the exit and there is no collectable
			{
				ft_printf("THE END\n"); // We print the end of the game
				close_window(data); // We close the window
				return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
