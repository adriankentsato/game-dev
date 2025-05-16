# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O3 -flto -march=native -fomit-frame-pointer -fno-rtti -fno-exceptions -funroll-loops -pipe
LDFLAGS := -flto -ffunction-sections -fdata-sections -Wl,--gc-sections -s

# Directories
SRC_DIR := src
BUILD_DIR := build
BOOST_INCLUDE_DIR := libs/boost/include
SFML_INCLUDE_DIR := libs/sfml/include
BOOST_LIB_DIR := libs/boost/lib
SFML_LIB_DIR := libs/sfml/lib
INCLUDE_DIRS := -I$(SRC_DIR) -I$(BOOST_INCLUDE_DIR) -I$(SFML_INCLUDE_DIR)
LIB_DIRS := -L$(BOOST_LIB_DIR) -L$(SFML_LIB_DIR)
LIBS := -ludev -lX11 -lXcursor -lXrandr -lXi -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lboost_system -lboost_filesystem -lboost_thread

# Find all source files
SOURCES := $(wildcard $(SRC_DIR)/**/*.cpp) $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
TARGET := $(BUILD_DIR)/sfml_game

# Default target
all: $(TARGET)

# Link the final executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LIB_DIRS) $(LIBS) $(LDFLAGS) -o $@
	strip --strip-all $(TARGET)

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -c $< -o $@

# Clean build directory
clean:
	rm -rf $(BUILD_DIR)

# Phony targets
.PHONY: all clean
