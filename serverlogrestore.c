#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const char* CLIENT_FORMAT_OUT = "%s::%s::%d::%s::%d\n";
const char* CLIENT_FORMAT_IN = "%[^:]::%[^:]::%d::%[^:]::%d\n";

typedef struct Client {
    char name[20];
    char password[30];
    int admin;
    char dir[30];
    int fd_client;
    
} client_t;

int main(){

    client_t c2;
    client_t c3;

    FILE* file;
    file = fopen("clients.dat","r");
    if (NULL == file){
        return 1;
    }

    fseek(file, 0, SEEK_SET);

    fscanf(file, CLIENT_FORMAT_IN, c2.name,c2.password,&c2.admin, c2.dir, &c2.fd_client);

    printf("%s \n", c2.name);
    printf("%s \n", c2.password);
    printf("%d \n", c2.admin);
    printf("%s \n", c2.dir);
    printf("%d \n", c2.fd_client);

    fscanf(file, CLIENT_FORMAT_IN, c3.name,c3.password,&c3.admin, c3.dir, &c3.fd_client);

    printf("%s \n", c3.name);
    printf("%s \n", c3.password);
    printf("%d \n", c3.admin);
    printf("%s \n", c3.dir);
    printf("%d \n", c3.fd_client);



    return 0;



}