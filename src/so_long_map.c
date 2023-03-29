/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:38:36 by lduthill          #+#    #+#             */
/*   Updated: 2023/03/29 14:51:53 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Read the .ber file with get_next_line and set the width and height of the map

int	size_of_map(t_vars *data)
{
	int		fd;

	fd = open("map/map_01.ber", O_RDONLY);
	data->width = ft_strlen(get_next_line(fd)) - 1;
	data->height = 1;
	while (get_next_line(fd))
		data->height++;
    if (data->width < 3 || data->height < 3)
        return (0);
    return (1);
}

// Print the map in a 2D array

void    print_map(t_vars *data)
{
    int    fd;
    int     x;
    int     y;
    char    *line;

    line = "0";
    fd = open("map/map_01.ber", O_RDONLY);
    while (line != NULL)
    {
        x = 0;
        line = get_next_line(fd);
        if (line == NULL)
            break ;
        while (line[x])
        {
            data->map[y][x] = line[x];
            x++;
        }
        y++;        
    }
}

// Verify if the map have a exit, a player and at least one collectible and the map is surrounded by walls


// Check errors in the map

int		check_map(t_vars **map)
{
    int		i;
    
    while (t_vars->map)
    {
        i = 0;
        if (vars.map[i] != '1' && vars.map[i] != '0' && vars.map[i] != 'C' && vars.map[i] != 'E' && vars.map[i] != 'P' && vars.map[i] != '\n')
            return (0);
        i++;
    }
    return (1);
}

