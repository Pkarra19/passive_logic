# Flags and directories
CC = gcc
CFLAGS = -Wall -Wextra

THIS_DIR = $(PWD)
EXE = state_machine
TEST = test
DIRECTIVE = SIMULATE

# Ignored making .o files just create exe

all: state_machine test

state_machine:
	$(CC) $(CFLAGS) -o $(EXE) -D$(DIRECTIVE) $(THIS_DIR)/state_machine.c

clean:
	rm -rf $(EXE)
	rm -rf $(TEST)

test:
	$(CC) $(CFLAGS) -o $(TEST) $(THIS_DIR)/state_machine.c $(THIS_DIR)/test.c

help:
	@echo "make all - build an exe"
	@echo "make clean - clean the build"
	@echo "make test - build test file exe"

.PHONY: state_machine clean test help