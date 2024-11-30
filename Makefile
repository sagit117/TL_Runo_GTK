CC = gcc
TARGET = RunoTL
CFLAGS = -O0 -g3 -Wall $(shell pkg-config --cflags gtk4)
LIBS = $(shell pkg-config --libs gtk4) -L../lib/logger/bin/ -llogger -Wl,-rpath,../lib/logger/bin/

all: $(TARGET)

main.o: ./src/main.c
	$(CC) $(CFLAGS) -c ./src/*.c

# %.o: %.c
# 	$(CC) $(CFLAGS) -c ./src/*.c

$(TARGET): main.o
	$(CC) -o ./bin/$(TARGET) *.o $(LIBS)

clean:
	rm -f *.o