# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 02:10:44 by samatsum          #+#    #+#              #
#    Updated: 2024/11/11 08:10:20 by samatsum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= fractol

NAME_BONUS	= fractol_bonus 

SRC =		./mandatory/ft_fractol.c \
			./mandatory/julia.c \
			./mandatory/complex_math.c \
			./mandatory/hooks.c \
			./mandatory/mandelbrot.c \
			./mandatory/params.c \
			./mandatory/format_check.c \
			./mandatory/ft_atod.c \
			./mandatory/useful_functions.c \
			./mandatory/zoom.c \
			$(shell find ./ft_printf/ -name '*.c') \

BONUS_SRC = ./bonus/ft_fractol_bonus.c \
			./bonus/julia_bonus.c \
			./bonus/complex_math_bonus.c \
			./bonus/hooks_bonus.c \
			./bonus/mandelbrot_bonus.c \
			./bonus/params_bonus.c \
			./bonus/burning_bonus.c \
			./bonus/format_check_bonus.c \
			./bonus/ft_atod_bonus.c \
			./bonus/useful_functions_bonus.c \
			./bonus/zoom_bonus.c \
			$(shell find ./ft_printf/ -name '*.c') \

OBJ				=	$(SRC:.c=.o)
BONUS_OBJS		=	$(BONUS_SRC:.c=.o)

CC					=	cc
RM					=	rm -f
MANDATORYFLAGS		=	-Wall -Wextra -Werror -lXext -lX11 minilibx-linux/libmlx_Linux.a
FSANITIZEFLAGS		=	-fsanitize=address -g3
OPTIMIZEFLAGS		= 	-O2 -march=native

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(MANDATORYFLAGS) $(OPTIMIZEFLAGS)

all:	$(NAME)

$(NAME_BONUS): $(BONUS_OBJS)
	$(CC) -o $(NAME_BONUS) $(BONUS_OBJS) $(MANDATORYFLAGS) $(OPTIMIZEFLAGS)

bonus:	$(BONUS_OBJS)

clean:		
	$(RM) $(OBJ) $(BONUS_OBJS)

fclean:		clean
	$(RM) $(NAME) $(NAME_BONUS)

re:				fclean all

.PHONY:			all clean fclean re bonus
