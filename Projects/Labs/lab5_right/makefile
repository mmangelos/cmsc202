CXX = g++
CXXFLAGS = -Wall

lab5: Student.o lab5.cpp
	$(CXX) $(CXXFLAGS) Student.o lab5.cpp -o lab5
Student.o: Student.cpp Student.h
	$(CXX) $(CXXFLAGS) -c Student.cpp
