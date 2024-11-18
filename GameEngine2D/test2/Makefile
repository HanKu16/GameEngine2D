all:
	g++ -c test.cpp ../src/Engine.cpp ../src/PrimitiveRenderer.cpp ../src/Point2D.cpp ../src/LineSegment.cpp ./Snake.cpp ./Fruit.cpp 
	g++ -o test test.o Engine.o PrimitiveRenderer.o Point2D.o LineSegment.o Snake.o Fruit.o -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm *.o 
