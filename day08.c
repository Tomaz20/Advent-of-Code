#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define LINESIZE 50

int newSizeMinSize(char *l){
	int i,c=0;

	for(i=0;l[i];i++){
		if (l[i]=='"' || l[i]=='\\') 
			c++;
		c++;
	}
	return c-strlen(l)+2;
}

int sizeMinLen(char *l){
	int i,c=0;

	for(i=1;l[i];i++){
		if (l[i]=='"') c--;
		else if (l[i]=='\\'){
			if (l[i+1]=='x') {
				i+=3;
			}
			else {
				i++;
			}

		}
		c++;
	}
	return strlen(l)-c;
}


int day8(){
	FILE *f;

	f=fopen("input","r");

	char line[LINESIZE];
	int r=0;

	while(fgets(line,LINESIZE,f)){
		r+=newSizeMinSize(line);
	}

	return r;
}

main(){
	printf("%d\n",day8());
}
