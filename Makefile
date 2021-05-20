##
## EPITECH PROJECT, 2021
## B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
## File description:
## Makefile
##

## USEFUL DEF ########################

CC		=	g++
RM		=	-rm -rf
EXT		=	.cpp

## BIN DEF ########################

BIN_INDIE	=	indie
TEST_BIN	=	unit_tests

## OBJ DEF ########################

SRC_DIR		=	./src

ERROR_DIR	=	./Error

MAIN_FILE	=	Indie

INDIE_FILES	=	RaylibEncapsulation/RaylibEncapsulation

ERROR_FILES	=	Error

SRC			=	$(addsuffix $(EXT), $(MAIN_FILE))	\
				$(addsuffix $(EXT), $(addprefix $(SRC_DIR)/, $(INDIE_FILES)))	\
				$(addsuffix $(EXT), $(addprefix $(ERROR_DIR)/, $(ERROR_FILES)))

INDIE_OBJ	=	$(SRC:.cpp=.o)

## FLAGS DEF ########################

CXXFLAGS	=	-W -Wextra -Wall #Werror

CPPFLAGS	=	-I./Error -I./src

LDFLAGS		=	-lraylib -O2 -lGL -lm -lpthread -ldl -lrt -lX11

## COMPILATION DEF ########################

%.o:    %.cpp
	@$(CC) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) -c -o $@ $<
	@printf "[\033[0;32mcompiled\033[0m] % 29s\n" $< | tr ' ' '.'

all: $(BIN_INDIE)

$(BIN_INDIE): $(INDIE_OBJ)
	@echo Compiled with $(CXXFLAGS) and $(LDFLAGS)
	@$(CC) -o $(BIN_INDIE) $(INDIE_OBJ) $(LDFLAGS)
	@printf "[\033[0;36mbuilt\033[0m] % 32s\n" $(BIN_INDIE) | tr ' ' '.'

clean:
	@$(RM) *~ $(INDIE_OBJ)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(INDIE_OBJ) | tr ' ' '.'

fclean: clean
	@$(RM) $(BIN_INDIE)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(BIN_INDIE) | tr ' ' '.'

debug:  CXXFLAGS += -g3
debug:	re

re:	fclean all

.PHONY: all clean fclean debug re