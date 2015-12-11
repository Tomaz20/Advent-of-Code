#include <stdio.h>
#include <stdlib.h>

#define LINESIZE 8000

void main(){
	printf("santa ends up in floor:%d\n",sfloor());
	printf("santa ends up in basement at step:%d\n",basement()+1);
}

int sfloor(){
	FILE *f;
	
	if(!(f=fopen("input","r"))){
		printf("Error opening file");
		return;
	}

	char line[LINESIZE];

	int santaFloor=0,i;

	while(fgets(line,LINESIZE,f)){
		for(i=0;line[i];i++){
			if (line[i]=='(') 
				santaFloor++;
			else
				santaFloor--;
		}
	}

	return santaFloor;
}

int basement(){
	FILE *f;
	
	if(!(f=fopen("input","r"))){
		printf("Error opening file");
		return;
	}

	char line[LINESIZE];

	int santaFloor=0,i;

	while(fgets(line,LINESIZE,f)){
		for(i=0;line[i];i++){
			if (line[i]=='(') 
				santaFloor++;
			else
				santaFloor--;

			if (santaFloor==-1) return i;
		}
	}

	return -1;
}
