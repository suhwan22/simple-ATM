NAME = simpleATM

CXX = g++
CXXFLAGS = -std=c++17

SRC_DIR = ./src

SRC_FILE = Account.cpp \
					SimpleATM.cpp \
					Bank.cpp \
	  			main.cpp

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJ = $(SRC:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	@$(RM) $(OBJ) $(NAME);

re:	clean all

.PHONY: all clean re
