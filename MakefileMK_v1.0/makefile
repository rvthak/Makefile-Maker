OUT=alpha
OBJS=input.o main.o makefileS.o output.o 
CC=g++

all: $(OUT)

$(OUT): $(OBJS)
	$(CC) $(COMPILATION_PARAMETERS) -o $(OUT) $(OBJS)

%.o: %.c
	$(CC) -c -o $@ $< $(COMPILATION_PARAMETERS)

run: $(OUT)
	./$(OUT) $(EXECUTION_PARAMETERS)

db: clean param
param: COMPILATION_PARAMETERS += -g
param: $(OUT)

gdb: db
	gdb $(OUT)

vg: db
	valgrind $(EXECUTION_PARAMETERS) ./$(OUT)

vgleak: db
	valgrind --leak-check=full ./$(OUT) $(EXECUTION_PARAMETERS)

vgext: db
	valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=high --track-origins=yes --vgdb=yes ./$(OUT) $(EXECUTION_PARAMETERS)

.PHONY: clean
clean:
	rm -f *.o
