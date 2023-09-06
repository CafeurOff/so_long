/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:53:11 by lduthill          #+#    #+#             */
/*   Updated: 2023/09/06 14:45:30 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	Here, we have a function to check if the file is a .ber file
*/
int	ft_checkfile(char *t)
{
	int		i;
	int		j;
	char	*l;

	i = 0;
	j = ft_strlen(t) - 1;
	l = "reb."; // We compare the last 4 characters of the file with "reb."
	while (j > 0 && l[i])
	{
		if (t[j--] != l[i++]) // If the characters are not the same, we return 0
			return (0);
	}
	return (1); // Else, we return 1
}

/*
	Here, we have a function to get the position of the player and parse the map
*/

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
				data->player_x = x; // We get the x position of the player
				data->player_y = y; // We get the y position of the player
				parsing_map(data, data->player_x, data->player_y); // We parse the map
				return ; 
			}
			x++;
		}
		y++;
	}
}

/* 
	Here, we have a function for print a error message and free all the data
*/

char	ft_errors(char *c, t_vars *data)
{
	ft_printf("%s", c); // Print the error message
	ft_free(data); // Free all the data
	exit(0); // Exit the program
	return (0);
}

/* 
	Here we have a function to close the window and free all the data
*/

int	close_window(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img_walls); // Destroy the wall texture
	mlx_destroy_image(vars->mlx, vars->img_road); // Destroy the road texture
	mlx_destroy_image(vars->mlx, vars->img_exit); // Destroy the exit texture
	mlx_destroy_image(vars->mlx, vars->img_collec); // Destroy the collectable texture
	mlx_destroy_image(vars->mlx, vars->img_charac); // Destroy the player texture
	mlx_destroy_image(vars->mlx, vars->img_pc); // Destroy the player texture
	mlx_destroy_window(vars->mlx, vars->win); // Destroy the window
	mlx_destroy_display(vars->mlx); // Destroy the display
	ft_free(vars); // Free all the data
	free(vars->mlx); // Free the mlx
	exit(0);
	return (0);
}

/*
	Here we have a function to print the number of mouvement on the screen 
*/

void	print_mouvement(t_vars *data)
{
	char	*str;

	str = ft_itoa(data->nb_mouvement); // We convert the number of mouvement to a string
	mlx_set_font(data->mlx, data->win, "-sony-*-*-*-*-*-24-230-*-*-*-*-*-1"); // We set the font
	mlx_string_put(data->mlx, data->win, data->width, 
		data->height + 20, 0x00FFFFFF, "Vos mouvements :"); // We print the text
	mlx_string_put(data->mlx, data->win, data->width + 200,
		data->height + 21, 0x00FFFFFF, str); // We print the number of mouvement
	free(str); // We free the string
}
