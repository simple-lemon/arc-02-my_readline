#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h> 

short READLINE_READ_SIZE= 20;
char* store = NULL;

void null(char* str){
    for(int i=0; i<(int)strlen(str); i++){
        str[i]='\0';
    }
}

void fill_null(char* str, int ind){
    for(int i=ind; i<(int)strlen(str); i++){
        str[i]='\0';
    }
}

char* line_over(char* temp, char* storage, int ind){
    char* res = (char*)calloc(strlen(temp)+ind+1,sizeof(char));
    int i=0;
    while(i<(int)strlen(temp)){
        res[i]=temp[i];
        i++;
    }
    for(int j=0; j<ind; j++){
        res[i]=storage[j];
        i++;
    }
    if (!storage[ind+1] || !(storage+ind+1)){
        *storage='\0';
    }
    else{
        char* new = (char*)calloc((int)strlen(storage)+1,sizeof(char));
        strcpy(new,&storage[ind+1]);
        strcpy(storage, new);
        free(new);
    }
    free(temp);
    return res;
}

char* my_stringcat(char* temp, char* storage){
    char* result = (char*)calloc(strlen(temp)+strlen(storage)+1, sizeof(char));
    int ind=0;
    while(ind<(int)strlen(temp)){
        result[ind]=temp[ind];
        ind++;
    }

    for (int j=0; j<(int)strlen(storage); j++){
        result[ind]=storage[j];
        ind++;
    }
    free(temp);
    return result;
}

void init_my_readline(){
    free(store);
}

char *my_readline(int fd){
    if (!store){
        int s;
        store=(char*)calloc(READLINE_READ_SIZE+1, sizeof(char));

        s = read(fd, store, READLINE_READ_SIZE);
        if(!s){
            init_my_readline();
            return NULL;
        }
    }
    if (!*store){
        init_my_readline();
        return NULL;
    }

    for (int i=0; i<(int)strlen(store); i++){
        if (store[i]=='\n'){
            char* result = (char*)calloc(i+1,sizeof(char));
            strncpy(result, store, i);

            char* new = (char*)calloc((int)strlen(store)+1,sizeof(char));
            strcpy(new, &store[i+1]);
            strcpy(store, new);
            free(new);
            return result;
        }
    }
    
    char* tmp = (char*)calloc((int)strlen(store)+1,sizeof(char));
    strcpy(tmp, store);
    int s;
    while(1){
        null(store);
        s = read(fd, store, READLINE_READ_SIZE);

        if(s) fill_null(store, s);
        
        if (!s){
            if(!*tmp){
                free(tmp);
                init_my_readline();
                return NULL;
            }
            store[0]='\0';
            return tmp;    
        }
        for (int i=0; i<(int)strlen(store); i++){
            if (store[i]=='\n'){
                return line_over(tmp, store, i);
            }
        }
        tmp = my_stringcat(tmp, store);
    }
}

int main() 
{
    init_my_readline();
    char *str = NULL;
    int fd = open("./file.txt", O_RDONLY);

    while ((str = my_readline(fd))) 
    {
        printf("%s\n", str);
        free(str);
    }
    
    close(fd);
    // str = my_readline(0);
    // printf("%s\n", str);
    // free(str);
    return 0;
}
