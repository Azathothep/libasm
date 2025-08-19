#--------- SRC ---------#

NAME =		a.test

SRC =		main.c \
		test_utils.c \
		test_write.c \
		test_read.c \
		test_strlen.c \
		test_strcmp.c \
		test_strcpy.c \
		test_strdup.c \
		test_atoi_base.c \
		test_list_push_front.c \
		test_list_size.c \
		test_list_sort.c \
		test_list_remove_if.c

OBJ_DIR = objs

OBJ = ${SRC:%.c=${OBJ_DIR}/%.o}

INCLUDES = test.h ${LIBASM_DIR}/${LIBASM_INCLUDES}

#---------- COMPILING -------#

LIBASM_NAME =	libasm.a

LIBASM_DIR =	..

LIBASM =	${LIBASM_DIR}/${LIBASM_NAME}

LIBASM_INCLUDES = libasm.h

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror -z noexecstack -no-pie -fno-pie

#----------- RULES ----------#

all: 			${NAME}

${LIBASM}:		
			${MAKE} -C ${LIBASM_DIR}

${OBJ_DIR}:
		 	@mkdir -p ${OBJ_DIR}

${OBJ_DIR}/%.o: 	%.c ${INCLUDES} | ${OBJ_DIR}
			${CC} ${CC_FLAGS} -c $< -o $@ -I.

${NAME}:		${LIBASM} ${OBJ} ${INCLUDES}
			${CC} ${CC_FLAGS} ${OBJ} -I. -I${LIBASM_DIR} -L${LIBASM_DIR} -lasm -o ${NAME}

clean:
			rm -rf ${OBJ_DIR}
			${MAKE} -C ${LIBASM_DIR} clean

fclean:			clean
			rm -f ${NAME}
			${MAKE} -C ${LIBASM_DIR} fclean

re:			fclean all

.PHONY:	clean fclean all re 
