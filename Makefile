#--------- SRC ---------#

SRC_DIR = src

SRC = 	ft_write.s \
	ft_read.s \
	ft_strlen.s \
	ft_strcmp.s \
	ft_strcpy.s \
	ft_strdup.s \
	ft_list_push_front.s \
	ft_list_size.s \
	ft_list_sort.s \
	ft_list_remove_if.s \
	ft_atoi_base.s \

SRC_ABS = ${SRC:%.s=${SRC_DIR}/%.s}

OBJ_DIR = objs

OBJ = ${SRC:%.s=${OBJ_DIR}/%.o}

#---------- COMPILING -------#

NAME = libasm.a

ASM = nasm

ASM_FLAGS = -f elf64

INCLUDES = libasm.h

#----------- RULES ----------#

all: 			${NAME}

${OBJ_DIR}/%.o: 	${SRC_DIR}/%.s ${INCLUDES} | ${OBJ_DIR}
		 	${ASM} ${ASM_FLAGS} $< -o $@ -I.

${NAME}:		${OBJ} ${INCLUDES}
			ar rcs ${NAME} ${OBJ}

${OBJ_DIR}:
		 	@mkdir -p ${OBJ_DIR}

clean:
			rm -rf ${OBJ_DIR}

fclean:			clean
			rm -f ${NAME}

re:			fclean all

.PHONY:	clean fclean all re 
