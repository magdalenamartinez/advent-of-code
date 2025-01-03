

NAME	=	day9



INCLUDE	=	-I ./include/

SRC	= 	src/main.c	\
		src/file.c	\
		src/numbers.c	\
		src/memory.c	\
		src/secondpart.c	\
		
		
#change this one for array.c to get the first part instead of the second

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
