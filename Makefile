#makefile
main_test: main_test.o linked_list.o
	gcc -g main_test.o linked_list.o -o maintest

linked_list.o: linked_list.c linked_list.h
	gcc -g -c linked_list.c

clean:
	rm *.o maintest
	
