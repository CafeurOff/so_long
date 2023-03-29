/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:59:56 by lduthill          #+#    #+#             */
/*   Updated: 2023/03/17 14:35:05 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found(t_list *str)
{
	int		i;
	t_list	*current;

	if (str == NULL)
		return (0);
	current = ft_lst_get_last(str);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// Return a pointer to the last char in my static

t_list	*ft_lst_get_last(t_list *str)
{
	t_list	*current;

	current = str;
	while (current && current->next)
		current = current->next;
	return (current);
}

void	generate(char **line, t_list *str)
{
	int	i;
	int	len;

	len = 0;
	while (str)
	{
		i = 0;
		while (str->content[i])
		{
			if (str->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		str = str->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

void	free_static(t_list *str)
{
	t_list	*current;
	t_list	*next;

	current = str;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

int	lenght(const char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}
