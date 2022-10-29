# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelyakou <aelyakou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 19:24:15 by aelyakou          #+#    #+#              #
#    Updated: 2022/10/29 01:26:03 by aelyakou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-static-libsan -fsanitize=address

all :
	gcc -o cub3d cube3d.c line_renderer.c raycasting.c init.c convert.c libft/libft.a  gnl/get_next_line.c -lmlx -framework OpenGL -framework AppKit
c :
	rm cub3d
