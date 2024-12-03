HEADERS = util.h
OBJECTS = program.o
EPATH = ./build/

default: program

%.o: ./%.cpp $(HEADERS)
	g++ -c $< -o $(EPATH)$@

program: $(OBJECTS)
	g++ $(EPATH)$(OBJECTS) -o $(EPATH)$@

clean:
	-rm -f $(EPATH)$(OBJECTS)
	-rm -f $(EPATH)program
