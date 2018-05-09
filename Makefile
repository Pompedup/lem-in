# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/25 16:13:40 by abezanni          #+#    #+#              #
#    Updated: 2018/05/09 17:21:15 by abezanni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = $(SRC:.c=.o)

#OBJ1 = $(SRC_1:.c=.o)

#OBJ2 = $(SRC_2:.c=.o)


CC = gcc

SRC = $(addprefix src/,$(SRC_NAME))

SRC_NAME =	lem_in.c\
			ft_lst.c\
			ft_parse.c\
			ft_check_rooms.c\
			ft_check_links.c\

#SRC_NAME1 =

#SRC_NAME2 =


#SRC_1 = $(addprefix src/,$(SRC_NAME1))

#SRC_2 = $(addprefix src/,$(SRC_NAME2))

NAME = lem-in

#NAME1 = checker

#NAME2 = push_swap

LIB_PATH = ../libft

LIB = ../libft/libft.a

INCLUDE = -I ./inc

CFLAGS = -Wall -Wextra -Werror $(INCLUDE)

all : libftcomp $(NAME)

$(NAME) : $(LIB) $(OBJ) inc/lem_in.h
	echo $(OBJ)
	gcc -o $(NAME) $(CFLAGS) $(LIB) $(OBJ)
	@echo "\033[1;32mSucced lem-in\033[0m"


#$(NAME1) : $(LIB) $(OBJ1) $(OBJ_ALL)
#	@gcc -o $(NAME1) $(CFLAGS) $(LIB) $(OBJ1) $(OBJ_ALL)
#	@echo "\033[1;32mSucced checker\033[0m"
#
#
#$(NAME2) : $(LIB) $(OBJ2) $(OBJ_ALL)
#	@gcc -o $(NAME2) $(CFLAGS) $(LIB) $(OBJ2) $(OBJ_ALL)
#	@echo "\033[1;32mSucced push_swap\033[0m"

libftcomp :
	@make -C $(LIB_PATH)

clean :
	@make clean -C $(LIB_PATH)
	@/bin/rm -f $(OBJ)
	@echo "\033[1;32mSucced clean of '*.o' from lem-in\033[0m"

fclean : clean
	@/bin/rm -f $(LIB)
	@echo "\033[1;32mSucced clean of libft.a\033[0m"
	@/bin/rm -f $(NAME)
	@echo "\033[1;32mSucced clean lem-in\033[0m"

re : fclean	all
	@echo "\033[1;32mSucced recompilation lem-in\033[0m"
