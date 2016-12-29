# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qduperon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/23 15:00:02 by qduperon          #+#    #+#              #
#    Updated: 2016/12/29 15:35:35 by qduperon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

CFLAGS = -Wall -Werror -Wextra -I include -g3

SRC = srcs/parsing/camera.c srcs/parsing/clear.c srcs/parsing/color.c \
	  srcs/parsing/cone.c srcs/parsing/cylindre.c srcs/parsing/init.c\
	  srcs/parsing/plan.c srcs/parsing/sphere.c srcs/parsing/parsing_tools.c\
	  srcs/parsing/spot.c srcs/parsing/new.c srcs/display.c srcs/tools.c\
	  srcs/draw.c srcs/hook.c srcs/main.c srcs/objects.c srcs/vectors.c\
	srcs/vectors2.c srcs/norm.c srcs/light.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@make -C minilibx_macos
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) -L minilibx_macos -lmlx \
	-framework OpenGl -framework Appkit libft/libft.a minilibx_macos/libmlx.a
	@echo "Make libmlx.a: \033[1;32m DONE !\033[m"
	@echo "Make $(NAME) : \033[1;32m DONE !\033[m"

clean :
	@make -C libft clean
	@make -C minilibx_macos clean
	@rm -rf $(OBJ)
	@echo "Clean Libft, Minilibx and $(NAME) : \033[1;32m DONE !\033[m"

fclean : clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@echo "Fclean $(NAME) : \033[1;32m DONE !\033[m"

re : fclean all

demo :
	@make re
	./Rtv1 scene/testroom

.PHONY: all clean fclean re
