CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = sorting_app

SOURCES = main.cpp sorting_algorithms.cpp utils.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)
