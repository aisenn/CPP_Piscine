NAME = easyfind
CFLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.cpp=.o)

SRC = 	main.cpp \

all: $(NAME) clean

$(NAME):$(OBJ)
	clang++ $(CFLAGS) -o $(NAME) $(OBJ)

$%.o:%.cpp
	@ clang++ $(CPPFLAGS) -c -o $@ $<

clean:
	rm -f *.o

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re