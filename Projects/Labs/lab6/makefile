CXX = g++
CXXFLAGS = -Wall

lab6: Item.o lab6.cpp
	$(CXX) $(CXXFLAGS) Item.o lab6.cpp -o lab6

Item.o: Item.cpp Item.h
	$(CXX) $(CXXFLAGS) -c Item.cpp
