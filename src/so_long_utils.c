/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:53:11 by lduthill          #+#    #+#             */
/*   Updated: 2023/06/06 10:53:39 by lduthill         ###   ########.fr       */
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

// Print error and free all the data

char	ft_errors(char *c, t_vars *data)
{
	ft_printf("%s", c);
	ft_free(data);
	exit(0);
	return (0);
}

// Close and free all the data

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

// Print count of mouvement in the window

void	print_mouvement(t_vars *data)
{
	char	*str;

	str = ft_itoa(data->nb_mouvement);
	mlx_set_font(data->mlx, data->win, "-sony-*-*-*-*-*-24-230-*-*-*-*-*-1");
	mlx_string_put(data->mlx, data->win, data->width,
		data->height + 20, 0x00FFFFFF, "Vos mouvements :");
	mlx_string_put(data->mlx, data->win, data->width + 200,
		data->height + 21, 0x00FFFFFF, str);
	free(str);
}
