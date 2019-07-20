cppflag = `pkg-config --cflags --libs opencv zbar`
all:
	g++ -c decoder.cpp -o decoder.o $(cppflag) -Wall
	gcc -c testmain.c   -o testmain.o -Wall
	
	gcc decoder.o testmain.o -o APP $(cppflag) -lstdc++
clean:
	rm *.o APP
