Name = test

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Account.cpp tests.cpp

OBJ = ${SRC:%.cpp=%.opp}

all: ${Name}

%.opp:%.cpp Account.hpp
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
