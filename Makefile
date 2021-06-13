#makefile
main: main.o linked_list.o
	gcc -g main.o linked_list.o -o main
	./main

linked_list.o: linked_list.c linked_list.h
	gcc -g -c linked_list.c

clean:
	rm *.o main