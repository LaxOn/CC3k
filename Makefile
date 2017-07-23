CXX=g++-5
CXXFLAGS=-std=c++14 -Wall -Werror=vla -MMD
OBJECTS=main.o character.o dragonNPC.o drowPC.o dwarfNPC.o elfNPC.o goblinPC.o halflingNPC.o humanNPC.o merchantNPC.o npc.o object.o orcNPC.o pc.o shadePC.o trollPC.o vampirePC.o
DEPENDS=$(OBJECTS:.o=.d)
EXEC=cc3k

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXEC)

-include $(DEPENDS)

clean:
	rm *.o *.d
.PHONY: clean
