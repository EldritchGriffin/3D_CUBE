# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelyakou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/26 00:48:37 by aelyakou          #+#    #+#              #
#    Updated: 2021/12/26 00:48:40 by aelyakou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=ft_printf_utils.c ft_printf.c ft_printf_utils2.c
NAME=libftprintf.a
INCLUDE=./
FLAGS=-Wall -Wextra -Werror

OBJ=$(SRCS:.c=.o)

%.o : %.c ft_printf.h
	@$(CC) $(FLAGS) -c $<


$(NAME): $(OBJ)
	@ar rcs $@ $^

all: $(NAME)

clean:
	@rm -f	$(OBJ)

fclean: clean
	@rm	-f $(NAME)

re: fclean all
