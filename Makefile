CC = gcc
TARGET = RunoTL
PKGCONFIG = $(shell which pkg-config)
CFLAGS = -O0 -g3 -Wall $(shell $(PKGCONFIG) --cflags gtk4)
LIBS = $(shell $(PKGCONFIG) --libs gtk4) -L../lib/logger/bin/ -llogger -Wl,-rpath,../lib/logger/bin/
OBJECTS = main.o mainwnd.o app.o app_menu.o resources.o
GLIB_COMPILE_RESOURCES = $(shell $(PKGCONFIG) --variable=glib_compile_resources gio-2.0)
BUILT_SRC = resources.c

all: $(TARGET)

resources.o: resources.c
	$(CC) $(CFLAGS) -c resources.c

resources.c: runoapp.gresource.xml ./src/mainwnd/mainwnd.ui
	$(GLIB_COMPILE_RESOURCES) runoapp.gresource.xml --target=$@ --sourcedir=. --generate-source

mainwnd.o: ./src/mainwnd/mainwnd.c resources.c
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
	rm -f $(BUILT_SRC)
	rm -f *.o