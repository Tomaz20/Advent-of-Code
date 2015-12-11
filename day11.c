#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINESIZE 20

int hasBadChar(char *s){
	int i;

	for(i=0;s[i];i++){
		if(s[i]=='i' || s[i]=='o' || s[i]=='l') 
			return 1;
	}

	return 0;
}

int hasTwoPair(char *s){
	int i;
	int l=strlen(s);
	char fst;

	for(i=0;i<l-3;i++){
		if(s[i+1]==s[i]) {
			fst=s[i];
			for(i=i+2;i<l-1;i++){
				if(s[i+1]==s[i] && s[i]!=fst) {
					return 1;
				}
			}
		}
	}
	return 0;
}

int hasSequence(char *s){
	int i;
	int l=strlen(s);

	for(i=0;i<l-2;i++){
		if(s[i]==s[i+1]-1 && s[i+1]==s[i+2]-1){
			return 1;
		}
	}
	return 0;
}

void incrementPass(char *s){
	int i;
	int l=strlen(s);

	for(i=l-1;i>=0;i--){
		if(s[i]=='z')
			s[i]='a';
		else
			break;
	}

	s[i]++;
}


void password(char *pass){
	do{
		incrementPass(pass);
	}while(hasBadChar(pass) || !hasTwoPair(pass) || !hasSequence(pass));
}


int main(){

	char pass[8]="cqjxxyzz";

	password(pass);
	printf("%s\n",pass);

	return 0;
}