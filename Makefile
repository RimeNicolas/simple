HEADERS = util.h
OBJECTS = program.o util.o
EPATH = ./build/

default: program

%.o: ./%.cpp $(HEADERS)
	g++ -c $< -o $(EPATH)$@

program: $(OBJECTS)
	g++ $(EPATH)*.o -o $(EPATH)$@

clean:
	-rm -f $(EPATH)*.o
	-rm -f $(EPATH)program
