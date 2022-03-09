CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = push_swap
FILES = creat_stack.c ft_atoi.c giving_index.c main.c printing_stack.c \
push_swap.c r_rotate.c rotate.c sort_utils.c sort_utils2.c swap.c push.c
OBJ = creat_stack.o ft_atoi.o giving_index.o main.o printing_stack.o \
push_swap.o r_rotate.o rotate.o sort_utils.o sort_utils2.o swap.o push.o

.PHONY: all fclean clean re
all: ${NAME}
${NAME}: ${OBJ}
	${CC} ${FLAGS} ${OBJ} -o ${NAME}
${OBJ}: ${FILES}
	${CC} ${FLAGS} ${FILES} -c
clean:
	${RM} ${OBJ}
fclean: clean
	${RM} ${NAME}