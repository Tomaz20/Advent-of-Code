#include <stdio.h>
#include <stdlib.h>

#define LINESIZE 8200

void main(){
	printf("houses:%d\n",nhouse());
	printf("robot:%d\n",robo());
}

int robo(){
	FILE *f;

	int **matriz=(int**)malloc(sizeof(int*)*8000);
	int i;
	for(i=0;i<8000;i++){
		matriz[i]=(int*)malloc(sizeof(int)*2);
	}
	matriz[0][0]=0;
	matriz[0][1]=0;
	matriz[1][0]=9999;
	
	if(!(f=fopen("input","r"))){
		printf("Error opening file");
		return;
	}

	char line[LINESIZE];

	int house=1,x=0,y=0;

	while(fgets(line,LINESIZE,f)){
		for(i=0;line[i];i+=2){
			if(line[i]=='>')x++;
			else if(line[i]=='<')x--;
			else if(line[i]=='v')y--;
			else if(line[i]=='^')y++;

			if(!exist(matriz,x,y))house++;
		}
		x=0;y=0;
		for(i=1;line[i];i+=2){
			if(line[i]=='>')x++;
			else if(line[i]=='<')x--;
			else if(line[i]=='v')y--;
			else if(line[i]=='^')y++;

			if(!exist(matriz,x,y))house++;
		}
	}

	return house;
}

int nhouse(){
	FILE *f;

	int **matriz=(int**)malloc(sizeof(int*)*8000);
	int i;
	for(i=0;i<8000;i++){
		matriz[i]=(int*)malloc(sizeof(int)*2);
	}
	matriz[0][0]=0;
	matriz[0][1]=0;
	matriz[1][0]=9999;
	
	if(!(f=fopen("input","r"))){
		printf("Error opening file");
		return;
	}

	char line[LINESIZE];

	int house=1,x=0,y=0;

	while(fgets(line,LINESIZE,f)){
		for(i=0;line[i];i++){
			if(line[i]=='>')x++;
			else if(line[i]=='<')x--;
			else if(line[i]=='v')y--;
			else if(line[i]=='^')y++;

			if(!exist(matriz,x,y))house++;
		}
	}

	return house;
}

int exist(int **matriz, int x,int y){
	int i;

	for(i=0;matriz[i][0]!=9999;i++){
		if(matriz[i][0]==x && matriz[i][1]==y)
			return 1;
	}
	matriz[i][0]=x;
	matriz[i][1]=y;
	matriz[i+1][0]=9999;
	return 0;
}