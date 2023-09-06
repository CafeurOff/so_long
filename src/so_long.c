/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:41:53 by lduthill          #+#    #+#             */
/*   Updated: 2023/09/06 14:37:36 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_render(t_vars data)
{
	data.mlx = mlx_init(); // Initialize mlx and create a window
	data.win = mlx_new_window(data.mlx, data.width * 64,
			data.height * 64 + 20, "So Long !"); // Initialize mlx frame with the size of the map and title
	init_xpm(&data); // Initialize my function to load textures
	mlx_loop_hook(data.mlx, &put_img, &data); // Loop to put the image
	mlx_hook(data.win, 2, 1, &key_controls, &data); // Hook to control the player
	mlx_hook(data.win, 17, 1, close_window, &data); // Hook to close the window
	mlx_loop(data.mlx); // Loop to keep the window open
}

int	main(int argc, char **argv)
{
	t_vars	data; // Create a structure to store all the data

	data.nb_mouvement = 0; // Initialize the number of mouvement to 0
	if (argc != 2)
		return (ft_printf("Error\n Map no advise")); // Check if the number of arguments is correct
	if (ft_checkfile(argv[1]) == 0)
		return (ft_printf("Error\n Map is not .ber file")); // Check if the file is a .ber file
	if (size_of_map(&data, argv) == 1)
		return (ft_printf("Error\n Map is not valid")); // Check if the map is valid
	malloc_tab(&data, argv);
	if (check_walls(&data) == 1)
		ft_errors("Error\n Map is not surrounded by walls", &data); // Check if the map is surrounded by walls
	check_collectable(&data); // Check if there is at least one collectable
	player_pos(&data); // Check if there is only one player
	if (check_letters(&data) == 1)
		ft_errors("Error\n Other letters in your map", &data); // Check if there is only P, E, C and 1
	if (data.nb_collect != 0)
	{
		ft_free(&data);
		return (ft_printf("Error\n Parsing error -> E or C not reachable")); // Check if the exit and collectable are reachable
	}
	if (data.collectables <= 0 || data.exit != 1 || data.player != 1)
		ft_errors("Error\n Missing E, C or P", &data); // Check if there is at least one exit, one collectable and one player
	mlx_render(data); // Render the game
	return (0);
}
