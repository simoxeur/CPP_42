NAME	= ware

CPP		= c++

FLAGS	= -Wall -Wextra -Werror

SRCS		=	main.cpp	Weapon.cpp	HumanA.cpp	HumanB.cpp

OBJS	=		${SRCS:.cpp=.opp}

all: $(NAME)

%.opp:%.cpp Weapon.hpp HumanA.hpp	HumanB.hpp	Makefile
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