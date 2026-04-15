CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -O2 -g
TARGET = test_hash

SRCS = hash.c test_hash.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c hash.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)