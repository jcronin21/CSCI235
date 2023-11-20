#CC=gcc
#CFLAGS=
#LDFLAGS =-lm

#my attempt at Makefiles, having some trouble grasping how they work
#SRC_FILES = hellomake.c hellofunc.c
#OBJ_FILES = $(SRC_FILES:.c=.o)

#all: hello

#hello: hellofunc.c hellomake.c


#hellomake.o: hellomake.c
#	gcc -o hellomake.c
#hellofunc.o: hellofunc.c
#	gcc -o hellofunc.c

#clean:
#	rm -rf *o hello


CC = gcc
CFLAGS = -Wall
LDFLAGS = -lm #was missing math library   

SRC = hellomake.c hellofunc.c
OBJ = $(SRC:.c=.o)
TARGET = myprogram

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< #added

clean:
	rm -f $(OBJ) #fixed

distclean: clean
	rm -f $(TARGET) #fixed
