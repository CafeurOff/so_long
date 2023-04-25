/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:41:53 by lduthill          #+#    #+#             */
/*   Updated: 2023/04/25 11:56:20 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	// files and args verification
	if (argc != 2)
		return (ft_printf("Error: Map no advise"));
	if (ft_checkfile(argv[1]) == 0)
		return (ft_printf("Error: Map is not .ber file"));
	if (size_of_map(&vars, argv) == 1)
		return (ft_printf("Error: Map is not rectangular"));
	// Print the map in a 2d array
	malloc_tab(&vars, argv);
	// Map verification
	if (check_walls(&vars) == 1)
		return (ft_printf("Error: Leak in the shape"));
	if (check_collectable(&vars) == 1)
		return (ft_printf("Error: Collectables maps"));
	player_pos(&vars);
	if (vars.nb_collect != 0)
		return (ft_printf("Error: Parsing error -> E or C not reachable"));
	// Open frame and hook event
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.width * 64,
			vars.height * 64, "So Long !");
	mlx_hook(vars.win, 2, 1, &key_controls, &vars);
	mlx_hook(vars.win, 17, 1, close_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
