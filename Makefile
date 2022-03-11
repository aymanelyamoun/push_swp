# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 13:23:42 by ael-yamo          #+#    #+#              #
#    Updated: 2022/03/11 15:01:30 by ael-yamo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = push_swap
BONUS = checker

FILES = main.c push_swap.c creat_stack.c giving_index.c creat_stack_utils.c \
op_r_rotate.c op_rotate.c op_swap.c op_push.c sort_utils.c sort_utils2.c 
OBJ = $(FILES:.c=.o)
BONUS_FILES = ch_r_rotate.c ch_rotate.c ch_swap.c ch_push.c checker.c \
creat_stack.c giving_index.c creat_stack_utils.c \
op_r_rotate.c op_rotate.c op_swap.c op_push.c sort_utils.c \
get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
BONUS_OBJ = $(BONUS_FILES:.c=.o)

.PHONY: all fclean clean re
all: ${NAME}


${NAME}: ${OBJ}
	${CC} ${FLAGS} ${OBJ} -o ${NAME}

%.o: %.c push_swap.h
	${CC} ${FLAGS} -c $< -o $@

bonus: ${BONUS_OBJ} get_next_line/get_next_line.h
	${CC} ${FLAGS} ${BONUS_OBJ} -o ${BONUS}
clean:
	${RM} ${OBJ}
	${RM} ${OBJ} ${BONUS_OBJ}
	
fclean: clean
	${RM} ${NAME}
	${RM} ${BONUS}
re: fclean all