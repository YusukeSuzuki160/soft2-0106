CC = gcc

BINDIR = bin
INCLUDEDIR = include
SRCDIR = src

CFLAGS = -Wall -I $(INCLUDEDIR)

SRCS = src/fibo.c src/main.c src/matrix.c
OBJS = $(SRCS:%.c=%.o)
TESTS = src/matrix.c src/test.c
TARGET = $(BINDIR)/fibo

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)

test:
	$(CC) $(CFLAGS) -o test $(TESTS)

.PHONY: tmpclean clean

tmpclean:
	rm -f $(SRCDIR)/*~ *~
clean: tmpclean
	rm -f $(TARGET) $(OBJS) test