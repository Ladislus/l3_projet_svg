# Compilateur
CC := g++
# Options de compilation
WFLAGS := -Wall -Wextra -pedantic
SFLAGS := -std=c++17
IFLAGS := -I include -I/usr/include/gtk-3.0 -I/usr/include/at-spi2-atk/2.0 -I/usr/include/at-spi-2.0 -I/usr/include/dbus-1.0 -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include -I/usr/include/gtk-3.0 -I/usr/include/gio-unix-2.0/ -I/usr/include/cairo -I/usr/include/pango-1.0 -I/usr/include/harfbuzz -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/librsvg-2.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/libpng16 -I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/freetype2 -I/usr/include/libpng16
TFLAGS := -pthread
LFLAGS := -lgtk-3 -lgdk-3 -lpangocairo-1.0 -lpango-1.0 -latk-1.0 -lcairo-gobject -lrsvg-2 -lm -lgio-2.0 -lgdk_pixbuf-2.0 -lgobject-2.0 -lglib-2.0 -lcairo -ltinyxml2


#Compilateur final
COMPILEUR := $(CC) $(SFLAGS) $(TFLAGS) $(IFLAGS)

#Noms des fichiers
FILES = $(notdir $(basename $(wildcard src/*.cpp)))
SRC = $(addprefix src/, $(FILES:=.cpp))
OBJ = $(addprefix obj/, $(FILES:=.o))
EXECUTABLE := exec

# règle de compilation
default : prepare main

all : clean default run

main : $(OBJ)
	$(COMPILEUR) -o $(EXECUTABLE) $^ $(LFLAGS)

obj/%.o : $(SRC)
	$(COMPILEUR)  -o $@ -c $<

run :
	valgrind --leak-check=full ./$(EXECUTABLE)

prepare :
	test -d obj || mkdir obj

clean :
	rm -rf obj $(EXECUTABLE)

debug :
	@echo $(FILES)
	@echo $(SRC)
	@echo $(OBJ)
