CXX=g++-5
CXXFLAGS=-std=c++14 -Wall -Werror=vla -MMD
OBJECTS=main.o object.o item.o potion.o gold.o basicpotion.o potiondecorator.o restorehealth.o poisonhealth.o boostatk.o woundatk.o boostdef.o wounddef.o floor.o basicfloor.o floordecorator.o tile.o stairs.o wall.o door.o passage.o none.o chamber.o dungeon.o display.o
DEPENDS=$(OBJECTS:.o=.d)
EXEC=cc3k

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXEC)

-include $(DEPENDS)

clean:
	rm *.o cc3k
.PHONY: clean
