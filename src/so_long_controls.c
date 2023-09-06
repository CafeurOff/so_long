/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_controls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:49:50 by lduthill          #+#    #+#             */
/*   Updated: 2023/06/06 10:53:24 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_controls(int keycode, t_vars *data)
{
	if (keycode == XK_Escape)
		close_window(data);
	if (keycode == XK_w)
		data->nb_mouvement += player_mouvement_y(data, -1);
	if (keycode == XK_s)
		data->nb_mouvement += player_mouvement_y(data, 1);
	if (keycode == XK_a)
		data->nb_mouvement += player_mouvement_x(data, -1);
	if (keycode == XK_d)
		data->nb_mouvement += player_mouvement_x(data, 1);
	endgame(data);
	return (data->nb_mouvement);
}

int	player_mouvement_y(t_vars *data, int mouv)
{
	if (data->map[data->player_y + mouv][data->player_x] != '1')
	{
		if (data->map[data->player_y + mouv][data->player_x] == 'C')
			data->collectables -= 1;
		if (data->map[data->player_y][data->player_x] == 'F')
			data->map[data->player_y][data->player_x] = 'E';
		else
			data->map[data->player_y][data->player_x] = '0';
		data->player_y += mouv;
		if (data->map[data->player_y][data->player_x] == 'E')
			data->map[data->player_y][data->player_x] = 'F';
		else
			data->map[data->player_y][data->player_x] = 'P';
		return (1);
	}
	return (0);
}

int	player_mouvement_x(t_vars *data, int mouv)
{
	if (data->map[data->player_y][data->player_x + mouv] != '1')
	{
		if (data->map[data->player_y][data->player_x + mouv] == 'C')
			data->collectables -= 1;
		if (data->map[data->player_y][data->player_x] == 'F')
			data->map[data->player_y][data->player_x] = 'E';
		else
			data->map[data->player_y][data->player_x] = '0';
		data->player_x += mouv;
		if (data->map[data->player_y][data->player_x] == 'E')
			data->map[data->player_y][data->player_x] = 'F';
		else
			data->map[data->player_y][data->player_x] = 'P';
		return (1);
	}
	return (0);
}

// End the game and close and free all mlx call

int	endgame(t_vars *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->height)
	{
		while (x < data->width)
		{
			if (data->collectables == 0 && \
					data->map[data->player_y][data->player_x] == 'F')
			{
				ft_printf("THE END\n");
				close_window(data);
				return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
