# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 11:22:31 by ldaniel           #+#    #+#              #
#    Updated: 2023/07/14 13:38:10 by ldaniel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = @gcc -Werror -Wall -Wextra -O3 -march=native -flto -fno-signed-zeros -funroll-loops
NOR = norminette -R CheckForbiddenSourceHeader
SRC = fractol.c julia.c mandelbrot.c utils.c close.c key.c color.c color2.c \
random.c ft_printf/ft_print_else.c ft_printf/ft_printf.c ft_printf/ft_print_hex.c \
ft_printf/ft_print_ptr.c ft_printf/ft_print_unsigned.c ft_printf/ft_itoa.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) mlx-linux/libmlx.a -lXext -lX11 -lm -lz -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	
re:	fclean all
