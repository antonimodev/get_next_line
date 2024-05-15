NAME = getnextline.a
CC = gcc
FLAGS = -Werror -Wextra -Wall
SRC =

OBJ = 

all: $(NAME)
	ar rcs 

o: %.c=%.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re