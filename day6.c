#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define LINESIZE 40

int isNumber(char c){
	if(c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9')
		return 1;
	return 0;
}

void rangeAux(char *l,int *r, int start){
	
	char num[10];
	int i=start;
	int j=0;
	while(isNumber(l[i])){
		num[j++]=l[i++];
	}
	num[j]='\0';
	r[1]=atoi(num);
	i++;
	j=0;

	while(isNumber(l[i])){
		num[j++]=l[i++];
	}
	num[j]='\0';
	r[3]=atoi(num);

	while(!isNumber(l[i])) i++;
	j=0;
	while(isNumber(l[i])){
		num[j++]=l[i++];
	}
	num[j]='\0';
	r[2]=atoi(num);

	i++;
	j=0;

	while(isNumber(l[i])){
		num[j++]=l[i++];
	}
	num[j]='\0';
	r[4]=atoi(num);
}

void getRange(char *l, int *r){
	int i,j;

	if(l[1]=='u'){
		if(l[6]=='n'){
			r[0]=1;
			rangeAux(l,r,8);
		}
		else{
			r[0]=2;
			rangeAux(l,r,9);
		}
	}
	else{
		r[0]=0;
		rangeAux(l,r,7);
	}
}

int lampadas(){
	FILE *f;
	char *line=(char*)malloc(sizeof(char)*LINESIZE);
	
	int **lamps=(int**)malloc(sizeof(int*)*1000);
	
	int i,j;
	for(i=0;i<1000;i++)
		lamps[i]=(int*)calloc(1000,sizeof(int));

	int *range=(int*)malloc(sizeof(int)*5);


	if(!(f=fopen("input","r"))){
		printf("Error opening file");
		return;
	}

	while(fgets(line,LINESIZE,f)){
		getRange(line,range);

		switch(range[0]){
			case 0: {
				for(i=range[1];i<=range[2];i++)
					for(j=range[3];j<=range[4];j++)
						lamps[i][j]+=2;
				break;
			}
			case 1: {
				for(i=range[1];i<=range[2];i++)
					for(j=range[3];j<=range[4];j++)
						lamps[i][j]+=1;
				break;
			}
			default: {
				for(i=range[1];i<=range[2];i++)
					for(j=range[3];j<=range[4];j++)
						if(lamps[i][j])lamps[i][j]-=1;
				break;
			}
		}
	}

	int r=0;
	for(i=0;i<1000;i++){
		for(j=0;j<1000;j++){
			r+=lamps[i][j];
		}
	}

	return r;
}

main(){
	printf("%d\n",lampadas());
}