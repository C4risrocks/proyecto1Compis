#include <stdio.h>
#include <string.h>

char nombre[300];
char caracter[300];
int i = -1;
int j=0;
void edo0(void);
void edo1(void);
FILE * archivo_escritura;

	int k;

main(){
	
	FILE * archivo_lectura;
	FILE * archivo_escritura;
	
	printf("Escribe el nombre del archivo: ");
	gets(nombre);
	
	archivo_lectura = fopen (nombre, "r");
//	archivo_escritura = fopen ("resultado.txt", "a");
	
	if (archivo_lectura == NULL){
		perror("ERROR");
	}
	
	else{
		while((caracter[j] = fgetc(archivo_lectura)) != EOF)
		{
 			//fprintf(archivo_escritura, "%c", caracter[j]);
 			//printf("%c\n", caracter[j]);
 			j++;
 			//printf("%i\n", j);	
 			//edo0();
   	   	}
   	   	//printf("%i\n", j);
   	   	edo0();	
		}
		fclose(archivo_lectura);
	}


void edo0(){
	i++;
	printf("j= %i\n", j);
	if(i<j){
	
		if( (caracter[i]>=97 && caracter[i]<=122) || (caracter[i]>=65 && caracter[i]<=90) || caracter[i]=='_')
		{	
		 printf("caracter leido E0 = %c\n", caracter[i]);
		 //fprintf(archivo_escritura, "%c", caracter[i]);
    	edo1();
   
		}
		}
    else{
    	printf("i= %i, caracter leido No Valido en E0= %c\n", caracter[i]);
    }
}
 
void edo1(){
	
	archivo_escritura = fopen ("resultado.txt", "w+");
    i++;
    printf("i= %i\n", i);
	if( (caracter[i]>=48 && caracter[i]<=57) || (caracter[i]>=97 && caracter[i]<=122) || (caracter[i]>=65 && caracter[i]<=90) || caracter[i]=='_')
	{
		printf("caracter leido E1= %c\n", caracter[i]);
   		edo1();     
	}
	else if(caracter[i]==' '||caracter[i]=='\n'||caracter[i]=='\t'||caracter[i]== EOF){
    	printf("Cadena valida");
    	for(k=0;k<i;k++){
    	fprintf(archivo_escritura, "%c", caracter[k]);	
    		if(caracter[k+1]==' '||caracter[k+1]=='\n'||caracter[k+1]=='\t'){
    			fprintf(archivo_escritura, " 1");
			}
    	//printf("caracteres %i = %c\n", k,caracter[k]);
		}
		//fprintf(archivo_escritura, " 1\n");
		edo0();
    	return;
    }
	else{
		printf("i= %i, caracter leido No Valido en E1= %c\n", caracter[i]);
	}	       
}
