# so_long - A simple 2D game

# Compile informations
NAME		=	so_long
SANIFLAG	=	-g
FLAGS		=	-Wall -Wextra -Werror $(SANIFLAG)

# This works only when mlx is loaded into the env (on school computers)

# This MLX_INCLUDE is for MacOS
MLX_INCLUDE =	-Lmlx/ -lmlx -L/usr/lib/ -lXext -lX11 -lm -I ./ -I ./mlx/

# This is all the source files we want to compile
SRC_FOLDER	=	src/
SRC_FILES	=	so_long.c so_long_map.c so_long_utils.c so_long_check_map.c so_long_controls.c so_long_images.c
OBJS		=	$(addprefix $(SRC_FOLDER), $(SRC_FILES:%.c=%.o))

# This is other projects we want to include to our source files
GNL_PATH	=	gnl/
GNL_LIB		= 	$(GNL_PATH)get_next_line.a
PRINTF_PATH =	printf/
PRINTF_LIB	=	$(PRINTF_PATH)libftprintf.a

#Some colors
DEFAULT		=	\033[0;39m
RED			=	\033[0;31m
GREEN		=	\033[0;32m	

# Our compile rules
%.o: %.c
	@echo "$(GREEN)Compiling $<$(DEFAULT)"
	@gcc $(FLAGS) -c $< -o $@

$(NAME): 	$(OBJS)
	@make -C $(GNL_PATH) --no-print-directory -s
	@make -C $(PRINTF_PATH) --no-print-directory -s
	@gcc $(FLAGS) $(OBJS) $(GNL_LIB) $(PRINTF_LIB) $(MLX_INCLUDE) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully!$(DEFAULT)"

# Here are mandatory rules
all:		$(NAME)

clean:
	@rm -rf $(OBJS)
	@make clean -C $(GNL_PATH) --no-print-directory -s
	@make clean -C $(PRINTF_PATH) --no-print-directory -s
	@echo "$(RED)$(NAME) cleaned successfully!$(DEFAULT)"

fclean:		clean
	@rm -f $(NAME)
	@make fclean -C $(GNL_PATH) --no-print-directory -s
	@make fclean -C $(PRINTF_PATH) --no-print-directory -s
	@echo "$(RED)$(NAME) executable files cleaned!$(DEFAULT)"
	@echo "$(RED)getnextline.a cleaned!$(DEFAULT)"

re:			fclean all
			@echo "$(GREEN)$(NAME) recompiled successfully!$(DEFAULT)"

norm:
	@norminette $(SRC_FOLDER) $(GNL_PATH) $(PRINTF_PATH) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm
