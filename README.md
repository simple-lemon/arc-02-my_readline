# Task

To create an implementation of function called readline that is part of the GNU Readline library.

# Description

In this porject I created some functions that are:
• int my_strlen() - it calculates length of given string as well as it is implementation of strlen() function;
• int check_n() - this function checks for '\n', to print next new line after coming in to '\n';
• char*strn_cpy() - to copy a certain number of characters from one string to another by given numbers;
• char* str_cpy() - to copy  all characters from one string to other, using pointers;
• void fill_with_nl() - this  function fills up the buffer with '\n' till it reaches its size limit;
• char*my_realloc() -  this function reallocates memory if needed and returns pointer to newly allocated memory or NULL on failure;
• void init_my_readline() -  initializes my own version of readline and sets up necessary variables;
• char*my_readline(int fd) -  reads input from file descriptor 'fd' into the user’s terminal until '\n'. It returns a pointer to the beginning of the line stored in memory.First it reads all data from file and divides and prints each line until reaches '\n'.
The main function 'readline' was implemented according to the description.

# Installation

Write make on terminal which will create other files via Makefile

# Usage

Call ./my_readline and 'filename'
