# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelyakou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 19:11:02 by aelyakou          #+#    #+#              #
#    Updated: 2022/03/19 19:11:03 by aelyakou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =so_long
NAMEB =so_long_bonus
SRC =mandatory/process_images.c mandatory/level_parser.c mandatory/process_images2.c\
mandatory/player_movement.c mandatory/so_long.c
SRCB =bonus/level_parser_bonus.c bonus/process_images_bonus.c bonus/player_movement_bonus.c\
bonus/so_long_bonus.c bonus/process_images2_bonus.c bonus/bonus_funcs.c
flags =-Wall -Wextra -Werror
mlx =-lmlx -framework OpenGL -framework AppKit
OBJ = ${SRC:.c=.o}
OBJB = ${SRCB:.c=.o}

all : ${NAME}
%.o : %.c
	@cc ${flags} -c $< -o $@
${NAME} : ${OBJ}
	@cd ft_printf && make
	@cd libft && make
	@cc ${flags} ${mlx} ${OBJ} ft_printf/libftprintf.a libft/libft.a -o ${NAME}
	@echo "GameCreated"
bonus : ${OBJB}
	@cd ft_printf && make	
	@cd libft && make
	@cc ${flags} ${mlx} ${OBJB} ft_printf/libftprintf.a libft/libft.a -o ${NAMEB}
	@echo "BonusGameCreated"
clean :
	@cd libft && make clean
	@cd ft_printf && make clean
	@rm -rf ${OBJ} ${OBJB}
	@echo "Cleaned"
fclean : clean
	@cd libft && make fclean
	@cd ft_printf && make fclean
	@rm -rf ${NAME} ${NAMEB}
	@echo "FullyCleaned"
re : fclean ${NAME}
