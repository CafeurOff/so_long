/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:49:29 by lduthill          #+#    #+#             */
/*   Updated: 2023/03/29 12:35:55 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Check if arround the player there is a wall

int     check_arround(t_vars *data)
{
    int     i;
    int     x;
    int     y;

    x = 0;
    y = 0;
    i = 0;
    while (data->map)
    {  
        while (data->map[y][x] != '\0')
        {
            if (data->map[y][x] == 'P')
            {
              if (data->map[y - 1][x] == '1' && data->map[y + 1][x] == '1' && data->map[y][x + 1] == '1' && data->map[y][x - 1] == '1')
                 return (0);
            }
            x++;
        }
        y++;
    }
    return (1);
}
// ft_strdup is a function from libft

char	*ft_strdup(char *s1)
{
    char	*str;
    int		i;

    i = 0;
    str = malloc(sizeof(char) * (ft_strlen(s1) + 1));
    if (!str)
        return (NULL);
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
