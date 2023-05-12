/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_controls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:25:11 by lduthill          #+#    #+#             */
/*   Updated: 2023/05/11 15:04:43 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_controls(int keycode, t_vars *data)
{
	if (keycode == XK_Escape)
		close_window(data);
	if (keycode == XK_Up)
		data->nb_mouvement += player_mouvement_y(data, -1);
	if (keycode == XK_Down)
		data->nb_mouvement += player_mouvement_y(data, 1);
	if (keycode == XK_Left)
		data->nb_mouvement += player_mouvement_x(data, -1);
	if (keycode == XK_Right)
		data->nb_mouvement += player_mouvement_x(data, 1);
	endgame(data);
	return (data->nb_mouvement);
}

int	close_window(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img_walls);
	mlx_destroy_image(vars->mlx, vars->img_road);
	mlx_destroy_image(vars->mlx, vars->img_exit);
	mlx_destroy_image(vars->mlx, vars->img_collec);
	mlx_destroy_image(vars->mlx, vars->img_charac);
	mlx_destroy_image(vars->mlx, vars->img_pc);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	ft_free(vars);
	free(vars->mlx);
	exit(0);
	return (0);
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
