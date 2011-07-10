TEST_NAME := $(notdir $(abspath .))
BIN := ../bin/$(TEST_NAME)

SOURCES += ../seatest/seatest.c
SOURCES += $(wildcard *.c)

OBJECTS := $(SOURCES:.c=.o)

CFLAGS := -MD -g -I../seatest `pkg-config --cflags gtk+-2.0` -DTEST
LDFLAGS := `pkg-config --libs gtk+-2.0` -lncursesw -lmagic

$(BIN): $(addprefix bin/, $(notdir $(OBJECTS)))
	gcc -o $@ $^ $(LDFLAGS)

bin/%.o: %.c
	gcc -c -o $@ $< $(CFLAGS)

bin/%.o: ../../src/%.c
	gcc -c -o $@ $< $(CFLAGS)

bin/%.o: ../seatest/%.c
	gcc -c -o $@ $< $(CFLAGS)

include $(wildcard bin/*.d)