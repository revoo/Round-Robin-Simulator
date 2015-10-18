# Complier flags
CCFLAGS = -ansi -Wall -std=c99 -ggdb

# Rule to link object code files to create executable file
assign4: assign4.o queue.o 
	gcc $(CCFLAGS) -o assign4 assign4.o queue.o 

# Rules to compile source code files to object code
assign4.o: assign4.c queue.h process.h
	gcc $(CCFLAGS) -c assign4.c

queue.o: queue.c queue.h process.h
	gcc $(CCFLAGS) -c queue.c

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign4
