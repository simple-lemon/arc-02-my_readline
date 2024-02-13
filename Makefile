CC = gcc 
CFLAGS = -Wall -Wextra -Werror
TARGET = my_readline
OBJ = my_readline.o 
SRC = my_readline.c 

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -f *.o 