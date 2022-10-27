# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelyakou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 11:17:22 by aelyakou          #+#    #+#              #
#    Updated: 2021/11/06 19:59:49 by aelyakou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=ft_isalpha.c ft_isdigit.c ft_memset.c ft_isalnum.c\
 ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c\
  ft_memcmp.c ft_strlen.c ft_isascii.c ft_isprint.c\
   ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c\
    ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c\
	 ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\
	  ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 
NAME =libft.a
BONUS =ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
 ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
INCLUDE=./
FLAGS=-Wall -Wextra -Werror

OBJ=$(SRCS:.c=.o)
BONUS_OBJ=$(BONUS:.c=.o)

%.o : %.c libft.h
	@$(CC) $(FLAGS) -c $<


$(NAME): $(OBJ)
	@ar rcs $@ $^

all: $(NAME)

clean:
	@rm -f	$(OBJ) $(BONUS_OBJ) 

fclean: clean
	@rm	-f $(NAME)

re: fclean all

bonus: $(BONUS) $(BONUS_OBJ)
	@ar rcs $(NAME) $(BONUS_OBJ)