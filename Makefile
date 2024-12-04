CC = gcc
TARGET = RunoTL

PKGCONFIG = $(shell which pkg-config)
CFLAGS = -O0 -g3 -Wall $(shell $(PKGCONFIG) --cflags gtk4)
LIBS = $(shell $(PKGCONFIG) --libs gtk4) -L../lib/logger/bin/ -llogger -Wl,-rpath,../lib/logger/bin/

GLIB_COMPILE_RESOURCES = $(shell $(PKGCONFIG) --variable=glib_compile_resources gio-2.0)
GLIB_COMPILE_SCHEMAS = $(shell $(PKGCONFIG) --variable=glib_compile_schemas gio-2.0)

BUILT_SRC = resources.c
OBJECTS = main.o app.o mainwnd.o resources.o

all: $(TARGET)

ru.axel.tl.gschema.valid: ru.axel.tl.gschema.xml
	$(GLIB_COMPILE_SCHEMAS) --strict --dry-run --schema-file=$< && mkdir -p $(@D) && touch $@

gschemas.compiled: ru.axel.tl.gschema.valid
	$(GLIB_COMPILE_SCHEMAS) .

resources.o: resources.c
	$(CC) $(CFLAGS) -c resources.c

resources.c: runoapp.gresource.xml ./src/mainwnd/mainwnd.ui ./src/app_menu/app_menu.ui
	$(GLIB_COMPILE_RESOURCES) runoapp.gresource.xml --target=$@ --sourcedir=. --generate-source

mainwnd.o: ./src/mainwnd/mainwnd.c resources.c
	$(CC) $(CFLAGS) -c ./src/mainwnd/*.c

app.o: ./src/app/app.c
	$(CC) $(CFLAGS) -c ./src/app/*.c

main.o: ./src/main.c
	$(CC) $(CFLAGS) -c ./src/*.c

$(TARGET): $(OBJECTS) gschemas.compiled
	$(CC) -o ./bin/$(TARGET) *.o $(LIBS)

clean:
	rm -f $(BUILT_SRC)
	rm -f *.o
	rm -f org.gtk.exampleapp.gschema.valid
	rm -f gschemas.compiled