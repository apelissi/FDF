# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apelissi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 17:22:28 by apelissi          #+#    #+#              #
#    Updated: 2018/10/01 20:01:18 by apelissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf

SRC_PATH = ./srcs/

OBJ_PATH = ./objs/

CPPFLAGS = -I./includes/

SRC_NAME =	main.c					\
			afficher.c				\
			fil.c					\
			ft_link.c				\
			get_line.c				\
			get_tab.c				\
			get_tab_dim.c			\
			ft_mlx.c				\
			deal_key.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

LDFLAGS = -L./libft/

LFT = -lft

CC = gcc $(CFLAGS)

CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit


all: $(NAME)

$(NAME): $(OBJ)
	make -C./libft/
	echo "\033[34mCreation of $(NAME) ...\033[0m"
	$(CC) $(LDFLAGS) $(LFT) $(OBJ) -o $@ $(MLX)
	echo "\033[32m$(NAME) created\n\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CPPFLAGS) -o $@ -c $<
clean:
	@make clean -C ./libft/
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make fclean -C ./libft/
	@echo "\033[33mRemoval of $(NAME)...\033[0m"
	@rm -f $(NAME)
	@echo "\033[31mBinary $(NAME) deleted\n\033[0m"

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY: all, clean, fclean, re
