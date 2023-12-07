#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int READLINE_READ_SIZE = 512;

void init_my_readline()
{
    READLINE_READ_SIZE = 1024;
}

char* my_readline(int fd)
{
    char* buf = malloc(READLINE_READ_SIZE + 1 * sizeof(char));
    char* result;
    int i = 0;
    int bytesRead;
    char c;
    while(i < READLINE_READ_SIZE && ((bytesRead = read(fd, &c, sizeof(char))) > 0))
    {
        if(c == '\n' || c == '\0' || c == EOF)
        {
            break;
        }
        else 
        {
            buf[i] = c;
            i++;
        }
    }
    if(bytesRead <= 0)
    {    
        free(buf);
        return NULL;
    }
    buf[i] = '\0';
    // printf("%s\n", buf);
    result = buf;
    return result;
}

// int main (int argc, char** argv)
// {
//     if (argc == 3)
//     {
//         int read_size = atoi(argv[2]);
//         init_my_readline(read_size);
//         char* str = NULL;
//         int count = 0;
//         int fd = open(argv[1], O_RDONLY);
//         if (fd == -1)
//         {
//             printf("error opening file.\n");
//             return 1;
//         }
//         else
//         {
//             printf("Reading from: %s\n", argv[1]);
//         }
//         while (count < READLINE_READ_SIZE && (str = my_readline(fd)) != NULL)
//         {
//             printf("READING FROM FILE: %s\n", argv[1]);
//             printf("%s\n", str);
//             printf("%s\n", "THIS IS A TEST");
//             free(str);
//         }
//         close(fd);
//     }
//     return 0;
// }