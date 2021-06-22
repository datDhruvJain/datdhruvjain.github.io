shape: shapes.o shapes_util.o
	g++ shapes.o shapes_util.o -o math

shapes.o: shapes.cpp
	g++ -c shapes.cpp

shapes_util.o: shapes_util.cpp
	g++ -c shapes_util.cpp

clean:
	rm *.o