#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char *Storege_of_file = NULL;
int Readline_Read_Size = 512;
int flag = 0;


char* my_realloc(char* buffer, int size){
    char* tmp = calloc(size + 1, sizeof(char));
    tmp = strcpy(tmp, buffer);
    free(buffer);
    return tmp;
}

char* n_spliter(){
    int j = 0;
    int flag2 = 1;
    char* str = calloc(2 , sizeof(char));
    for(int i = flag; Storege_of_file[i]; i++){
        if(Storege_of_file[i] == '\n'){
            flag = i+1;
            return str;
        }else if(Storege_of_file[i] == '\0'){
            return NULL;
        }else{
            str = my_realloc(str, flag2 + 2);
            str[j++] = Storege_of_file[i];
            flag2++;
        }
    }
    free(str);
    return NULL;
}
char *my_readline(char *name)
{
    int fd = open(name, O_RDONLY);
    int index = 0;
    char *res = NULL;
    if(Storege_of_file == NULL){
        Storege_of_file = calloc(Readline_Read_Size + 1, sizeof(char));
        while (read(fd, &Storege_of_file[index], Readline_Read_Size))
        {
            index += Readline_Read_Size;
            int allocate_size = Readline_Read_Size + index + 1;
            Storege_of_file = my_realloc(Storege_of_file, allocate_size);
        }
    }  
    res = n_spliter();
    return res;
}

int main(int argc, char **argv)
{
    char *buf;
    while((buf = my_readline(argv[1])) != NULL){
        printf("%s\n", buf);
        free(buf);
    }
    flag = 0;
    free(buf);
    free(Storege_of_file);
}

