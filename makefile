Mat = my_mat.o
Main = main.o
CC = gcc
AR = ar -rcs
FLAGS = -Wall -g


Mats: libmat.a
libmat.a: $(Mat)
	$(AR) -o libmat.a $(Mat) 

Mains: libmat.a $(Main)
	$(CC) $(FLAGS) -o Mains libmat.a $(Main)

main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c 

connections: libmat.a Main.o 
	$(CC) $(FLAGS) libmat.a Main.o -o connections -lm

all: Mats Mains main.o


.PHONY: clean all

clean:
	rm -f *.o *.a Mats Mains Main.o
