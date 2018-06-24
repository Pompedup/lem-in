# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/25 16:13:40 by abezanni          #+#    #+#              #
#    Updated: 2018/06/24 15:35:11 by ccoupez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = $(SRC:.c=.o)

CC = @gcc

SRC = $(addprefix src/,$(SRC_NAME))

PARSE =		check_double_rooms.c\
			check_links.c\
			check_option.c\
			check_rooms.c\
			cmd.c\
			parse.c\
			verify_link.c\

ALGO =		check_opti_way.c\
			resolve.c \
			search_best_ways.c\
			search_ways.c\
			send_ant.c\

STRUCT =	free_struct.c\
			lst_path.c\
			lst.c\

SRC_NAME =	lem_in.c\
			$(addprefix parse/,$(PARSE))\
			$(addprefix algo/,$(ALGO))\
			$(addprefix struct/,$(STRUCT))\

NAME = lem-in

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
