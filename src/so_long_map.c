/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:38:36 by lduthill          #+#    #+#             */
/*   Updated: 2023/04/25 11:51:46 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Read the .ber file with get_next_line and set the width and height of the map

int	size_of_map(t_vars *data, char **file)
{
	int		fd;
	char	*line;

	fd = open(file[1], O_RDONLY);
	line = get_next_line(fd);
	data->width = ft_strlen(line);
	data->height = 0;
	while (line)
	{
		data->height++;
		if ((int)ft_strlen(line) != data->width)
		{
			close(fd);
			ft_free(data);
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

// Get the map and allocate his memory

void	malloc_tab(t_vars *data, char **file)
{
	int		i;
	int		fd;

	fd = open(file[1], O_RDONLY);
	i = 0;
	data->map = malloc(sizeof(char **) * data->height);
	data->map2 = malloc(sizeof(char **) * data->height);
	while (i < data->height)
	{
		data->map[i] = get_next_line(fd);
		i++;
		ft_printf("%s", data->map[i - 1]);
	}
	free(get_next_line(fd));
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

void	ft_free(t_vars *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->map[i]);
		free(data->map2[i]);
		i++;
	}
	free(data->map);
	free(data->map2);
}
