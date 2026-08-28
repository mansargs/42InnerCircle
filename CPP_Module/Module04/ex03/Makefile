NAME = AMateria

CXX = c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp
HDR = AMateria.hpp Ice.hpp Cure.hpp Character.hpp ICharacter.hpp IMateriaSource.hpp \
		MateriaSource.hpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXX_FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp $(HDR)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
