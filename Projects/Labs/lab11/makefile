CXX = g++
CXXFLAGS = -Wall -g

lab11: Outlet.o lab11.cpp
	$(CXX) $(CXXFLAGS) Outlet.o lab11.cpp -o lab11

Outlet.o: Outlet.h Outlet.cpp
	$(CXX) $(CXXFLAGS) -c Outlet.cpp

clean:
	rm *.o
	rm *~

run:
	./lab11

val1:
	valgrind ./lab11
