# Description

If you already played with another higher-level programming language, you know how easy it is to read a line from a file. For example in Python, you can even iterate through the file like for line in file:.

Unfortunately for you, this project will bring you back in the 1970s (again) when no such super power was available.

Fortunately for you, you will discover the concept of global variables and gain a deeper understanding of how the heap and the stack interact with each other.



# Task

Your code must be compiled with the flags -Wall -Wextra -Werror.

In order to start reading another file you will also produce a function: void init_my_readline() which will init (or reinitialize) your global variable.

In the case of reinitialize, you will, obviously, free allocated resources. :-)

int READLINE_READ_SIZE = 512;
int main(int ac, char av)
{
char *str = NULL;


int fd = open("./file.txt", O_RDONLY);
while ((str = my_readline(fd)) != NULL)
{
printf("%s\n", str);
free(str);
}
close(fd);
//
//  Yes it's also working with stdin :-)
//  printf("%s", my_readline(0));
//


return 0;
}

# Installation

# Usage
