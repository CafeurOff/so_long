/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:41:53 by lduthill          #+#    #+#             */
/*   Updated: 2023/05/22 17:53:48 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_render(t_vars data)
{
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.width * 64,
			data.height * 64 + 20, "So Long !");
	init_xpm(&data);
	mlx_loop_hook(data.mlx, &put_img, &data);
	mlx_hook(data.win, 2, 1, &key_controls, &data);
	mlx_hook(data.win, 17, 1, close_window, &data);
	mlx_loop(data.mlx);
}

int	main(int argc, char **argv)
{
	t_vars	data;

	data.nb_mouvement = 0;
	if (argc != 2)
		return (ft_printf("Error\n Map no advise"));
	if (ft_checkfile(argv[1]) == 0)
		return (ft_printf("Error\n Map is not .ber file"));
	if (size_of_map(&data, argv) == 1)
		return (ft_printf("Error\n Map is not valid"));
	malloc_tab(&data, argv);
	if (check_walls(&data) == 1)
		ft_errors("Error\n Map is not surrounded by walls", &data);
	check_collectable(&data);
	player_pos(&data);
	if (check_letters(&data) == 1)
		ft_errors("Error\n Other letters in your map", &data);
	if (data.nb_collect != 0)
	{
		ft_free(&data);
		return (ft_printf("Error\n Parsing error -> E or C not reachable"));
	}
	if (data.collectables <= 0 || data.exit != 1 || data.player != 1)
		ft_errors("Error\n Missing E, C or P", &data);
	mlx_render(data);
	return (0);
}
