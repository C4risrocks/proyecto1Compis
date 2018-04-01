#include<stdio.h>
#include<string.h>

void edo0();
void edo1();
void edo2();
void edo3();
void edo4();
void edo5();

char cad[30];
int i=-1;


main ()  {

printf ("Ingrese la cadena a analizar");
fflush(stdin);
gets(cad);
edo0();

} 

void edo0(){
	i++;
	if (cad[i]=='a' )
	edo1();
	else if(cad[i]=='\0' || cad[i]=='e'|| cad[i]=='i'|| cad[i]=='o'|| cad[i]=='u')
	printf("ERROR");
	else 
	edo0();
	
	
}



void edo1(){
	i++;
	if (cad[i]=='e' )
	edo2();
	else if (cad[i]=='a')
	edo1();
	else if(cad[i]=='\0' || cad[i]=='i'|| cad[i]=='o'|| cad[i]=='u')
	printf("ERROR");
	else 
	edo1();
	
}


void edo2(){
	i++;
	if (cad[i]=='e' )
	edo2(); 
	else if (cad[i]=='i')
	edo3();
	else if(cad[i]=='\0' || cad[i]=='a'|| cad[i]=='o'|| cad[i]=='u')
	printf("ERROR");
	else 
	edo2();
}

void edo3(){
	i++;
	if (cad[i]=='o' )
	edo4(); 
	else if (cad[i]=='i')
	edo3();
	else if(cad[i]=='\0' || cad[i]=='a'|| cad[i]=='e'|| cad[i]=='u')
	printf("ERROR");
	else 
	edo3();
}
void edo4(){
	i++;
	if (cad[i]=='u' )
	edo5(); 
	else if (cad[i]=='o')
	edo4();
	else if(cad[i]=='\0' || cad[i]=='a'|| cad[i]=='e'|| cad[i]=='i')
	printf("ERROR");
	else 
	edo4();
}
void edo5(){
	i++;
	if (cad[i]=='u' )
	edo5(); 
	else if(cad[i]=='o' || cad[i]=='a'|| cad[i]=='e'|| cad[i]=='i')
	printf("ERROR");
	else if  (cad [i]=='\0')
	printf("Cadena valida");
	else
	edo5();
}


	
	
