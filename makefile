# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelyakou <aelyakou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 19:24:15 by aelyakou          #+#    #+#              #
#    Updated: 2022/11/30 10:43:11 by aelyakou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# all :
# 	gcc -o cub3d cube3d.c line_renderer.c raycasting.c init.c convert.c mlx_adds.c libft/libft.a  gnl/get_next_line.c -lmlx -framework OpenGL -framework AppKit
# c :
# 	rm cub3d

# $(GREEN)$(shell basename $<)$(GREEN

##############################colors####################################################################
RED        := \033[0;31m
WHITE      := \033[0;37m
GREEN      := \033[0;32m
BLUE       := \033[0;34m
YELLOW	   := \033[0;33m
########################################################################################################
draw       := draw
INCLUDE_DIR := includes
LIBFT_DIR  := LIBFT
GNL_DIR    := gnl
FILE	   := files
LIBFT      := $(LIBFT_DIR)/libft.a
GNL 	   := $(GNL_DIR)/get_next_line.a
SRC_DIR    := src
OBJ_DIR    := obj
PARSING    := parser_utils parser colors
src        := raycasting init convert init_utils additional
RND		   := line_renderer mlx_adds
SRC        := $(addsuffix .c, $(addprefix src/parser/, $(PARSING))) \
					$(addsuffix .c, $(addprefix src/, $(src))) \
					$(addsuffix .c, $(addprefix src/rendering/, $(RND)))\

main        := 	$(SRC_DIR)/cube3d.c
OBJ	        := $(SRC:.c=.o)
CC          := 	gcc
GCCFLAGS    := -Wall -Wextra -Werror
# -static-libsan -fsanitize=address
INCLUDE      := $(INCLUDE_DIR)/cube3d.h
NAME        := Cube3d
RECOMPILING := echo "     $(YELLOW)Recompiling..........$(YELLOW)"

MLXFLAGS := -lmlx -framework OpenGL -framework AppKit

###################################TARGETS######################################################

all : $(NAME)
	@echo""
	@echo " $(YELLOW)Welcome to$(YELLOW) "
	@sleep 0.8
	@cat $(draw)/cube3d-art.ans
	@sleep 1
	@echo""
	@echo""
	@echo "                				$(YELLOW)By zrabhi && aelyakou $(YELLOW)                        "

$(NAME) : create_dir  $(OBJ) $(main) $(INCLUDE) $(LIBFT) $(GNL)
	@echo "\n"
	@echo " $(YELLOW)Source files are compiled!\n$(YELLOW)"
	@echo  "Building $(NAME) for" "Mandatory" "..."
	@$(CC) $(GCCFLAGS) $(MLXFLAGS) $(main) $(LIBFT) $(GNL) $(OBJ) -o $(NAME) 
	@sleep 0.1.5
	@sleep 0.2
	@echo ""
	@echo  "$(NAME) is created!\n"
################################################### LIBFT && GNL###################################
$(GNL)   :
	@$(MAKE) -C $(GNL_DIR)
$(LIBFT) :
	@$(MAKE) -C $(LIBFT_DIR)

##################################################################################################

%.o: %.c
	@echo "$(YELLOW)creating : $(@:OBJ/%=%) "
	@sleep 0.05
	@$(CC) $(GCCFLAG)   -c $< -o $@

#####################################################REMOVING ABJECTS FILE#######################
create_dir :
	@mkdir -p $(FILE)
clean :
	@echo "$(YELLOW)Removing Objects file ....    $(GREEN)$(shell basename $(OBJ))$(GREEN)"
	@$(MAKE) -C $(LIBFT_DIR)/ clean
	@$(MAKE) -C $(GNL_DIR)/ clean
	@rm -rf $(OBJ)
	@echo "     $(YELLOW)Successfully Removed$(YELLOW)"

##############################REMOVING OBJECTS FILE AND EXE#####################################

fclean : clean
	@$(MAKE) -C $(LIBFT_DIR)/ fclean
	@$(MAKE) -C $(GNL_DIR)/ fclean
	@echo "$(YELLOW)Removing Minishell ....    $(GREEN)$(shell basename $(NAME))$(GREEN)"
	@rm -rf $(NAME) Cube3d.dSYM .vscode
	@echo "     $(YELLOW)Successfully Removed$(YELLO)"

#################################################RECOMPILING##################################

re: fclean all
	@echo "     $(YELLOW)Recompiling..........$(YELLOW)"
