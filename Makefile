##
## EPITECH PROJECT, 2022
## My_hunter
## File description:
## makefile
##

SRC	=	$(wildcard myhunterdir/*.c)

OBJ	=	$(SRC:.c=.o)

COPIES	=	*~

NAME	=	my_hunter

CFLAGS	=	-g -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

MAKE	=	make

all:	$(NAME)  clean

$(NAME):	$(OBJ)
	cd ./lib/my/ && $(MAKE)
	gcc -c $(SRC)
	rm -f myhunterdir/'*.o'
	gcc $(OBJ) -o $(NAME) -L./lib/my -lmy $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f $(COPIES)
	rm -f *.o

fclean:	clean
	rm -f $(NAME)
	cd lib/my/ && rm libmy.a

re:     fclean all
	rm -f $(OBJ)
