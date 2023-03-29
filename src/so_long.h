#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../mlx/mlx.h"
# include "../printf/ft_printf.h"
# include "../gnl/get_next_line.h"
# include <fcntl.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	int		height;
	int		width;
	int		x;
	int		y;
}				t_vars;

char	ft_strdup(char *s1);
int	size_of_map(t_vars *data);
int		check_map(t_vars *map);
int     check_arround(t_vars *data);
void	print_map(t_vars *data);

#endif
