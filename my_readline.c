#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>

#define READLINE_READ_SIZE 1

void my_memset(char* buff, char val, int size)
{
    int index = 0;
    while (index < size)
    {
        buff[index] = val;
        index += 1;
    }
}

void my_bzero(void* buff, size_t size)
{
    my_memset(buff, 0, size);
}


int get_next_index(char* leftover, int* offset)
{
    int index = 0;
    while (leftover[index] != '\0')
    {
        if (leftover[index] == '\n')
        {
            break;
        }
        else if (leftover[index] == '\\' && leftover[++index] == 'n')
        {
            *offset = 1;
            break;
        }
        index++;
    }
    return index;
}

char* get_next_content(int fd)
{
    char* content = (char*)malloc(sizeof(char) * (READLINE_READ_SIZE + 1));
    my_bzero(content, strlen(content));
    read(fd, content, READLINE_READ_SIZE);
    return content;
}

void move_string(char* leftover, int index, int offset)
{
    char* buff = (char*)malloc(strlen(leftover) - index + offset);
    my_bzero(buff, strlen(buff));
    strcpy(buff, &leftover[index+offset]);
    my_bzero(leftover, strlen(leftover));
    if(buff[0] == '\n')
    {
        if(strlen(buff) == 1)
        {
            free(buff);
            my_bzero(leftover, strlen(leftover));
            return;
        }
        else
        {
            buff += 1;
        }
    }
    strcpy(leftover, buff);
    free(buff);
}

char* my_readline(int fd)
{
    if (fd < 0) return NULL;
    static char leftover[READLINE_READ_SIZE + 1];               
    char* content = get_next_content(fd);                       
    strcat(leftover, content);                                  
    if(leftover[0] == '\n')                                     
    {
        move_string(leftover, 1, 0);
    }
    else if(strlen(leftover) == 0)                              
    {
        free(content);
        return NULL;
    }
    
    unsigned int index = 0;
    int offset = 0;                                             
                                                                
    index = get_next_index(leftover, &offset);                  

    if(index >= strlen(leftover) && leftover[index] != EOF)     
    {
        while(index >= strlen(leftover))                        
        {
            content = get_next_content(fd);
            if(strlen(content) == 0)                            
            {
                free(content);
                break;
            }
            strcat(leftover, content);                          
            index = get_next_index(leftover, &offset);          
            free(content);
        }
    }

    char* line = malloc(sizeof(char) * (index + 1 - offset));   
    strncpy(line, leftover, index - offset);                    

    move_string(leftover, index, offset);                      
    free(content);
    if(strlen(line) == 0) free(line);                           
    return strlen(line) > 0 ? line : NULL;                      
}

int main()
{
  char *str = NULL;

  int fd = open("./file.txt", O_RDONLY);
  while ((str = my_readline(fd)) != NULL)
  {
      printf(">%s\n", str);
      free(str);
  }
  close(fd);

  return 0;
}