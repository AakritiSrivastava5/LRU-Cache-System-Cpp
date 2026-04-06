CXX = g++
CXXFLAGS = -std=c++17 -Iinclude

SRC = src/main.cpp src/LRUCache.cpp
OUT = lru

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

run:
	./$(OUT)

clean:
	rm -f $(OUT)
