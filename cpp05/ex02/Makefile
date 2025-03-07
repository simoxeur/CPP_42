NAME	= prog

CPP		= c++

FLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp	Bureaucrat.cpp AForm.cpp	ShrubberyCreationForm.cpp	RobotomyRequestForm.cpp	PresidentialPardonForm.cpp

OBJS	=		${SRCS:.cpp=.opp}

all: $(NAME)

%.opp:%.cpp Bureaucrat.hpp AForm.hpp	ShrubberyCreationForm.hpp	RobotomyRequestForm.hpp	PresidentialPardonForm.hpp	Makefile
	@$(CPP) ${FLAGS} -c $< -o $@

$(NAME): 		${OBJS}
	@$(CPP) ${FLAGS} ${OBJS} -o ${NAME}
	@echo "finished";

clean:
	@rm -f ${OBJS}
	@echo "removed files";

fclean: 	clean
	@rm -f $(NAME)
	@echo "removed" ${NAME};

re:		fclean all

.PHONY: clean