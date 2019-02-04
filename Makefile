# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/25 14:21:50 by bfalmer-          #+#    #+#              #
#    Updated: 2019/02/04 16:04:18 by bfalmer-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FLAGS = -Wall -Wextra -Werror -g 
SRCS = src/main.c src/errors.c src/image.c src/kernel.c
OBJS = $(SRCS:.c=.o)
INC = includes/fractol.h
FRAMEWORKS = -framework OpenGL -framework AppKit -framework opencl
LIBS = -L minilibx_macos/ -lmlx -L libft/ -lft
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	make lib_ft
	make minilibx_macos
	$(CC) $(FLAGS) $(OBJS) -I $(INC) $(LIBS) $(FRAMEWORKS) -o $(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

lib_ft:
	make -C libft

minilibx_macos:
	make -C minilibx_macos

clean:
	/bin/rm -f src/*.o
	make -C libft/ clean
	make -C minilibx_macos clean

fclean: 
	make clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: 
	make fclean
	make	