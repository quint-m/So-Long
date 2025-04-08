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

all			:	libmlx $(NAME)

run			:	all
		./$(NAME)

libmlx		:
		@cmake $(LIB_MLX) -B $(LIB_MLX)/build && make -C $(LIB_MLX)/build -j4

$(NAME)		:	$(OBJ_DIR) $(OBJECTS)
		$(CC) $(CCFLAG) $(OBJECTS) $(LIBS) -I$(HDR_DIR) -I$(LIB_MLX_HDR) -o $(NAME)
		@echo "\033[0;92m* $(NAME) program file was created\033[0m *"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
		@$(CC) $(CCFLAG) -I$(HDR_DIR) -I$(LIB_MLX_HDR) -c $< -o $@

clean		:
		rm -rf $(OBJECTS)
		@echo "\033[0;91m* $(NAME) object files was deleted *\033[0m"

fclean		:	clean
		rm -rf $(NAME)
		@echo "\033[0;91m* $(NAME) was deleted *\033[0m"

re			:	fclean $(NAME)

.PHONY		:	all clean fclean re
