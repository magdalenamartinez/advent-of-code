

NAME	=	day5



INCLUDE	=	-I ./include/

SRC	= 	src/main.c	\
		src/file.c	\
		src/rules.c	\
		src/sort.c	\
		src/update.c	\
		src/num.c	\
		src/secondpart.c	\

	

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
