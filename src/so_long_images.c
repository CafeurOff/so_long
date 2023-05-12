/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:25:09 by lduthill          #+#    #+#             */
/*   Updated: 2023/05/11 15:31:30 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_img(t_vars *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			put_img_2(data, y, x);
			x++;
		}
		y++;
	}
	return (0);
}

int	put_img_2(t_vars *data, int y, int x)
{
	if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img_walls,
			x * 64, y * 64);
	if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img_road,
			x * 64, y * 64);
	if (data->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img_exit,
			x * 64, y * 64);
	if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img_collec,
			x * 64, y * 64);
	if (data->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->img_charac,
			x * 64, y * 64);
	if (data->map[y][x] == 'F')
		mlx_put_image_to_window(data->mlx, data->win, data->img_pc,
			x * 64, y * 64);
	return (0);
}

// Init my xpm files

void	init_xpm(t_vars *data)
{
	int	img_w;
	int	img_h;

	img_w = 64;
	img_h = 64;
	data->img_walls = mlx_xpm_file_to_image(data->mlx, "img/wall.xpm",
			&img_w, &img_h);
	data->img_road = mlx_xpm_file_to_image(data->mlx, "img/road.xpm",
			&img_w, &img_h);
	data->img_exit = mlx_xpm_file_to_image(data->mlx, "img/exit.xpm",
			&img_w, &img_h);
	data->img_collec = mlx_xpm_file_to_image(data->mlx, "img/collectables.xpm",
			&img_w, &img_h);
	data->img_charac = mlx_xpm_file_to_image(data->mlx, "img/charac.xpm",
			&img_w, &img_h);
	data->img_pc = mlx_xpm_file_to_image(data->mlx, "img/pc.xpm",
			&img_w, &img_h);
}
