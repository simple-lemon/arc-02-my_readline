FLAGS = -g3 -fsanitize=address -Wall -Wextra -Werror
G = gcc
TARGET = my_readline
SRC = my_readline.c

$(TARGET) : $(SRC)
	@$(G)  -o $(TARGET) $(SRC)

.PHONY : fclean
fclean :
	@rm -rf $(TARGET)