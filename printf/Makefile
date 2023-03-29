# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduthill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 12:25:09 by lduthill          #+#    #+#              #
#    Updated: 2023/03/28 17:49:12 by lduthill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_printf_utils.c ft_printf_utils_2.c

OBJS = $(SRC:.c=.o)

RM = rm -f

NAME = libftprintf.a

all : $(NAME)

.c.o:
		gcc -Wall -Werror -Wextra -I ./ -c $< -o $(<:.c=.o)

$(NAME) :	$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean :
		$(RM) $(OBJS)

fclean :	clean
				$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY: all clean fclean re
