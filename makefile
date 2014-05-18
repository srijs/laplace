HEADERS = entity.h atom.h uuid.h
OBJECTS = entity.o atom.o uuid.o
TESTS   = tests/uuid.c

default: laplace

%.o: %.c $(HEADERS)
	%(CC) -Os -c $< -o $@

laplace: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

test: $(OBJECTS) test.c $(TESTS)
	$(CC) test.c $(TESTS) $(OBJECTS) -o test
	./test

clean:
	-rm -f $(OBJECTS)
	-rm -f laplace
