

NAME	=	day10



INCLUDE	=	-I ./include/

SRC	= 	src/main.c	\
		src/file.c	\
		src/numbers.c	\

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
