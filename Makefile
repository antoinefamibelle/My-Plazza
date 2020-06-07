##
## EPITECH PROJECT, 2020
## PLAZZA
## File description:
## Makefile
##

.SUFFIXES: .cpp .hpp .o
.DEFAULT_GOAL := all
SHELL         =  /bin/bash

CC 	      = g++

destdir       = ./
srcdir 	      = $(destdir)sources/
headerdir	  = $(destdir)Headers

BIN	      =	plazza

SRC 	      += $(srcdir)main.cpp
SRC 	      += $(srcdir)Cook.cpp
SRC 	      += $(srcdir)Kitchen.cpp
SRC 	      += $(srcdir)Reception.cpp
SRC 	      += $(srcdir)Parser.cpp
SRC 	      += $(srcdir)Communication.cpp
SRC 	      += $(srcdir)Process.cpp
SRC 	      += $(srcdir)Chrono.cpp
SRC			  += $(srcdir)Order.cpp
SRC			  += $(srcdir)StoredIngredient.cpp
SRC			  += $(srcdir)Pizza.cpp
SRC			  += $(srcdir)Thread.cpp
SRC			  += $(srcdir)Log.cpp
SRC			  += $(srcdir)Graphical.cpp


CPPFLAGS      += -I./Headers/ -I./Headers/AbstractClass/

CXXFLAGS      += -Wall
CXXFLAGS      += -Wextra -lpthread -std=c++17

CPPDEBUG      += -g3

FLAGS         += $(CPPFLAGS)
FLAGS         += $(CXXFLAGS)

OBJ	      =	$(SRC:.cpp=.o)

.PHONY: all
all: $(BIN)

$(BIN):	$(OBJ)
	@$(CC) $(FLAGS) -o $@ $^ -lncurses

.PHONY: clean
clean:
	rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	rm -f $(BIN)

.PHONY: re
re: fclean all

.PHONY: memcheck
memcheck: all
	valgrind -v --show-leak-kinds=all --leak-check=full --track-origins=yes $(destdir)$(BIN)

.PHONY: debug
debug: $(FLAGS) += $(CPPDEBUG)
debug: fclean all

print-% :
	@printf $* = $($*)