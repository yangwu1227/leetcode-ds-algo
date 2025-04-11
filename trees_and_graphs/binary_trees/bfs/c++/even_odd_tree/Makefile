CXX = /usr/bin/g++

# Compiler flags
CXXFLAGS = -std=c++17 -fdiagnostics-color=always

# Source and object file
TARGET = main
MAIN_SRC = main.cpp
OBJS = tree_node.o even_odd_tree.o 

# Rule to build the target executable from main.cpp and object files
$(TARGET): $(MAIN_SRC) $(OBJS)
		$(CXX) $(CXXFLAGS) -o $(TARGET) $(MAIN_SRC) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)
.PHONY: clean
