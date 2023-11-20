CC = gcc
CFLAGS = -Wall
LDFLAGS = -lm

SRC = hellomake.c hellofunc.c
OBJ = $(SRC:.c=.o)
TARGET = makethefile

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<
clean:
	rm -f $(OBJ) $(TARGET)
