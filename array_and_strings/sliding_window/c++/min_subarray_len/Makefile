CXX = /usr/bin/g++

# Compiler flags
CXXFLAGS = -std=c++17 -fdiagnostics-color=always -I/opt/homebrew/include

# Source and object files
TARGET = main
MAIN_SRC = main.cpp
OBJS = min_subarray_len.o

# Rule to build the target executable from main.cpp and object files
$(TARGET): $(MAIN_SRC) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(MAIN_SRC) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJS)
.PHONY: clean
