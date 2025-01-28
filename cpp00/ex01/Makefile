Name = PhoneBook

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp	Phonebook.cpp	is_valid.cpp

OBJ = ${SRC:%.cpp=%.opp}

all: ${Name}

%.opp:%.cpp	Phonebook.hpp
	@${CPP} ${FLAGS} -c $< -o $@

${Name}: ${OBJ}
	@${CPP} ${FLAGS} ${OBJ} -o ${Name}
	@echo "finish"

clean:
	@rm -f ${OBJ}
	@echo "removed objects"

fclean:	clean
	@rm -f ${Name}
	@echo "removed" ${Name}

re: fclean all

.PHONY: clean
