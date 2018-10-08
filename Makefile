# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apelissi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 17:22:28 by apelissi          #+#    #+#              #
#    Updated: 2018/10/08 15:14:48 by apelissi         ###   ########.fr        #
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
			deal_key.c				\
			get_max.c

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
	@make -C./libft/
	@$(CC) $(LDFLAGS) $(LFT) $(OBJ) -o $@ $(MLX)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CPPFLAGS) -o $@ -c $<
clean:
	@make clean -C ./libft/
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make fclean -C ./libft/
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
