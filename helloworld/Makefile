CC = gcc
OBJS = helloworld1.o calc_magicnumber.o

CFLAGS = -Wall

TARGET = helloworld1

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f $(OBJS) $(TARGET)