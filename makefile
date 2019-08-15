output: main.o ant.o pixelArray.o
	g++ main.o ant.o pixelArray.o -o output -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp

ant.o: ant.cpp headers/ant.h
	g++ -c ant.cpp

pixelArray.o: pixelArray.cpp headers/pixelArray.h
	g++ -c pixelArray.cpp

clean:
	rm *.o output

