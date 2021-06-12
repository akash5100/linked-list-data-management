#makefile
helper: helper.c helper.h
	gcc -g helper.c helper.h
	./a.out

clean:
	rm *.out *.gch
	
