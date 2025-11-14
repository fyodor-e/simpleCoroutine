CPPFLAGS = -fcoroutines -std=c++20 -O0 -g 
LFLAGS = 
SRC_DIR := ./
OBJ_DIR := ./obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
DIRS = $(subst /,/,$(sort $(dir $(OBJ_FILES))))

coroutine:	$(OBJ_DIR)/coroutine

$(OBJ_DIR)/coroutine: $(OBJ_FILES)
	g++ -o $@ $^ ${LFLAGS}

mkdir:
	mkdir -p $(DIRS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ -c -o $@ $< $(CPPFLAGS)

.PHONY : clean
clean :
	rm -r obj
	mkdir -p obj