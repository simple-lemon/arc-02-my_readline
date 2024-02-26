step 1: The READLINE_READ_SIZE variable declared in line 7 is assigned an integer value from 0.

step 2:The file to be read is opened using the open system call through the main function

step 3:The file is read by calling the function my_readline once or repeatedly through a loop, in which the descriptor of the file opened using the open system call is sent to the function

step 4:c fc file is compiled via makefile or this command "gcc -Wall -Wextra -Werror -g3 -fsanitize=address -o my_readline my_readline.c".

step 5:"./" and the output filename are pasted to the terminal.

Don't forget to close the opened file using the close system call.
close is enough to send the opened file descriptor to the system command, and this is done after the file has been read completely.
