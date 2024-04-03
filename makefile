
calc: calc.o rpn.o stack.o
	  gcc -o calc calc.o rpn.o stack.o

calc.o: calc.c rpn.h 
		gcc -c calc.c

rpn.o: rpn.h rpn.c stack.h
	   gcc -c rpn.c 

stack.o: stack.h stack.c 
		 gcc -c stack.c 