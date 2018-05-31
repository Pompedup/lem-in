# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/25 16:13:40 by abezanni          #+#    #+#              #
#    Updated: 2018/05/31 16:17:46 by ccoupez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = $(SRC:.c=.o)

#OBJ1 = $(SRC_1:.c=.o)

#OBJ2 = $(SRC_2:.c=.o)


CC = @gcc

SRC = $(addprefix src/,$(SRC_NAME))

SRC_NAME =	lem_in.c\
			ft_lst.c\
			ft_parse.c\
			ft_check_rooms.c\
			ft_check_links.c\
			ft_free_struct.c\
			resolve.c \
			lst_path.c

#SRC_NAME1 =

#SRC_NAME2 =


#SRC_1 = $(addprefix src/,$(SRC_NAME1))

#SRC_2 = $(addprefix src/,$(SRC_NAME2))

NAME = lem-in

#NAME1 = checker

#NAME2 = push_swap

LIB_PATH = libft

LIB = libft/libft.a

INCLUDE = -I ./inc

CFLAGS = -Wall -Wextra -Werror $(INCLUDE)

all : libftcomp $(NAME)

$(NAME) : $(LIB) $(OBJ) inc/lem_in.h
	$(CC) -o $(NAME) $(CFLAGS) $(LIB) $(OBJ)
	@echo "\033[1;32mSucced lem-in\033[0m"

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
