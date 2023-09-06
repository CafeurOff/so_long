/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:50:02 by lduthill          #+#    #+#             */
/*   Updated: 2023/09/06 14:48:28 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	Here, we have a function for get the size of the map with get_next_line and store it in a structure
*/

int	size_of_map(t_vars *data, char **file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file[1], O_RDONLY); // We open the file
	if (fd == -1) // If the file doesn't exist, we return 1
		return (1);
	line = get_next_line(fd); // We get the first line of the map
	if (line == NULL) // If the file is empty, we return 1
		return (1);
	data->width = ft_strlen(line) - 1; // We get the width of the map
	data->height = 0; // We initialize the height of the map to 0
	while (line) // While the line is not empty
	{
		data->height++;
		if ((int)ft_strlen(line) - 1 != data->width) // If the width of the line is not the same as the first line, we return 1
			i = 1;
		free(line);
		line = get_next_line(fd); // We get the next line
	}
	close(fd);
	return (i);
}

/*
	Here, we have a function for malloc my map1 and the copy of my map1 (map2) with get_next_line and store it in a structure
*/

void	malloc_tab(t_vars *data, char **file)
{
	int		i;
	int		fd;

	fd = open(file[1], O_RDONLY); // We open the file
	i = 0;
	data->map = malloc(sizeof(char **) * data->height); // We malloc the map
	data->map2 = malloc(sizeof(char **) * data->height); // We malloc the copy of the map
	while (i < data->height) // While the height is not reached
	{
		data->map[i] = get_next_line(fd); // We get the line of the map
		i++;
	}
	free(get_next_line(fd)); // We free the last line
	close(fd);
	fd = open(file[1], O_RDONLY); 
	i = 0;
	while (i < data->height)
	{
		data->map2[i] = get_next_line(fd);
		i++;
	}
	free(get_next_line(fd));
	close(fd);
}

/*
	Here, we have a function for free all the data and the map
*/

void	ft_free(t_vars *data)
{
	int	i;

	i = 0;
	while (i < data->height) // While the height is not reached
	{
		free(data->map[i]); // We free the line of the map
		free(data->map2[i]); // We free the line of the copy of the map
		i++;
	}
	free(data->map); // We free the map
	free(data->map2); // We free the copy of the map
}
