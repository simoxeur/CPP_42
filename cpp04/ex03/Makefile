NAME	= prog

CPP		= c++

FLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp		AMateria.cpp		Cure.cpp	Ice.cpp\
				Character.cpp	MateriaSource.cpp	

OBJS	=		${SRCS:.cpp=.opp}

all: $(NAME)

%.opp:%.cpp AMateria.hpp Character.hpp	Cure.hpp	Ice.hpp	ICharacter.hpp	IMateriaSource.hpp	MateriaSource.hpp	Makefile
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