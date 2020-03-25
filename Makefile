snl.out: main.cpp SNL.h SNL.cpp
	g++ -std=c++11 -o snl main.cpp SNL.cpp

clean:
	rm snl
