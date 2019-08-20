CC = g++
CFLAGS = -lsodium
all:
	$(CC) -o testBinary test.cpp $(CFLAGS)
clean:
	-rm -f testBinary