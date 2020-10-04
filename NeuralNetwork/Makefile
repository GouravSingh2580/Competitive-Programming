CC=g++
IPATH=-Iinc/
SRC=src
OBJ=obj
BIN=bin
FLAGS=-std=c++2a

SRC_FILES=$(wildcard $(SRC)/*.cpp)
OBJ_FILES=$(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SRC_FILES))

all: app
	@echo "Sucess"

clean:
	@rm -rf $(OBJ)*.o $(BIN)*

run:
	@$(BIN)/app

dev: app
	@$(BIN)/app

app: $(OBJ_FILES)
	@$(CC) -o $(BIN)/$@ $^ $(FLAGS)

$(OBJ)/%.o: $(SRC)/%.cpp
	@$(CC) $(IPATH) $(FLAGS) -c -o $@ $<