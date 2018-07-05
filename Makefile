connectn.out: main.o board.o win.o input_val.o minimax.o
	gcc -g -Wall -Werror -o connectn.out main.o board.o win.o input_val.o minimax.o
	
board.o: board.c board.h
	gcc -g -Wall -Werror -c -o board.o board.c
	
main.o: main.c board.h win.h input_val.h minimax.h
	gcc -g -Wall -Werror -c -o main.o main.c
	
win.o: win.c win.h 
	gcc -g -Wall -Werror -c -o win.o win.c
	
input_val.o: input_val.c input_val.h
	gcc -g -Wall -Werror -c -o input_val.o input_val.c

minimax.o: minimax.c minimax.h
	gcc -g -Wall -Werror -c -o minimax.o minimax.c

clean:
	rm -f *.o 
