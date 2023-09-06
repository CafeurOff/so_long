/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:52:27 by lduthill          #+#    #+#             */
/*   Updated: 2023/09/06 14:40:58 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../mlx/mlx.h"
# include "../printf/ft_printf.h"
# include "../gnl/get_next_line.h"
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_vars // Struct for storing all the data
{
	void	*mlx; // Pointer to the connection to the display server
	void	*win; // Pointer to the created window
	void	*img_walls; // Pointer to the image of the walls
	void	*img_ground; // Pointer to the image of the ground
	void	*img_road; // Pointer to the image of the road
	void	*img_exit; // Pointer to the image of the exit
	void	*img_collec; // Pointer to the image of the collectables
	void	*img_charac; // Pointer to the image of the character
	void	*img_pc; // Pointer to the image of the character on exit 
	char	**map; // Map in a double array
	char	**map2; // Copy of map1 in a double array
	int		height; // Height of the map
	int		width; // Width of the map
	int		collectables; // Number of collectables
	int		exit; // Number of exits
	int		player; // Number of players
	int		player_x; // X position of the player
	int		player_y; // Y position of the player
	int		nb_collect; // Number of collectables collected
	int		nb_mouvement; // Number of mouvement
}				t_vars;

void	check_collectable(t_vars *data); // Check if map contains collectables
void	mlx_render(t_vars data); // Render the map
void	malloc_tab(t_vars *data, char **file); // Malloc the map
void	player_pos(t_vars *data); // Get the position of the player
void	parsing_map(t_vars *data, int x, int y); // Parse the map
void	ft_free(t_vars *data); // Free the map
void	init_xpm(t_vars *data); // Init the images
void	print_mouvement(t_vars *data); // Print the number of mouvement
int		check_letters(t_vars *data); // Check if map contains only valid letters
int		put_img(t_vars *data); // Put the images on the screen
int		put_img_2(t_vars *data, int y, int x); // Put the images on the screen (2 functions for norm)
int		player_mouvement_y(t_vars *data, int mouv); // Handle the mouvement of the player
int		player_mouvement_x(t_vars *data, int mouv); // Handle the mouvement of the player
int		key_controls(int keycode, t_vars *data); // Handle the key controls
int		close_window(t_vars *data); // Handle the close window
int		ft_checkfile(char *t); // Check if the file is valid
int		size_of_map(t_vars *data, char **file); // Get the size of the map
int		handle_keypress(int keysym, t_vars *data); // Handle the key press
int		endgame(t_vars *data); // Handle the end of the game
int		check_walls(t_vars *data); // Check if map contains walls
char	ft_errors(char *c, t_vars *data); // Handle the errors
char	*ft_strrev(char *str, int a, int n, int num); // Reverse a string
char	*ft_itoa(int n); // Convert an int to a string

#endif
