# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/27 17:50:35 by qmennen           #+#    #+#              #
#    Updated: 2025/03/27 19:03:44 by qmennen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	cc
CCFLAG		=	-Wall -Wextra -Werror -Wundef -fsanitize=address,undefined

LIB_MLX		=	./lib/MLX42

HDR_DIR		=	./includes/

LIB_MLX_HDR	=	$(LIB_MLX)/include

LIBS	:= $(LIB_MLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRC_DIR		=	./src/
SRC_FILE	=	main.c window.c log.c game.c hooks.c

SOURCES		=	$(addprefix $(SRC_DIR), $(SRC_FILE))

OBJ_DIR		=	./obj/
OBJ_FILE	=	$(patsubst %.c, %.o, $(SRC_FILE))
OBJECTS		=	$(addprefix $(OBJ_DIR), $(OBJ_FILE))

GREEN		=	\033[0;92m
RESET		=	\033[0m
RED 		=	\033[31m

all			:	libmlx $(NAME)

run			:	all
		./$(NAME)

libmlx		:
		@cmake $(LIB_MLX) -B $(LIB_MLX)/build && make -C $(LIB_MLX)/build -j4

$(NAME)		:	$(OBJ_DIR) $(OBJECTS)
		$(CC) $(CCFLAG) $(OBJECTS) $(LIBS) -I$(HDR_DIR) -I$(LIB_MLX_HDR) -o $(NAME)
		@echo "$(GREEN)* $(NAME) program file was created *$(RESET)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
		@$(CC) $(CCFLAG) -I$(HDR_DIR) -I$(LIB_MLX_HDR) -c $< -o $@

clean		:
		@rm -rf $(OBJECTS)
		@echo "$(RED)* $(NAME) object files have been deleted *$(RESET)"

fclean		:	clean
		@rm -rf $(NAME)
		@echo "$(RED)* $(NAME) was deleted *$(RESET)"

re			:	fclean $(NAME)

deps		:	fclean
	@printf "$(GREEN)* composing compile_commands.json *$(RESET)\n"
	@intercept-build-14 make
	@printf "$(GREEN)* compile_commands.json was created *$(RESET)\n"

.PHONY		:	all clean fclean re deps
