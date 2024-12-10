HEADERS = util.h
OBJECTS = main.o util.o
EPATH = ./build/
OPATH = ./build/object/

default: main

%.o: ./%.cpp $(HEADERS)
	g++ -c $< -o $(OPATH)$@

main: $(OBJECTS)
	g++ $(OPATH)*.o -o $(EPATH)$@

clean:
	-rm -f $(OPATH)*.o
	-rm -f $(EPATH)main
