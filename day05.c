#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINESIZE 20

int hasBadString(char *s, int l){
	int i;

	for(i=0;i<l-1;i++){
		if(s[i]=='a')
			if(s[i+1]=='b') return 1;
		if(s[i]=='c')
			if(s[i+1]=='d') return 1;
		if(s[i]=='p')
			if(s[i+1]=='q') return 1;
		if(s[i]=='x'){
			if(s[i+1]=='y') return 1;
		}
	}

	return 0;
}

int hasDoble(char *s, int l){
	int i;

	for(i=0;i<l-1;i++){
		if(s[i+1]==s[i]) return 1;
	}
	return 0;
}

int hasVowels(char *s,int l){
	int i,c=0;

	for(i=0;i<l;i++){
		if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') 
			c++;
		if (c==3) return 1;
	}
	return 0;
}

int ocorrePar(char par[],char *s,int l){
	int i;
	for(i=2;i<l-1;i++){
		if(s[i]==par[0])
			if(s[i+1]==par[1])
				return 1;
	}
	return 0;
}

int hasPairRep(char *s,int l){
	int i;
	char par[2];

	for(i=0;i<l-3;i++){
		par[0]=s[i];
		par[1]=s[i+1];

		if (ocorrePar(par,s+i,l-i)) return 1;
	}
	return 0;
}

int hasJumper(char *s,int l){
	int i;

	for(i=0;i<l-2;i++){
		if(s[i+2]==s[i]) return 1;
	}
	return 0;
}

int isNice(char *string){
	int l=strlen(string);
	if(hasVowels(string,l) && hasDoble(string,l) && !hasBadString(string,l))
		return 1;

	return 0;
}

int isNewNice(char *string){
	int l=strlen(string);
	if(hasPairRep(string,l) && hasJumper(string,l))
		return 1;
	return 0;
}

int naughtice(){
	FILE *f;

	f=fopen("input","r");

	char line[LINESIZE];
	int r=0;

	while(fgets(line,LINESIZE,f)){
		r+=isNice(line);
	}

	return r;
}

int niceghty(){
	FILE *f;

	f=fopen("input","r");

	char line[LINESIZE];
	int r=0;

	while(fgets(line,LINESIZE,f)){
		r+=isNewNice(line);
	}

	return r;
}
int main(){

	printf("how many nice:%d\n",naughtice());
	printf("how many new nice:%d\n",niceghty());

	return 0;
}
