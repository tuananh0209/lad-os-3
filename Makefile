all : ex1.o
	gcc ex1.o -o ex1
main.0 : ex1.c
	gcc -c ex1.c
clean: 
	rm -f ex1 ex2 *.o *.chg