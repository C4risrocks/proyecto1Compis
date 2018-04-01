#include <stdio.h>
#include <string.h>

char nombre[300];
char caracter;
int i = -1;
void edo0(void);
void edo1(void);

main(){
	
	FILE * archivo_lectura;
	FILE * archivo_escritura;
	
	printf("Escribe el nombre del archivo: ");
	gets(nombre);
	
	archivo_lectura = fopen (nombre, "r");
	archivo_escritura = fopen ("resultado.txt", "w+");
	int j=0;
	if (archivo_lectura == NULL){
		perror("ERROR");
	}
	
	else{
		while((caracter = fgetc(archivo_lectura)) != EOF)
		{
 			fprintf(archivo_escritura, "%c", caracter);
 			printf("%c", caracter);
 		//	edo0();
   	   		
   	   	}
   	   		
		}
		fclose(archivo_lectura);
	}


void edo0(void){
	i++;
	if( (caracter>=97 && caracter<=122) || (caracter>=65 && caracter<=90) || caracter=='_')
	{
		 printf("%c", caracter);
    edo1();
   
	}
    else{
    printf("%c", caracter);
    }
}
 
void edo1(void){
    i++;
	if( (caracter>=48 && caracter<=57) || (caracter>=97 && caracter<=122) || (caracter>=65 && caracter<=90) || caracter=='_')
	{
    edo1();
     printf("%c", caracter);
	}
	else if(caracter=='\0'){
    printf("Cadena valida");
    return;
    }
	else{
    printf("No valida");
	}	       
}
