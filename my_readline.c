#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int READLINE_READ_SIZE = 6;
char* store;

typedef struct listnode
{
    int size;
    int count;
    char* text;
} list;

char* my_strcpy(char* str1, char* str2) {
    for(int i = 0; str2[i]; i++) {
        str1[i] = str2[i];
    }
    return str1;
}

int my_strlen(char* string)
{
    int i = 0;
    while(string[i] != '\0')
        i++;
    return i;
}

void fill_null(char* string, int length)
{
    int i = 0;
    while(i <= length)
    {
        string[i] = '\0';
        i++;
    }
}

char* my_realloc(char* content, int over)
{
    char* temp = malloc(sizeof(char) * over + 1 + READLINE_READ_SIZE);
    fill_null(temp, over + READLINE_READ_SIZE);
    my_strcpy(temp, content);
    free(content);
    return temp;
}

void copy_store(char* after_new_line)
{
    fill_null(store, READLINE_READ_SIZE);
    short i = 0;
    for( ; after_new_line[i]; i++) {
        store[i] = after_new_line[i];
    }
    store[i] = '\0';
}

void init_my_readline()
{
    if(store) {
        free(store);
    }
    store = malloc(sizeof(char) * READLINE_READ_SIZE + 1);
    fill_null(store, READLINE_READ_SIZE);
}

int check_line(list* answer, char* temp)
{   
    int length = my_strlen(temp);
    int i = 0;
    while(i < length)
    {
        if(temp[i] == '\n')
        {
            copy_store(&temp[i + 1]);
            return 1;
        }

        if(answer->size == (READLINE_READ_SIZE) * answer->count)
        {
            answer->count++;
            answer->text = my_realloc(answer->text, answer->size);
        }
        answer->text[answer->size++] = temp[i];
        i++;
    }
    return 0;
}

char* my_readline(int fd)
{
    if(fd != 3 && fd != 0){
        return NULL;
    }
    list answer;
    answer.count = 1;
    answer.size = 0;
    answer.text = malloc(sizeof(char) * (READLINE_READ_SIZE + 1));
    fill_null(answer.text, READLINE_READ_SIZE);
    char* temp = NULL;
    if(store)
    {
        temp = malloc(sizeof(char) * (READLINE_READ_SIZE + 1));
        fill_null(temp, READLINE_READ_SIZE);
        my_strcpy(temp, store);

        if(check_line(&answer, temp) == 1)
        {
            free(temp);
            return answer.text;
        }
    }
    fill_null(temp, READLINE_READ_SIZE);
    while(read(fd, temp, READLINE_READ_SIZE))
    {
        if(check_line(&answer, temp) == 1)
        {
            free(temp);
            return answer.text;
        }
       fill_null(temp, READLINE_READ_SIZE);
    }
    if(answer.text[0]){
        free(temp);
        return answer.text;
    }
    free(temp);
    free(answer.text);
    return NULL;
}

int main() {
    
    char *str = NULL;
    init_my_readline();

    int fd = open("./file.txt", O_RDONLY);

    while ((str = my_readline(fd)) != NULL) {
        printf("%s\n", str);
        free(str);
    }
    close(fd);
    
    str = my_readline(0);
    printf("%s\n", str);
    free(str);
    return 0;
}
