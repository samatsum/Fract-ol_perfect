# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 02:10:44 by samatsum          #+#    #+#              #
#    Updated: 2024/08/09 03:13:29 by samatsum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc

CFLAGS = -Wall -Werror -Wextra -g 
MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11
LIBFT = ./libft/libft.a

SRC = ft_fractol.c \
	julia.c \
	complex_math.c \
	hooks.c \
	mandelbrot.c \
	params.c \
	burning.c \


all: $(NAME)

$(NAME): $(SRC:.c=.o)
	$(MAKE) --no-print-directory -C ./libft
	echo "\033[1m LIBFT done \033[0m"
	$(MAKE) --no-print-directory -C ./minilibx-linux
	echo "\033[1m MiniLibX done \033[0m"
	$(CC) $(CFLAGS) -lm $(SRC) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	echo "\033[1m Ready to FRACT-OL \033[0m"

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(SRC:.c=.o)
	echo "OBJ deleted"

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)
	echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re, bonus

.SILENT:
