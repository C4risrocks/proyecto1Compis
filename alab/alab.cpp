#include<stdio.h>
#include<string.h>

void edo0(void);
void edo1(void);
char s[30];
int i=-1;
main(){
	
	printf("introduce una cadena\n");
	fflush(stdin);
	gets(s);
	
	edo0();
}

void edo0(void){
	i++;
	if(s[i]=='a')
	edo0();
	else if(s[i]=='b')
	edo1();
	else
	printf("ERROR0");
}
void edo1(void){
	i++;
	if(s[i]=='a')
	edo0();
	else if(s[i]=='b')
	edo1();
	else if(s[i]=='\0')
	printf("Cadena valida");
	else
	printf("ERROR1");
}

