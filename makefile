OUT=mkfl
OBJS=input.o main.o makefileS.o output.o 
CXX=g++
CXXFLAGS=
EXECUTION_PARAMETERS=

all: $(OUT)

$(OUT): $(OBJS)
	$(CXX) -o $(OUT) $(OBJS)

%.o: %.c
	$(CXX) -c -o $@ $<

run: $(OUT)
	./$(OUT) $(EXECUTION_PARAMETERS)


install: $(OUT)
	sudo cp $(OUT) /usr/local/bin
	@echo Program Installed in /usr/local/bin
	@echo You can now delete this folder safely

db: clean param
param: CXXFLAGS += -g
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
