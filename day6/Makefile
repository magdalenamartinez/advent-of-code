

NAME	=	day6



INCLUDE	=	-I ./include/

SRC	= 	src/main.c	\
		src/file.c	\
		src/num.c	\
		src/memory.c	\
		src/utilities.c	\
		src/guard.c	\
		src/copy_map.c	\
		src/loops.c	\

OBJ	=	$(SRC:.c=.o)


all: 	$(NAME)

$(NAME): 	$(OBJ)

		gcc -g $(OBJ) -o $(NAME) $(INCLUDE) 

clean:
	rm -f $(NAME)


fclean: clean
	rm -f ./src/*.o

re: 	fclean all

library: fclean

exec:	re
	./$(NAME)
