all:
	g++ -c test.cpp ../src/Engine.cpp ../src/PrimitiveRenderer.cpp ../src/Point2D.cpp ../src/LineSegment.cpp ../src/shapes.cpp
	g++ -o test test.o Engine.o PrimitiveRenderer.o Point2D.o LineSegment.o shapes.o -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm *.o 
