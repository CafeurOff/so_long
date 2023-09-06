/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:25:09 by lduthill          #+#    #+#             */
/*   Updated: 2023/05/23 10:50:53 by lduthill         ###   ########.fr       */
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
			print_mouvement(data);
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

// Use strrev & itoa from libft for print count of mouvement in the window

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
