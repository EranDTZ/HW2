Mat = my_mat.o
Main = main.o
CC = gcc
AR = ar -rcs
FLAGS = -Wall -g


Mats: libmat.a
libmat.a: $(Mat)
	$(AR) -o libmat.a $(Mat) 

connections: libmat.a $(Main)
	$(CC) $(FLAGS) -o connections libmat.a $(Main)

main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c 

all: Mats connections main.o


.PHONY: clean all

clean:
	rm -f *.o *.a Mats connections Main.o
