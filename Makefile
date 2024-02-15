CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
SRC = my_readline.c
TARGET = my_readline

$(TARGET): $(SRC)
  @$(CC) $(CFLAGS) -o $@ $^


.PHONY: fclean

fclean:
  @rm -r $(TARGET)

clean:
  @rm -rf $(TARGET)

run:
  @./$(TARGET)
