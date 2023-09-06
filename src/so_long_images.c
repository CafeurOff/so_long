/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:25:09 by lduthill          #+#    #+#             */
/*   Updated: 2023/09/06 14:51:17 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	Here, we have a function to put the image in the window
*/

int	put_img(t_vars *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height) // While the height is not reached
	{
		x = 0;
		while (x < data->width) // While the width is not reached
		{
			print_mouvement(data); // We print the number of mouvement
			put_img_2(data, y, x); // We put the image in the window 2 function for the norm
			x++;
		}
		y++;
	}
	return (0);
}

int	put_img_2(t_vars *data, int y, int x)
{
	if (data->map[y][x] == '1') // We put the image of walls in the window
		mlx_put_image_to_window(data->mlx, data->win, data->img_walls,
			x * 64, y * 64); 
	if (data->map[y][x] == '0') // We put the image of road in the window
		mlx_put_image_to_window(data->mlx, data->win, data->img_road,
			x * 64, y * 64);
	if (data->map[y][x] == 'E') // We put the image of exit in the window
		mlx_put_image_to_window(data->mlx, data->win, data->img_exit,
			x * 64, y * 64);
	if (data->map[y][x] == 'C') // We put the image of collectable in the window
		mlx_put_image_to_window(data->mlx, data->win, data->img_collec,
			x * 64, y * 64);
	if (data->map[y][x] == 'P') // We put the image of player in the window
		mlx_put_image_to_window(data->mlx, data->win, data->img_charac,
			x * 64, y * 64);
	if (data->map[y][x] == 'F') // We put the image of player on the exit in the window
		mlx_put_image_to_window(data->mlx, data->win, data->img_pc,
			x * 64, y * 64);
	return (0);
}

/*
	Here, we have a function to load the textures for mlx
*/

void	init_xpm(t_vars *data)
{
	int	img_w;
	int	img_h;

	img_w = 64; // We initialize the width of the image to 64
	img_h = 64; // We initialize the height of the image to 64
	data->img_walls = mlx_xpm_file_to_image(data->mlx, "img/wall.xpm",
			&img_w, &img_h); // We load the image of walls
	data->img_road = mlx_xpm_file_to_image(data->mlx, "img/road.xpm",
			&img_w, &img_h); // We load the image of road
	data->img_exit = mlx_xpm_file_to_image(data->mlx, "img/exit.xpm",
			&img_w, &img_h); // We load the image of exit
	data->img_collec = mlx_xpm_file_to_image(data->mlx, "img/collectables.xpm",
			&img_w, &img_h); // We load the image of collectable
	data->img_charac = mlx_xpm_file_to_image(data->mlx, "img/charac.xpm",
			&img_w, &img_h); // We load the image of player
	data->img_pc = mlx_xpm_file_to_image(data->mlx, "img/pc.xpm",
			&img_w, &img_h); // We load the image of player on the exit
}

/*
	Here, we have a two libft functions for convert a int to a string and reverse it for print the number of mouvement
*/


char	*ft_strrev(char *str, int a, int n, int num)
{
	while (num >= 0)
	{
		str[num] = (a * (n % 10)) + 48;
		n /= 10;
		num--;
	}
	if (a == -1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		num;
	int		a;
	int		len;

	a = 1;
	len = 1;
	if (n < 0)
	{
		len = 2;
		a = -1;
	}
	num = n;
	while (num / 10 != 0)
	{
		num /= 10;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	num = len - 1;
	str = ft_strrev(str, a, n, num);
	return (str);
}
