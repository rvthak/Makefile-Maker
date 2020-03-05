OUT=mk3
OBJS=makefileMKv1_0.o inputManager.o makefileADT.o strQueue.o
CC=gcc
COMPILATION_PARAMETERS=
EXECUTION_PARAMETERS=

all: $(OUT)

$(OUT): $(OBJS)
	$(CC) $(COMPILATION_PARAMETERS) -o $(OUT) $(OBJS)

%.o: %.c
	$(CC) -c -o $@ $< $(COMPILATION_PARAMETERS)

# run the program
run: $(OUT)
	./$(OUT) $(EXECUTION_PARAMETERS)

# Debugging
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

# Clean up
.PHONY: clean
clean:
	rm -f *o