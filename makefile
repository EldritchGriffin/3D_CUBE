# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelyakou <aelyakou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 19:24:15 by aelyakou          #+#    #+#              #
#    Updated: 2022/11/10 08:51:34 by aelyakou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all :
	gcc -o cub3d cube3d.c line_renderer.c raycasting.c init.c convert.c mlx_adds.c libft/libft.a  gnl/get_next_line.c -lmlx -framework OpenGL -framework AppKit
c :
	rm cub3d
