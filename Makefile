#mail: itzhak173@gmail.com

CXX = clang++
CXXFLAGS = -std=c++2a -Wall -Wextra -g

SRC = main.cpp Graph.cpp Algorithms.cpp
OBJ = $(SRC:.cpp=.o)

TEST_SRC = tests.cpp Graph.cpp Algorithms.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)

TARGET = program
TEST_TARGET = tests

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

$(TEST_TARGET): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Main: $(TARGET)
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

clean:
	rm -f *.o $(TARGET) $(TEST_TARGET)
