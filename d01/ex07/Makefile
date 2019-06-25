NAME = replace
CFLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.cpp=.o)

SRC =	replace.cpp \
		MySed.class.cpp \

all: $(NAME)

$(NAME):$(OBJ)
	clang++ $(CFLAGS) -o $(NAME) $(OBJ)

$%.o:%.cpp
	@ clang++ $(CPPFLAGS) -c -o $@ $<

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re