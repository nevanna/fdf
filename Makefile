# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htillman <htillman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/02 21:40:05 by htillman          #+#    #+#              #
#    Updated: 2019/02/23 21:53:11 by htillman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = ft_first_val.c ft_free.c ft_list.c ft_nb_sys.c ft_secondary.c ft_val_lst.c main.c ft_data_pr.c \
	ft_key.c ft_around_x_y.c ft_brasenham.c ft_draw.c ft_lst_cpy.c ft_move.c \
	ft_move_t.c ft_iso.c
FILESO = ${SRC:.c=.o}
FLAGS = -Wall -Wextra -Werror
LIBA = -L ./libft -lft
MIN = -L ./minilibx_macos -lmlx
ADD = -framework OpenGL -framework AppKit
INCL = -I ./libft
INCLM = -I ./minilibx_macos
#-fsanitize=address
all: $(NAME)

$(NAME): $(FILESO)
	make -C ./libft/
	make -C ./minilibx_macos/
	gcc $(FLAGS) -o $(NAME) $(SRC) $(LIBA) $(MIN) $(ADD)

%.o: %.c
	gcc $(FLAGS) $(INCL)  -o $@ -c $<

clean:
	rm -f $(FILESO)
	make clean -C ./libft/
	make clean -C ./minilibx_macos/
fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft/
re: fclean all
