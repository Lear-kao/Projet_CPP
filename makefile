# ---------- CONFIG ----------
NAME        := game
CXX         := g++
SRC_DIR     := CPP
OBJ_DIR     := OFILE

CXXFLAGS    := -Wall -Wextra -std=c++20 -I./HPP 
DEBUGFLAGS  := -g -O0 -fno-omit-frame-pointer -D_GLIBCXX_DEBUG
LDFLAGS     := -lsfml-graphics -lsfml-window -lsfml-system

SRC         := $(wildcard $(SRC_DIR)/*.cpp)
OBJ         := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

# ---------- RULES ----------
all: debug

debug: CXXFLAGS += $(DEBUGFLAGS)
debug: $(NAME)

release: CXXFLAGS += -O3
release: $(NAME)

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
