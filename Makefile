# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 13:23:42 by ael-yamo          #+#    #+#              #
#    Updated: 2022/03/10 21:38:01 by ael-yamo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = push_swap
FILES =  main.c push_swap.c creat_stack.c giving_index.c \
op_r_rotate.c op_rotate.c op_swap.c op_push.c sort_utils.c sort_utils2.c 
OBJ = $(FILES:.c=.o)

.PHONY: all fclean clean re
all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${FLAGS} ${OBJ} -o ${NAME}
	
%.o: %.c push_swap.h
	${CC} ${FLAGS} -c $< -o $@
clean:
	${RM} ${OBJ}
fclean: clean
	${RM} ${NAME}
re: fclean all