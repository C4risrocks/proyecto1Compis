#include<stdio.h>

void edo0(void);
void edo1(void);
int i = -1;
char * s;
main(int argc, char *args[]){
s = args[1];
edo0();
}

void edo0(void){
i++;
if( (s[i]>=97 && s[i]<=122) || (s[i]>=65 && s[i]<=90) || s[i]=='_') 
	edo1();
	else{
	printf("No valida :'v");
	}
}

void edo1(void){
	i++;
if( (s[i]>=48 && s[i]<=57) || (s[i]>=97 && s[i]<=122) || (s[i]>=65 && s[i]<=90) || s[i]=='_') 
	edo1();
else if(s[i]=='\0'){
	printf("Cadena valida :v");
	return;
	}
else{
	printf("No valida :'v");
}		
}
