# This code is part of dotlinker-cpp
# Copyright Jacob Killelea <jkillelea@protonmail.ch>
EXEC         = dotlinker
BUILD-DIR    = build
SRC-DIR      = src
LIB-DIR      = lib
# CFLAGS       += -static-libstdc++
CFLAGS       += -std=c++14
CFLAGS       += -Wall
CFLAGS       += -I$(LIB-DIR)
LFLAGS       += -lstdc++fs
# CC    = g++
CC    = clang++

all: $(EXEC)

remake:
	$(MAKE) purge
	$(MAKE)

clean:
	rm -rf $(BUILD-DIR)

purge:
	rm -f $(EXEC) test
	$(MAKE) clean

test: $(BUILD-DIR)/test.o $(BUILD-DIR)/dotfile.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

$(EXEC): $(BUILD-DIR)/dotlinker-cpp.o $(BUILD-DIR)/dotfile.o
	$(CC) $(CFLAGS) -o $(EXEC) $^ $(LFLAGS)

$(BUILD-DIR)/%.o: $(SRC-DIR)/%.cpp | $(BUILD-DIR)
	$(CC) $(CFLAGS) -c $^ -o $@

$(BUILD-DIR):
	mkdir -p build
