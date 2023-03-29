/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:57:31 by lduthill          #+#    #+#             */
/*   Updated: 2023/03/17 14:42:40 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*str = NULL;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	readline(fd, &str);
	if (str == NULL)
		return (NULL);
	print(str, &line);
	clean(&str);
	if (line[0] == '\0')
	{
		free_static(str);
		str = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

void	readline(int fd, t_list **str)
{
	char	*buff;
	int		readed;

	readed = 1;
	while (!found(*str) && readed != 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return ;
		readed = (int)read(fd, buff, BUFFER_SIZE);
		if ((*str == NULL && readed == 0) || readed == -1)
		{
			free(buff);
			return ;
		}
		buff[readed] = '\0';
		add(str, buff, readed);
		free(buff);
	}
}

void	add(t_list **str, char *buff, int readed)
{
	int		i;
	t_list	*last;
	t_list	*new_value;

	i = 0;
	new_value = malloc(sizeof(t_list));
	if (!new_value)
		return ;
	new_value->next = NULL;
	new_value->content = malloc(sizeof(char) * (readed + 1));
	if (new_value->content == NULL)
		return ;
	while (buff[i] && i < readed)
	{
		new_value->content[i] = buff[i];
		i++;
	}
	new_value->content[i] = '\0';
	if (*str == NULL)
	{
		*str = new_value;
		return ;
	}
	last = ft_lst_get_last(*str);
	last->next = new_value;
}

void	print(t_list *str, char **line)
{
	int	i;
	int	j;

	j = 0;
	if (str == NULL)
		return ;
	generate(line, str);
	if (!line)
		return ;
	while (str)
	{
		i = 0;
		while (str->content[i])
		{
			if (str->content[i] == '\n')
			{
				(*line)[j++] = str->content[i];
				break ;
			}
			(*line)[j++] = str->content[i++];
		}
		str = str->next;
	}
	(*line)[j] = '\0';
}

void	clean(t_list **str)
{
	t_list	*last;
	t_list	*clean;
	int		i;
	int		j;

	clean = malloc(sizeof(t_list));
	if (str == NULL || clean == NULL)
		return ;
	clean->next = NULL;
	last = ft_lst_get_last(*str);
	i = 0;
	j = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean->content = malloc(sizeof(char) * ((lenght(last->content) - i) + 1));
	if (!clean->content)
		return ;
	while (last->content[i])
		clean->content[j++] = last->content[i++];
	clean->content[j] = '\0';
	free_static(*str);
	*str = clean;
}
