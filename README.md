# Description

GNU Readline is a software library that provides in-line editing and history capabilities for interactive programs with a command-line interface, such as Bash. It is currently maintained by Chet Ramey as part of the GNU Project.

It allows users to move the text cursor, search the command history, control a kill ring (a more flexible version of a copy/paste clipboard) and use tab completion on a text terminal. As a cross-platform library, readline allows applications on various systems to exhibit identical line-editing behavior.

GNU Readline is notable for being a free software library which is licensed under the GNU General Public License (GPL). Free software libraries are far more often licensed under the GNU Lesser General Public License (LGPL), for example, the GNU C Library, GNU gettext and FLTK. A developer of an application who chooses to link to an LGPL licensed library can use any license for the application.[3] But linking to a GPL licensed library such as Readline requires the entire combined resulting application to be licensed under the GPL when distributed, to comply with section 5 of the GPL.[4][5]

# Task

If you already played with another higher-level programming language, you know how easy it is to read a line from a file. For example in Python, you can even iterate through the file like for line in file:.

Unfortunately for you, this project will bring you back in the 1970s (again) when no such super power was available.

Fortunately for you, you will discover the concept of global variables and gain a deeper understanding of how the heap and the stack interact with each other.

The function my_readline reads a line from the strean represented by fd and returns it into an allocated string (heap or stack ?). It stops when either the newline character is read or when the end-of-file is reached, whichever comes first. The newline character is not copied to the string.

On success, a pointer to the string is returned. On error, a null pointer is returned. If the end-of-file occurs before any characters have been read, the string remains unchanged.

# Usage

gcc c -o my_readline.c

# Installation

https://github.com/Fzlvm/arc-02-my_readline.git

# Malumotlar Wikipediadan Olingan 