#------------------------------------------------------
# Makefile to compile the ptr_manip libraries
#
# Created by Pierre-Marie Danieau the 07-04-2017
#------------------------------------------------------

CC =		gcc

AR =		ar rc

RM =		rm -f

LIB =		libptr_manip.a

SRC =		src/c2d.c

OBJ =		$(SRC:.c=.o)

INC =		-I./include/

CFLAGS +=	$(INC)

all:		$(LIB)

$(LIB):		$(OBJ)
		$(AR) $(LIB) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(LIB)

re:		fclean all

dbg:		CFLAGS += -g
dbg:		re

.PHONY:		all $(LIB) clean fclean re dbg
