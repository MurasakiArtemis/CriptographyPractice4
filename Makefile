all: ModifiedDES.out

ModifiedDES.out: ModifiedDES.c des.o
	g++ des.o ModifiedDES.c -o ModifiedDES.out
des.o: des.c des.h
	g++ des.c -c
