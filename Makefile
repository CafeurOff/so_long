# so_long - A simple 2D game
# Use this makefile to compile to game

# Compile informations
NAME		=	so_long
SANIFLAG	=	-g
FLAGS		=	-Wall -Wextra -Werror $(SANIFLAG)

# This works only when mlx is loaded into the env (on school computers)

# This MLX_INCLUDE is for MacOS
MLX_INCLUDE =	-Lmlx/ -lmlx -L/usr/lib/ -lXext -lX11 -lm -I ./ -I ./mlx/

# This is all the source files we want to compile
SRC_FOLDER	=	src/
SRC_FILES	=	so_long.c so_long_map.c so_long_utils.c so_long_check_map.c so_long_controls.c 
OBJS		=	$(addprefix $(SRC_FOLDER), $(SRC_FILES:%.c=%.o))

# This is other projects we want to include to our source files
GNL_PATH	=	gnl/
GNL_LIB		= 	$(GNL_PATH)get_next_line.a
PRINTF_PATH =	printf/
PRINTF_LIB	=	$(PRINTF_PATH)libftprintf.a

#Some colors
RED			=	\033[0;31m
GREEN		=	\033[0;32m	

# Our compile rules
%.o: %.c
	gcc $(FLAGS) -c $< -o $@

$(NAME): 	$(OBJS)
	@echo "$(GREEN)Compiling $(NAME)..."
	make -C $(GNL_PATH)
	make -C $(PRINTF_PATH)
	gcc $(FLAGS) $(OBJS) $(GNL_LIB) $(PRINTF_LIB) $(MLX_INCLUDE) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully!"

# Here are mandatory rules
all:		$(NAME)

clean:
	@echo "$(RED)Cleaning $(NAME)..."
	rm -rf $(OBJS)
	make clean -C $(GNL_PATH)
	make clean -C $(PRINTF_PATH)
	@echo "$(RED)$(NAME) cleaned successfully!"

fclean:		clean
	@echo "$(RED)Cleaning $(NAME)..."
	rm -f $(NAME)
	make fclean -C $(GNL_PATH)
	make fclean -C $(PRINTF_PATH)
	@echo "$(RED)$(NAME) cleaned successfully!"

re:			fclean all

.PHONY:		all clean fclean re
