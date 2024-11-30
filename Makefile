CC = gcc
TARGET = RunoTL
CFLAGS = -O0 -g3 -Wall $(shell pkg-config --cflags gtk4)
LIBS = $(shell pkg-config --libs gtk4) -L../lib/logger/bin/ -llogger -Wl,-rpath,../lib/logger/bin/
OBJECTS = main.o mainwnd.o app.o app_menu.o

all: $(TARGET)

mainwnd.o: ./src/mainwnd/mainwnd.c
	$(CC) $(CFLAGS) -c ./src/mainwnd/*.c

app_menu.o: ./src/app_menu/app_menu.c
	$(CC) $(CFLAGS) -c ./src/app_menu/*.c

app.o: ./src/app/app.c
	$(CC) $(CFLAGS) -c ./src/app/*.c

main.o: ./src/main.c
	$(CC) $(CFLAGS) -c ./src/*.c

$(TARGET): $(OBJECTS)
	$(CC) -o ./bin/$(TARGET) *.o $(LIBS)

clean:
	rm -f *.o