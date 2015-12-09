all: ieee754
	
ieee754: main.cpp
	g++ main.cpp -o ieee754

clean:
	rm ieee754