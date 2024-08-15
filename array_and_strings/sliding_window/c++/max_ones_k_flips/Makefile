CXX = /usr/bin/g++

# Compiler flags
CXXFLAGS = -std=c++17 -fdiagnostics-color=always -I/opt/homebrew/Cellar/boost/1.85.0/include -I/opt/homebrew/Cellar/eigen/3.4.0_1/include/eigen3

# Linker flags
LDFLAGS = -L/opt/homebrew/Cellar/boost/1.85.0/lib -lboost_system

# Source and object files
TARGET = main
MAIN_SRC = main.cpp
OBJS = custom_bn_rng.o max_ones_k_flips.o

# Rule to build the target executable from main.cpp and object files
$(TARGET): $(MAIN_SRC) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(MAIN_SRC) $(OBJS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJS)
.PHONY: clean
