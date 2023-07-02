# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbolzan- <tbolzan-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 14:11:51 by tbolzan-          #+#    #+#              #
#    Updated: 2023/06/29 14:24:20 by tbolzan-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = so_long

LIBFT = libft.a

LIBMLX = ./minilibx-linux/libmlx_Linux.a ./minilibx-linux/libmlx.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

LFLAGS = -L $(LIBMLX) $(LIBFT)

RM = rm -f

AR = ar -rsc

SRC = $(wildcard ./src/.c) main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)


$(NAME): $(OBJ)
	@make -C ./libft
	@mv ./libft/$(LIBFT) .
	cc -Wall -Wextra -Werror -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(OBJ) $(LFLAGS) $(CFLAGS) -L. $(LIBFT) -o $(NAME) -L $(LIBMLX)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3  -c $< -o $@

clean:
	$(RM) $(OBJ)
	@make clean -C ./libft

fclean: clean
	$(RM) $(NAME)

re: fclean all
	
.PHONE: all clean fclan re
	
