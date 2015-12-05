#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/md5.h>

int resposta(char *string){
    int num=0;
    char *numero=(char*)malloc(sizeof(char)*20);
    char *completa=(char*)malloc(sizeof(char)*20);
    char *h=(char*)malloc(sizeof(char)*33);

    unsigned char md[16];


    MD5_CTX context;
    MD5_Init(&context);

    int i;
    do{
        completa[0]='\0';
        numero[0]='\0';
        h[0]='\0';
        MD5_Init(&context);

        sprintf(numero,"%d",num);

        strcat(completa,string);

        strcat(completa,numero);
        
        MD5_Update(&context,completa,strlen(completa));

        MD5_Final(md,&context);

        for(i = 0; i < 4; ++i)
            sprintf(&h[i*2], "%02x", (unsigned int)md[i]);


        if(h[0]=='0' && h[1]=='0' && h[2]=='0' && h[3]=='0' && h[4]=='0'){
            return num;
        }

        num++;
    }while(1);

    free(h);
    return num;
}

int main(){
    printf("Resposta: %d\n",resposta("yzbqklnj"));
    //printf("abcdef: %d\n",resposta("abcdef"));

    return 1;
}