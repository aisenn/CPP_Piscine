NAME = identify
CFLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.cpp=.o)

SRC = 	A.cpp \
        B.cpp \
        Base.cpp \
        C.cpp \
        main.cpp \

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