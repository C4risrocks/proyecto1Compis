#include <stdio.h>
#include <string.h>

char nombre[300];
char caracter[300];
int i = -1;
int j=0;
void edo0(void); //estado inicial
void edo1(void); //estado final identificadores
void edo2(void); //estado final constantes
void edo3(void); //estado final simbolos especiales
FILE * archivo_escritura;

	int k;

main(){

	FILE * archivo_lectura;
	FILE * archivo_escritura;

	//printf("Escribe el nombre del archivo: ");
	//gets(nombre);

	archivo_lectura = fopen ("entrada.txt", "r");
	archivo_escritura = fopen ("resultado.txt", "w");

	if (archivo_lectura == NULL){
		perror("ERROR");
	}

	else{
		while((caracter[j] = fgetc(archivo_lectura)) != EOF)
		{
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
	archivo_escritura = fopen ("resultado.txt", "a");
	i++;
	printf("j= %i\n", j);
	if(i<j){

		if( (caracter[i]>=97 && caracter[i]<=122) || (caracter[i]>=65 && caracter[i]<=90) || caracter[i]=='_')
		{
		fprintf(archivo_escritura, "%c", caracter[i]);
		 printf("caracter leido E0 = %c\n", caracter[i]);

    	edo1();

		}
		else if(caracter[i]>=48 && caracter[i]<=57){
			 printf("caracter leido E0 = %c\n", caracter[i]);
			fprintf(archivo_escritura, "%c", caracter[i]);
    		edo2();
		}
		else if(caracter[i]>=33 && caracter[i]<=47){
			 printf("caracter leido E0 = %c\n", caracter[i]);
			fprintf(archivo_escritura, "%c", caracter[i]);
    		edo3();
		}
		 else{
    	printf("i= %i, caracter leido No Valido en E0= %c\n", caracter[i]);
    	}
		}

}

void edo1(){

	archivo_escritura = fopen ("resultado.txt", "a");
    i++;
    printf("i= %i\n", i);
	if( (caracter[i]>=48 && caracter[i]<=57) || (caracter[i]>=97 && caracter[i]<=122) || (caracter[i]>=65 && caracter[i]<=90) || caracter[i]=='_')
	{
		printf("caracter leido E1= %c\n", caracter[i]);
		 fprintf(archivo_escritura, "%c", caracter[i]);
   		edo1();
	}
	else if(caracter[i]==' '||caracter[i]=='\n'||caracter[i]=='\t'||caracter[i]== EOF){
    	printf("Cadena valida");
    			fprintf(archivo_escritura, " 1\n");
    	//printf("caracteres %i = %c\n", k,caracter[k]);
		//fprintf(archivo_escritura, " 1\n");
		edo0();
    }
	else{
		printf("i= %i, caracter leido No Valido en E1= %c\n", caracter[i]);
	}
	return;
}

void edo2(){
	i++;
	archivo_escritura = fopen ("resultado.txt", "a");
		if(caracter[i]>=48 && caracter[i]<=57){
			 printf("caracter leido E2 = %c\n", caracter[i]);
			 fprintf(archivo_escritura, "%c", caracter[i]);
    		edo2();
		}

		else if(caracter[i]==' '||caracter[i]=='\n'||caracter[i]=='\t'||caracter[i]== EOF){
    	printf("Cadena valida");
    			fprintf(archivo_escritura, " 6\n");
    			edo0();
    		//return;
			}
		//fprintf(archivo_escritura, " 1\n");

    else{
		printf("i= %i, caracter leido No Valido en E2= %c\n", caracter[i]);
	}
}

void edo3(){
	i++;
	archivo_escritura = fopen ("resultado.txt", "a");
		if(caracter[i]>=33 && caracter[i]<=47){
			 printf("caracter leido E2 = %c\n", caracter[i]);
			 fprintf(archivo_escritura, "%c", caracter[i]);
    		edo3();
		}

		else if(caracter[i]==' '||caracter[i]=='\n'||caracter[i]=='\t'||caracter[i]== EOF){
    	printf("Cadena valida");
    			fprintf(archivo_escritura, " 2\n");
    			edo0();
    		//return;
			}
		//fprintf(archivo_escritura, " 1\n");

    else{
		printf("i= %i, caracter leido No Valido en E2= %c\n", caracter[i]);
	}
}

