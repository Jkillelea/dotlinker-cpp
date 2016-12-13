# This code is part of dotlinker-cpp
# Copyright Jacob Killelea <jkillelea@protonmail.ch>
EXEC         = dotlinker
BUILD-DIR    = build
SRC-DIR      = src
LIB-DIR      = lib
# NORMAL-CC    = g++
NORMAL-CC    = clang++
ARM-ABI-CC   = arm-linux-gnueabi-g++
ARM-ABIHF-CC = arm-linux-gnueabihf-g++
# CFLAGS       += -static-libstdc++
CFLAGS       += -std=c++14
CFLAGS       += -Wall
CFLAGS       += -I$(LIB-DIR)
LFLAGS       += -lstdc++fs
CC = $(NORMAL-CC)

all: $(EXEC)

clean:
	rm -f $(BUILD-DIR)/*.o

purge:
	rm -f $(EXEC) test
	$(MAKE) clean
	rmdir $(BUILD-DIR)

test: $(BUILD-DIR)/test.o $(BUILD-DIR)/dotfile.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

$(EXEC): $(BUILD-DIR)/dotlinker-cpp.o $(BUILD-DIR)/dotfile.o
	$(CC) $(CFLAGS) -o $(EXEC) $^ $(LFLAGS)

$(BUILD-DIR)/%.o: $(SRC-DIR)/%.cpp | $(BUILD-DIR)
	$(CC) $(CFLAGS) -c $^ -o $@

$(BUILD-DIR):
	mkdir -p build
