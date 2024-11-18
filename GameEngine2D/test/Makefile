all:
	g++ -c test.cpp ../src/Engine.cpp ../src/PrimitiveRenderer.cpp ../src/Point2D.cpp ../src/LineSegment.cpp ../src/shapes.cpp ../src/BitmapObject.cpp
	g++ -o test test.o Engine.o PrimitiveRenderer.o Point2D.o LineSegment.o shapes.o BitmapObject.o -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm *.o 
