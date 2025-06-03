##
## EPITECH PROJECT, 2024
## 42sh
## File description:
## test
## test
##

CC = gcc
CFLAGS = -g3 -I./
EXEC = 42sh
SRC_FILES = $(wildcard *.c)
OBJ_FILES = $(SRC_FILES:.c=.o)

all:
	@(gcc -o $(EXEC) $(SRC_FILES) -O3 -fno-builtin $(CFLAGS))

clean:
	@(rm -f $(EXEC))

fclean: clean

re :	fclean all
