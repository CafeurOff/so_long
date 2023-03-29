/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:56:25 by lduthill          #+#    #+#             */
/*   Updated: 2023/03/17 14:58:28 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		found(t_list *str);
t_list	*ft_lst_get_last(t_list *str);
void	readline(int fd, t_list **str);
void	add(t_list **str, char *buff, int readed);
void	print(t_list *str, char **line);
void	generate(char **line, t_list *str);
void	clean(t_list **str);
int		lenght(const char *str);
void	free_static(t_list *str);

#endif
