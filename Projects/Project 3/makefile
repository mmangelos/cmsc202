CXX = g++
CXXFLAGS = -Wall

proj4: BabyDragon.o Entity.o Character.o Game.o Goblin.o Monster.o Paladin.o Rogue.o Room.o Skeleton.o Wizard.o proj4.cpp
	$(CXX) $(CXXFLAGS) BabyDragon.o Entity.o Character.o Game.o Goblin.o Monster.o Paladin.o Rogue.o Room.o Skeleton.o Wizard.o proj4.cpp -o proj4

Game.o: Room.o Entity.o Monster.o Character.o Goblin.o Skeleton.o BabyDragon.o Rogue.o Wizard.o Paladin.o Game.h Game.cpp
	$(CXX) $(CXXFLAGS) -c Game.cpp

BabyDragon.o: BabyDragon.h BabyDragon.cpp
	$(CXX) $(CXXFLAGS) -c BabyDragon.cpp

Goblin.o: Goblin.h Goblin.cpp
	$(CXX) $(CXXFLAGS) -c Goblin.cpp

Skeleton.o: Skeleton.h Skeleton.cpp
	$(CXX) $(CXXFLAGS) -c Skeleton.cpp

Paladin.o: Paladin.h Paladin.cpp
	$(CXX) $(CXXFLAGS) -c Paladin.cpp

Rogue.o: Rogue.h Rogue.cpp
	$(CXX) $(CXXFLAGS) -c Rogue.cpp

Wizard.o: Wizard.h Wizard.cpp
	$(CXX) $(CXXFLAGS) -c Wizard.cpp

Character.o: Character.h Character.cpp Paladin.o Rogue.o Wizard.o
	$(CXX) $(CXXFLAGS) -c Character.cpp

Monster.o: Monster.h Monster.cpp BabyDragon.o Goblin.o Skeleton.o
	$(CXX) $(CXXFLAGS) -c Monster.cpp

Entity.o: Entity.h Entity.cpp
	$(CXX) $(CXXFLAGS) -c Entity.cpp

Room.o: Room.h Room.cpp
	$(CXX) $(CXXFLAGS) -c Room.cpp

run1:
	./proj4 map1_data.txt

run2:
	./proj4 map2_data.txt

val1:
	valgrind ./proj4 map1_data.txt

val2:
	valgrind ./proj4 map2_data.txt

clean:
	rm *.o*
	rm *~
