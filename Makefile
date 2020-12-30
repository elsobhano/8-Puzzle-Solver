CXX = g++
CXXFLAGS = -std=c++17 -Wall -c	-O3
LXXFLAGS = -std=c++17
OBJECTS = main.o	bfs.o	dfs.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET) 
main.o: main.cpp	bfs.h		bfs.cpp		dfs.h	dfs.cpp
	$(CXX) $(CXXFLAGS) main.cpp
bfs.o:	bfs.cpp
	$(CXX) $(CXXFLAGS) bfs.cpp
dfs.o:	dfs.cpp
	$(CXX) $(CXXFLAGS) dfs.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)
