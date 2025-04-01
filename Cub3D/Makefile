# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/18 15:47:27 by elsikira          #+#    #+#              #
#    Updated: 2025/03/27 17:19:10 by elsikira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

CC			=	cc -g3

FLAG		=	#-Wall -Wextra -Werror

LIBFT_PATH	=	./Libft/

LIBFT_FILE	=	libft.a

# MLX_FILE	=	libmlx.a
MLX_FILE	=	libmlx_Linux.a

LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

MLX_FLAG	=	-lX11 -lXext

MLX_PATH	=	./mlx_linux/

MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))

MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

SRC_FILE	= exec/close_game.c exec/img.c exec/keys.c exec/main.c parsing/init.c parsing/parse_args.c parsing/parse_line.c parsing/parse_map.c parsing/parse_walls.c parsing/rgb.c utils/bool_utils.c utils/error.c utils/get_next_line.c utils/gnl.c utils/utils.c parsing/get_map.c utils/bool_utils_2.c exec/exec.c exec/move_player.c exec/rotate_player.c exec/settings.c exec/render_game.c exec/raycasting.c exec/minimap.c exec/set_player_orientation.c

SRC_DIR = src/


#INC_DIR		=	./

SRC			=	$(addprefix $(SRC_DIR),$(SRC_FILE))

OBJ			=	$(SRC:.c=.o)

.c.o:
	$(CC) $(FLAG) -c $< -o $@ -I./mlx_linux

all: $(NAME)

lib:
	@make -C $(LIBFT_PATH)

mlx:
	@make -sC $(MLX_PATH)

$(NAME): lib mlx $(OBJ)
	$(CC) $(OBJ) $(LIBFT_LIB) $(MLX_EX) -o $(NAME) -I./mlx_linux -lm

clean:
	@make clean -sC $(MLX_PATH)
	@make clean -sC $(LIBFT_PATH)
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re
