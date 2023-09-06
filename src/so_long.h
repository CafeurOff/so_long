/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:52:27 by lduthill          #+#    #+#             */
/*   Updated: 2023/05/23 10:49:11 by lduthill         ###   ########.fr       */
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
	void	*img_walls;
	void	*img_ground;
	void	*img_road;
	void	*img_exit;
	void	*img_collec;
	void	*img_charac;
	void	*img_pc;
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
	int		nb_mouvement;
}				t_vars;

void	check_collectable(t_vars *data);
void	mlx_render(t_vars data);
void	malloc_tab(t_vars *data, char **file);
void	player_pos(t_vars *data);
void	parsing_map(t_vars *data, int x, int y);
void	ft_free(t_vars *data);
void	init_xpm(t_vars *data);
void	print_mouvement(t_vars *data);
int		check_letters(t_vars *data);
int		put_img(t_vars *data);
int		put_img_2(t_vars *data, int y, int x);
int		player_mouvement_y(t_vars *data, int mouv);
int		player_mouvement_x(t_vars *data, int mouv);
int		key_controls(int keycode, t_vars *data);
int		close_window(t_vars *data);
int		ft_checkfile(char *t);
int		size_of_map(t_vars *data, char **file);
int		handle_keypress(int keysym, t_vars *data);
int		endgame(t_vars *data);
int		check_walls(t_vars *data);
char	ft_errors(char *c, t_vars *data);
char	*ft_strrev(char *str, int a, int n, int num);
char	*ft_itoa(int n);

#endif
