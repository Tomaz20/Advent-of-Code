#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINESIZE 20

int *tokenizer(char *string){
	int *r=(int*)malloc(sizeof(int)*3);

	char *aux=(char*)malloc(sizeof(char)*20);

	int i,j=0;


	for(i=0;string[i]!='x';i++){
		aux[j++]=string[i];
	}
	aux[j]='\0';
	i++;


	r[0]=atoi(aux);
	j=0;
	for(i;string[i]!='x';i++){
		aux[j++]=string[i];
	}

	aux[j]='\0';
	i++;

	r[1]=atoi(aux);

	j=0;
	for(i;string[i];i++){
		aux[j++]=string[i];
	}

	aux[j]='\0';
	i++;

	r[2]=atoi(aux);

	return r;
}

int min(int *a){
	int b[3];
	b[0]=a[0]*a[1];
	b[1]=a[1]*a[2];
	b[2]=a[0]*a[2];

	if(b[0]<b[1]){
		if(b[0]<b[2]) return b[0];
		else return b[2];
	}
	else{
		if(b[1]<b[2]) return b[1];
		else return b[2];
	}
}

int fita(int *a){
	int r=0;

	if(a[0]<a[1]){
		r+=a[0]*2;

		if(a[1]<a[2]) r+=a[1]*2;
		else r+=a[2]*2;
	}
	else{
		r+=2*a[1];

		if(a[0]<a[2]) r+=2*a[0]; 
		else r+=2*a[2];
	}
	return r;
}

int laco(){
	FILE *f;

	f=fopen("input","r");

	char line[LINESIZE];
	int *dim;
	int r=0;

	while(fgets(line,LINESIZE,f)){
		dim=tokenizer(line);
		r+=dim[0]*dim[1]*dim[2];
		r+=fita(dim);
	}

	return r;
}

int paper(){
	FILE *f;

	f=fopen("input","r");

	char line[LINESIZE];
	int *dim;
	int r=0;

	while(fgets(line,LINESIZE,f)){
		dim=tokenizer(line);
		r+=2*dim[0]*dim[1];
		r+=2*dim[0]*dim[2];
		r+=2*dim[2]*dim[1];
		r+=min(dim);
	}

	return r;
}

void main(){

	printf("papel:%d\n",paper());
	printf("laco:%d\n",laco());
}



