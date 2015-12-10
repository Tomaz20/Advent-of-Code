#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int lookSay(char *s, int h){
	int i,j=0,n;

	char *r=(char*)malloc(strlen(s)*2);

	for(i=0;s[i];i++){
		n=1;

		while(s[i+1]==s[i]){
			i++;
			n++;
		}

		sprintf(&r[j],"%d%c",n,s[i]);
		j+=2;
	}
	r[j]='\0';

	//printf("%s\n",r);

	return h==1 ? strlen(r) : lookSay(r,h-1);
}

int main(int argc,char *argv[]){
	printf("%d\n",lookSay(argv[1],atoi(argv[2])));
}