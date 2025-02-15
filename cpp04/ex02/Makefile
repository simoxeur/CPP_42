NAME	= prog

CPP		= c++

FLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp	Animal.cpp Dog.cpp Cat.cpp	WrongAnimal.cpp WrongCat.cpp Brain.cpp

OBJS	=		${SRCS:.cpp=.opp}

all: $(NAME)

%.opp:%.cpp Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp	WrongCat.hpp	Brain.hpp	Makefile
	@$(CPP) ${FLAGS} -c $< -o $@

$(NAME): 		${OBJS}
	@$(CPP) ${FLAGS} ${OBJS} -o ${NAME}
	@echo "finished";

clean:
	@rm -f ${OBJS}
	@echo "removed files";

fclean: 	clean
	@rm -f $(NAME)
	@@echo "removed" ${NAME};

re:		fclean all

.PHONY: clean