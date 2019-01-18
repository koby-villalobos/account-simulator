main : main.o linkedlist.o
	gcc -o main main.o linkedlist.o
main.o : main.c
	gcc -ansi -pedantic-errors -Wall -c main.c
linkedlist.o : linkedlist.c
	gcc -ansi -pedantic-errors -Wall -c linkedlist.c
 
