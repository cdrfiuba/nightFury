CC = g++
TESTFLAGS = -lgtest -lpthread
CFLAGS = -Wall -pedantic

OUTPUT = test
TESTINPUT = main.cpp test.cpp ../motor.cpp

all:
	$(CC) $(CFLAGS) $(TESTFLAGS) $(TESTINPUT) -o $(OUTPUT)

.PHONY: clean

clean:
	rm $(OUTPUT)
