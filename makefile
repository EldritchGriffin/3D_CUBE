# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelyakou <aelyakou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 19:24:15 by aelyakou          #+#    #+#              #
#    Updated: 2022/10/30 19:42:11 by aelyakou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all :
	gcc -o cub3d cube3d.c line_renderer.c raycasting.c init.c convert.c libft/libft.a  gnl/get_next_line.c -lmlx -framework OpenGL -framework AppKit
c :
	rm cub3d
