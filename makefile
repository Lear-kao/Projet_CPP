# ---------- CONFIG ----------
NAME        := game
CXX         := g++
CXXFLAGS    := -Wall -Wextra -std=c++20 -I./HPP
LDFLAGS     := -lsfml-graphics -lsfml-window -lsfml-system

SRC_DIR     := CPP
OBJ_DIR     := OFILE

SRC         := $(wildcard $(SRC_DIR)/*.cpp)
OBJ         := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

# ---------- RULES ----------
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $^ -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
