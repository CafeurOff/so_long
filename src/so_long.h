/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:52:27 by lduthill          #+#    #+#             */
/*   Updated: 2023/04/25 11:52:21 by lduthill         ###   ########.fr       */
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

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	char	**map2;
	int		height;
	int		width;
	int		collectables;
	int		exit;
	int		player;
	int		player_x;
	int		player_y;
	int		nb_collect;
}				t_vars;

int		check_walls(t_vars *data);
int		check_collectable(t_vars *data);
int		ft_checkfile(char *t);
int		size_of_map(t_vars *data, char **file);
int		handle_keypress(int keysym, t_vars *data);
void	malloc_tab(t_vars *data, char **file);
void	player_pos(t_vars *data);
void	parsing_map(t_vars *data, int x, int y);
void	ft_free(t_vars *data);
int		key_controls(int keycode, t_vars *data);
int		close_window(t_vars *data);

#endif
