# Compilateur
CC := g++

# Options de compilation
WFLAGS := -Wall -Wextra -pedantic
SFLAGS := -std=c++17
IFLAGS := -I include $(shell pkg-config --cflags cairo gtk+-3.0 librsvg-2.0 tinyxml2)
LFLAGS := $(shell pkg-config --libs cairo gtk+-3.0 librsvg-2.0 tinyxml2) -lcbor -pthread

#Compilateur final
COMPILEUR_SERVER := $(CC) $(SFLAGS) $(IFLAGS)
COMPILEUR_CLIENT := $(CC) $(SFLAGS) -I include

#Noms des fichiers
FILES_SERVER = main server serverUI XMLController
SRC_SERVER = $(addprefix src/, $(FILES_SERVER:=.cpp))
OBJ_SERVER = $(addprefix obj/, $(FILES_SERVER:=.o))
NAME_SERVER = server
EXEC_SERVER := $(addprefix bin/, $(NAME_SERVER))

FILES_CLIENT = client
SRC_CLIENT = $(addprefix src/, $(FILES_CLIENT:=.cpp))
OBJ_CLIENT = $(addprefix obj/, $(FILES_CLIENT:=.o))
NAME_CLIENT = client
EXEC_CLIENT := $(addprefix bin/, $(NAME_CLIENT))

SRC := $(SRC_SERVER) $(SRC_CLIENT)
OBJ := $(OBJ_SERVER) $(OBJ_CLIENT)

# règle de compilation
default : prepare main

all : clean default run

main : $(OBJ)
	$(COMPILEUR_SERVER) -o $(EXEC_SERVER) $(OBJ_SERVER) $(LFLAGS)
	@echo "Server created !"
	$(COMPILEUR_CLIENT) -o $(EXEC_CLIENT) $(OBJ_CLIENT) -lcbor
	@echo "Client created !"


obj/%.o : src/%.cpp
	$(COMPILEUR_SERVER) -o $@ -c $<

run :
	valgrind --leak-check=full --track-origins=yes $(EXEC_CLIENT) 127.0.0.1 6000
	valgrind --leak-check=full --track-origins=yes $(EXEC_SERVER) 6000

prepare :
	test -d obj || mkdir obj
	test -d bin || mkdir bin

clean :
	rm -rf obj bin

debug :
	@echo $(FILES_SERVER)
	@echo $(SRC_SERVER)
	@echo $(OBJ_SERVER)
	@echo $(NAME_SERVER)
	@echo $(EXEC_SERVER)

	@echo $(FILES_CLIENT)
	@echo $(SRC_CLIENT)
	@echo $(OBJ_CLIENT)
	@echo $(NAME_CLIENT)
	@echo $(EXEC_CLIENT)

	@echo $(SRC)
	@echo $(OBJ)
