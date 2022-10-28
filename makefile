# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelyakou <aelyakou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 19:24:15 by aelyakou          #+#    #+#              #
#    Updated: 2022/10/27 21:26:13 by aelyakou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-static-libsan -fsanitize=address

all :
	gcc -Wall -Wextra -Werror -o cub3d cube3d.c init.c convert.c libft/libft.a  gnl/get_next_line.c -lmlx -framework OpenGL -framework AppKit
c :
	rm cub3d