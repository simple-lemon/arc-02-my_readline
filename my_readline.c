// gcc -o out -g3 -fsanitize=address my_readline.c
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h> 
int READLINE_READ_SIZE=20;
char* FULL_CONTENT;

void empty_string(char* string){
    for(int i=0; i<(int)strlen(string); i++){
        string[i]='\0';
    }
}

void n_strip(char* string, int index){
    for(int i=index; i<(int)strlen(string); i++){
        string[i]='\0';
    }
}

char* my_strcat_finish(char* tmp, char* full_content, int index){
    char* res = (char*)calloc(strlen(tmp)+index+1,sizeof(char));
    int i=0;
    while(i<(int)strlen(tmp)){
        res[i]=tmp[i];
        i++;
    }
    for(int j=0; j<index; j++){
        res[i]=full_content[j];
        i++;
    }
    if (!full_content[index+1] || !(full_content+index+1)){
        *full_content='\0';
    }
    else{
        char* new = (char*)calloc((int)strlen(full_content)+1,sizeof(char));
        strcpy(new,&full_content[index+1]);
        strcpy(full_content, new);
        free(new);
    }
    free(tmp);
    return res;
}

char* my_strcat(char* tmp, char* full_content){
    char* result = (char*)calloc(strlen(tmp)+strlen(full_content)+1, sizeof(char));
    int index=0;
    while(index<(int)strlen(tmp)){
        result[index]=tmp[index];
        index++;
    }

    for (int j=0; j<(int)strlen(full_content); j++){
        result[index]=full_content[j];
        index++;
    }
    free(tmp);
    return result;
}

void init_my_readline(){
    free(FULL_CONTENT);
}

char *my_readline(int fd){
    if (!FULL_CONTENT){
        int s;
        FULL_CONTENT=(char*)calloc(READLINE_READ_SIZE+1, sizeof(char));

        s = read(fd, FULL_CONTENT, READLINE_READ_SIZE);
        if(!s){
            init_my_readline();
            return NULL;
        }
    }
    if (!*FULL_CONTENT){
        init_my_readline();
        return NULL;
    }

    for (int i=0; i<(int)strlen(FULL_CONTENT); i++){
        if (FULL_CONTENT[i]=='\n'){
            char* result = (char*)calloc(i+1,sizeof(char));
            strncpy(result, FULL_CONTENT, i);

            char* new = (char*)calloc((int)strlen(FULL_CONTENT)+1,sizeof(char));
            strcpy(new, &FULL_CONTENT[i+1]);
            strcpy(FULL_CONTENT, new);
            free(new);
            return result;
        }
    }
    
    char* tmp = (char*)calloc((int)strlen(FULL_CONTENT)+1,sizeof(char));
    strcpy(tmp, FULL_CONTENT);
    int s;
    while(1){
        empty_string(FULL_CONTENT);
        s = read(fd, FULL_CONTENT, READLINE_READ_SIZE);

        if(s) n_strip(FULL_CONTENT, s);
        
        if (!s){
            if(!*tmp){
                free(tmp);
                init_my_readline();
                return NULL;
            }
            FULL_CONTENT[0]='\0';
            return tmp;    
        }
        for (int i=0; i<(int)strlen(FULL_CONTENT); i++){
            if (FULL_CONTENT[i]=='\n'){
                return my_strcat_finish(tmp, FULL_CONTENT, i);
            }
        }
        tmp = my_strcat(tmp, FULL_CONTENT);
    }
}


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