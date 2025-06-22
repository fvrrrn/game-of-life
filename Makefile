CC = gcc

CFLAGS = -Wall -Wextra -Werror -std=c11 -lncurses -g

SRCS = src/controls.c src/graphics.c src/logic.c src/main.c

OBJS = $(SRCS:.c=.o)

TARGET = gof

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
