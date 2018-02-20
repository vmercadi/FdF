# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/16 06:27:28 by vmercadi          #+#    #+#              #
#    Updated: 2017/09/25 18:16:31 by vmercadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = srcs/fdf.c srcs/display.c srcs/init.c srcs/utils.c srcs/check.c \
		srcs/event.c

MLX_S = autre/minilibx_macos_sierra/

INCLUDES = -I includes -I $(MLX_S) -I libft

CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

MFLAGS = -framework OpenGL -framework AppKit -L $(MLX_S) -lmlx

SRCO = $(SRC:%.c=%.o)

LIB = libft/libft.a

.PHONY: all re cleans

all: $(NAME)

$(NAME):$(SRCO)
	@make -C $(MLX_S)
	@make -C libft/
	@gcc $(FLAGS) $(LIB) -o $(NAME) $(SRC) $(MFLAGS) $(INCLUDES)

clean:
	@rm -rf $(SRCO)
	@make clean -C libft/

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft/

ultra: all clean

re: fclean all
