NAME = avm
CC = clang++ -std=c++11
FLAGS = #-Wall -Wextra -Werror

SRC_PATH = ./src/
INC_PATH = ./include/
BUILD_PATH = ./build/

INC = IOperand.hpp \
      Parser.hpp  \
      AvmParseException.hpp \
      AbstractVm.hpp

SRC = main.cpp \
      AvmParseException.cpp \
      AbstractVm.cpp

OBJ = $(SRC:.cpp=.o)
OBJ_SRC = $(addprefix $(BUILD_PATH), $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ_SRC)
	$(CC) $(FLAGS) $(OBJ_SRC) -o $(NAME)

$(BUILD_PATH)%.o : $(SRC_PATH)%.cpp
	@/bin/mkdir -p $(BUILD_PATH)
	@$(CC) $(FLAGS) -I$(INC_PATH) -c -o $@ $<

clean:
	@/bin/rm -rf $(BUILD_PATH)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all