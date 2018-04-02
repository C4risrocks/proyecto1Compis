#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char nombre[300];
char caracter[300];
int i = -1;
int j=0; //tamaño de caracteres en el archivo
void edo0(void); //estado inicial
void edo1(void); //estado final identificadores
void edo2(void); //estado final constantes
void edo3(void); //estado final simbolos especiales
void edo4(void); //estado inicial cadenas
void edo5(void); // estado final cadenas
void edo6(void);//estado final operadores
void edo7(void);//estado final símbolos de asignación
void edo8(void);//estado final símbolos de comparación
FILE * archivo_escritura;
char s[100]; //guarda la palabra completa antes de insertarla
char apt[100][100]; //guarda las palabras insertadas en el archivo
int k=-1; //tamaño de s
int v =0, w=0; //tamaño del arreglo	
int encontro = 0; //identificador para insertar o no palabras iguales
int res; //si es cero significa que las cademas son iguales
int p,a,b;
char cad[100]; //cadena auxiliar para comparar arrelo 

main(){

	FILE * archivo_lectura;
/////////////////////////////// LEE NOMBRE DE ARCHIVO A ANALIZAR DESDE CONSOLA
	//printf("Escribe el nombre del archivo: ");
	//gets(nombre);
	//archivo_lectura = fopen (nombre, "r");
////////////////////////////////////////////////////////

	archivo_lectura = fopen ("entrada.txt", "r");


	if (archivo_lectura == NULL){
		perror("ERROR");
		}

	else{
		while((caracter[j] = fgetc(archivo_lectura)) != EOF)
		{
 			j++;
   	   	}
   	   	edo0(); //Después de leer el archivo envía al edo0
		}
		fclose(archivo_lectura);
	}


void edo0(){ ////Estado inicial
	i++; 
	k++; 
	//printf("j= %i\n", j);
	if(i<j){ //si i que recorre el arreglo es menos que el número de caracteres en el archivo
	
			if( (caracter[i]>=97 && caracter[i]<=122) || (caracter[i]>=65 && caracter[i]<=90) || caracter[i]=='_'){
				//fprintf(archivo_escritura, "%c", caracter[i]);
				s[k] = caracter[i]; //asigno a una cadeba para poder compararlas después
				printf("caracter leido E0 = %c\n", caracter[i]);
		    	edo1(); //identificadores
				}
				
			else if(caracter[i]>=48 && caracter[i]<=57){
				printf("caracter leido E0 = %c\n", caracter[i]);
				s[k] = caracter[i]; //asigno a una cadeba para poder compararlas después
				//fprintf(archivo_escritura, "%c", caracter[i]);
	    		edo2(); //constantes
				}
				
			else if(caracter[i]== '('|| caracter[i]== ')'|| caracter[i]== ','|| caracter[i]== '.'|| caracter[i]== '{'|| caracter[i]== '}'|| caracter[i]== '['|| caracter[i]== ']'){
				printf("caracter leido E0 = %c\n", caracter[i]);
				//fprintf(archivo_escritura, "%c", caracter[i]);
				s[k] = caracter[i]; //asigno a una cadeba para poder compararlas después
	    		edo3(); //simbolos especiales
				}
				
			else if(caracter[i]== '"'){
				printf("caracter leido E0 = %c\n", caracter[i]);
				//fprintf(archivo_escritura, "%c", caracter[i]);
				s[k] = caracter[i]; //asigno a una cadeba para poder compararlas después
	    		edo4(); //cadenas inicial
	    		}
	    		
			else if(caracter[i]== '+'|| caracter[i]== '-'|| caracter[i]== '/'|| caracter[i]== '*'){
				printf("caracter leido E0 = %c\n", caracter[i]);
				//fprintf(archivo_escritura, "%c", caracter[i]);
				s[k] = caracter[i]; //asigno a una cadeba para poder compararlas después
	    		edo6(); //operadores
	    		}
			
			else if(caracter[i]== '='){
				printf("caracter leido E0 = %c\n", caracter[i]);
				//fprintf(archivo_escritura, "%c", caracter[i]);
				s[k] = caracter[i]; //asigno a una cadeba para poder compararlas después
	    		edo7();//símbolos de asignación
	    		}
	    		
			else if(caracter[i]== '<'|| caracter[i]== '>'){
				printf("caracter leido E0 = %c\n", caracter[i]);
				//fprintf(archivo_escritura, "%c", caracter[i]);
				s[k] = caracter[i]; //asigno a una cadeba para poder compararlas después
	    		edo8(); //comparaciones
				}
				
			else{
	    	printf("i= %i, caracter leido No Valido en E0= %c\n", caracter[i]);
	    	}
		}
}

void edo1(){
	archivo_escritura = fopen ("resultado.txt", "a"); 
    i++;
    k++;
		if( (caracter[i]>=48 && caracter[i]<=57) || (caracter[i]>=97 && caracter[i]<=122) || (caracter[i]>=65 && caracter[i]<=90) || caracter[i]=='_')
		{
		printf("caracter leido E1= %c\n", caracter[i]);
		 //fprintf(archivo_escritura, "%c", caracter[i]);
		s[k] = caracter[i]; //asigno a una cadeba para poder compararlas después
   		edo1();
		}
		else if(caracter[i]==' '||caracter[i]=='\n'||caracter[i]=='\t'||caracter[i]== EOF){
    		printf("Cadena valida: %s\n", s);
			///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b]; 
						  }
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  //printf("CAD=%s\n", cad);
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}
					  }
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;
					}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1) //si es diferente de uno significa que no se ha insertado
			{
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;
	   	   		}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 1\n", s); //inserto la cadena en el archivo con el tipo
				/////////////////////////////////////////   		
	    	}    	
	    ///////////////////////inicializo las cadenas nuevamente
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;	
			edo0();
    	}

		else if(caracter[i]== '('|| caracter[i]== ')'|| caracter[i]== ','|| caracter[i]== '.'|| caracter[i]== '{'|| caracter[i]== '}'|| caracter[i]== '['|| caracter[i]== ']'){ 
			printf("Cadena valida en E3: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 1\n", s); //inserto la cadena en el archivo con el tipo	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
				//s[k]=caracter[i];
				//printf("%s", caracter[i]);
	    		encontro = 0;
	    		i=i-1;
			edo3();
		}
		else if(caracter[i]== '+'|| caracter[i]== '-'|| caracter[i]== '/'|| caracter[i]== '*'){
			printf("Cadena valida: %s\n", s);   
	    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
				for(a=0;a<=w;a++){
		   	   			for(b=0;b<=v;b++){
		   	   				cad[b]=apt[a][b];}
							  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
							  if (res == 0) //entra si las cadenas son iguales
								{
						 			printf ("iguales\n");
						 			encontro = 1; 
								}}
					/////////////////////////////////////////////elimino el contenido de cad
					for(p=0;p<b;p++){
			    			cad[p]=NULL;}
					////////////////////////////////////////////		  
		    	
		    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
					///////////////////////////////////////// Guarda la plabra en el arreglo
					for(a=0;a<k;a++){	
						apt[w][v]=s[a];
						printf("%i, %i=%c\n", w, v, apt[w][v]);	
						v++;}
		   	   		w++;
		   	   		fprintf(archivo_escritura, "%s 1\n", s); //inserto la cadena en el archivo con el tipo	
		    	}    	
		    	for(p=0;p<k;p++){
		    			s[p]=NULL;
					}
					k=-1;
		    		encontro = 0;
		    			i=i-1;
	    		edo6();
	    }
		else if(caracter[i]== '='){
    		printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 1\n", s); //inserto la cadena en el archivo con el tipo	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
    		edo7();
   		}
		else if(caracter[i]== '<'|| caracter[i]== '>'){
	    	printf("Cadena valida: %s\n", s);   
	    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
				for(a=0;a<=w;a++){
		   	   			for(b=0;b<=v;b++){
		   	   				cad[b]=apt[a][b];}
							  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
							  if (res == 0) //entra si las cadenas son iguales
								{
						 			printf ("iguales\n");
						 			encontro = 1; 
								}}
					/////////////////////////////////////////////elimino el contenido de cad
					for(p=0;p<b;p++){
			    			cad[p]=NULL;}
					////////////////////////////////////////////		  
		    	
		    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
					///////////////////////////////////////// Guarda la plabra en el arreglo
					for(a=0;a<k;a++){	
						apt[w][v]=s[a];
						printf("%i, %i=%c\n", w, v, apt[w][v]);	
						v++;}
		   	   		w++;
		   	   		fprintf(archivo_escritura, "%s 1\n", s); //inserto la cadena en el archivo con el tipo	
		    	}    	
		    	for(p=0;p<k;p++){
		    			s[p]=NULL;
					}
					k=-1;
		    		encontro = 0;
		    			i=i-1;
	    		edo8();
	    }
	else{
		printf("i= %i, caracter leido No Valido en E1= %c\n", caracter[i]);
		}
}

void edo2(){
	i++;
	k++;
	archivo_escritura = fopen ("resultado.txt", "a");
		if(caracter[i]>=48 && caracter[i]<=57){
			 printf("caracter leido E2 = %c\n", caracter[i]);
			 //fprintf(archivo_escritura, "%c", caracter[i]);
			s[k] = caracter[i]; //asigno a una cadeba para poder compararlas después
    		edo2();
			}

		else if(caracter[i]==' '||caracter[i]=='\n'||caracter[i]=='\t'||caracter[i]== EOF){
    	printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 6\n", s); //inserto la cadena en el archivo con el tipo 6 constantes	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
    			edo0();
    	}
		else if( (caracter[i]>=97 && caracter[i]<=122) || (caracter[i]>=65 && caracter[i]<=90) || caracter[i]=='_'){
			printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 6\n", s); //inserto la cadena en el archivo con el tipo 6 constantes	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
				edo1();
    	}					
		else if(caracter[i]== '('|| caracter[i]== ')'|| caracter[i]== ','|| caracter[i]== '.'|| caracter[i]== '{'|| caracter[i]== '}'|| caracter[i]== '['|| caracter[i]== ']'){
    	printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 6\n", s); //inserto la cadena en el archivo con el tipo 6 constantes	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;    
					i=i-1;	
		edo3();
    	}
		else if(caracter[i]== '"'){    	
			 	printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 6\n", s); //inserto la cadena en el archivo con el tipo 6 constantes	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
    		edo4();	
    	}
		else if(caracter[i]== '+'|| caracter[i]== '-'|| caracter[i]== '/'|| caracter[i]== '*'){
			 	printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 6\n", s); //inserto la cadena en el archivo con el tipo 6 constantes	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
    		edo6();
    	}
		else if(caracter[i]== '='){    	
			printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 6\n", s); //inserto la cadena en el archivo con el tipo 6 constantes	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
    		edo7();
    	}
		else if(caracter[i]== '<'|| caracter[i]== '>'){
    			printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 6\n", s); //inserto la cadena en el archivo con el tipo 6 constantes	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
    		edo8();
		}
    else{
		printf("i= %i, caracter leido No Valido en E2= %c\n", caracter[i]);
	}
}

void edo3(){
	i++;
	k++;
	printf("E3\n");
	archivo_escritura = fopen ("resultado.txt", "a");
		if(caracter[i]== '('|| caracter[i]== ')'|| caracter[i]== ','|| caracter[i]== '.'|| caracter[i]== '{'|| caracter[i]== '}'|| caracter[i]== '['|| caracter[i]== ']'){
			 printf("caracter leido E3 = %c\n", caracter[i]);			 
			 //fprintf(archivo_escritura, "%c", caracter[i]);
			 s[k] = caracter[i]; //asigno a una cadeba para poder compararlas después
    		edo3();
		}

		else if(caracter[i]==' '||caracter[i]=='\n'||caracter[i]=='\t'||caracter[i]== EOF){
    		printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 2\n", s); //inserto la cadena en el archivo con el tipo 2 simbolos especiales	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
    			edo0();
    		}
			
		else if( (caracter[i]>=97 && caracter[i]<=122) || (caracter[i]>=65 && caracter[i]<=90) || caracter[i]=='_'){
			printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 2\n", s); //inserto la cadena en el archivo con el tipo 2 simbolos especiales	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
				edo1();
    	}
		else if(caracter[i]>=48 && caracter[i]<=57){
			printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 2\n", s); //inserto la cadena en el archivo con el tipo 2 simbolos especiales	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
    		edo2();
		}
		
		else if(caracter[i]== '"'){
		printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 2\n", s); //inserto la cadena en el archivo con el tipo 2 simbolos especiales	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
    		edo4();
    	}else if(caracter[i]== '+'|| caracter[i]== '-'|| caracter[i]== '/'|| caracter[i]== '*'){
    		printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 2\n", s); //inserto la cadena en el archivo con el tipo 2 simbolos especiales	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
    		edo6();
    	}else if(caracter[i]== '='){
    		printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 2\n", s); //inserto la cadena en el archivo con el tipo 2 simbolos especiales	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
    		edo7();
    	}
		else if(caracter[i]== '<'|| caracter[i]== '>'){
    		printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 2\n", s); //inserto la cadena en el archivo con el tipo 2 simbolos especiales	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
    		edo8();
		}
	else{
			printf("i= %i, caracter leido No Valido en E2= %c\n", caracter[i]);
		}
}

void edo4(){
	i++;
	k++;
	archivo_escritura = fopen ("resultado.txt", "a");
		if(caracter[i]== '"'){
			 printf("Cadena valida");
			 printf("caracter leido E4 = %c\n", caracter[i]);
			 //s[k] = caracter[i]; //asigno a una cadeba para poder compararlas después
			 fprintf(archivo_escritura, "%c", caracter[i]);
    			fprintf(archivo_escritura, "cadena\n");
    			edo5();
		}

		else if((caracter[i]>=48 && caracter[i]<=57) || (caracter[i]>=97 && caracter[i]<=122) || (caracter[i]>=65 && caracter[i]<=90) || caracter[i]=='_' || caracter[i]==' '||caracter[i]=='\n'||caracter[i]=='\t'){
    	printf("Cadena valida");
    			printf("caracter leido E4 = %c\n", caracter[i]);
			 fprintf(archivo_escritura, "%c", caracter[i]);
    			edo4();
			}
		else if(caracter[i]==' '||caracter[i]=='\n'||caracter[i]=='\t'||caracter[i]== EOF){
    	printf("Cadena valida");
    			fprintf(archivo_escritura, " cadena\n");
    			edo0();
    		//return;
			}
			
		else if( (caracter[i]>=97 && caracter[i]<=122) || (caracter[i]>=65 && caracter[i]<=90) || caracter[i]=='_'){
			
				printf("Cadena valida");
    			fprintf(archivo_escritura, " cadena\n");
				
				edo1();
    		//return;
    	}
		else if(caracter[i]>=48 && caracter[i]<=57){
			
			printf("Cadena valida");
    		fprintf(archivo_escritura, " cadena\n");
    		edo2();
		}
			
		else if(caracter[i]== '('|| caracter[i]== ')'|| caracter[i]== ','|| caracter[i]== '.'|| caracter[i]== '{'|| caracter[i]== '}'|| caracter[i]== '['|| caracter[i]== ']'){
    
    	printf("Cadena valida");
    	fprintf(archivo_escritura, " cadena\n");
		edo3();
		
		}else if(caracter[i]== '+'|| caracter[i]== '-'|| caracter[i]== '/'|| caracter[i]== '*'){
    		
			 printf("Cadena valida");
    	    	fprintf(archivo_escritura, " cadena\n");
    		edo6();
    	}else if(caracter[i]== '='){
    		
			printf("Cadena valida");
    		fprintf(archivo_escritura, " simbolo especial\n");
    		edo7();
    	}else if(caracter[i]== '<'|| caracter[i]== '>'){
    		
			 printf("Cadena valida");
    		fprintf(archivo_escritura, " cadena\n");
    		edo8();
		}
			
			
else{
		printf("i= %i, caracter leido No Valido en E2= %c\n", caracter[i]);
	}
}

void edo5(){
	i++;
	k++;
	archivo_escritura = fopen ("resultado.txt", "a");
		if(caracter[i]==' '||caracter[i]=='\n'||caracter[i]=='\t'||caracter[i]== EOF){
    	printf("Estado final cadenas");
		edo0();}
	else{
			printf("i= %i, caracter leido No Valido en E2= %c\n", caracter[i]);
		}
}
void edo6(){
		i++;
		k++;
		archivo_escritura = fopen ("resultado.txt", "a");
		if(caracter[i]== '+'|| caracter[i]== '-'|| caracter[i]== '/'|| caracter[i]== '*'){
			 printf("caracter leido E6 = %c\n", caracter[i]);
			 s[k] = caracter[i]; //asigno a una cadeba para poder compararlas después
			 //fprintf(archivo_escritura, "%c", caracter[i]);
    		edo6();}
    		
    	else if(caracter[i]==' '||caracter[i]=='\n'||caracter[i]=='\t'||caracter[i]== EOF){
    		printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 3\n", s); //inserto la cadena en el archivo con el tipo 3 operadores	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
    			edo0();    		
    		}
		else if( (caracter[i]>=97 && caracter[i]<=122) || (caracter[i]>=65 && caracter[i]<=90) || caracter[i]=='_'){
			printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 3\n", s); //inserto la cadena en el archivo con el tipo 3 operadores		
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
				edo1();
    	}
		else if(caracter[i]>=48 && caracter[i]<=57){
			printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 3\n", s); //inserto la cadena en el archivo con el tipo 3 operadores		
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
    		edo2();
		}
		else if(caracter[i]== '('|| caracter[i]== ')'|| caracter[i]== ','|| caracter[i]== '.'|| caracter[i]== '{'|| caracter[i]== '}'|| caracter[i]== '['|| caracter[i]== ']'){
    			printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 3\n", s); //inserto la cadena en el archivo con el tipo 3 operadores		
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
			edo3();
		}
		
		else if(caracter[i]== '"'){
			printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 3\n", s); //inserto la cadena en el archivo con el tipo 3 operadores		
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
    		edo4();
    		
    	}
		else if(caracter[i]== '='){
    			printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 3\n", s); //inserto la cadena en el archivo con el tipo 3 operadores		
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
    		edo7();
    	}
		else if(caracter[i]== '<'|| caracter[i]== '>'){
    		printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 3\n", s); //inserto la cadena en el archivo con el tipo 3 operadores	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
    		edo8();
		}
    	else{
			printf("i= %i, caracter leido No Valido en E6= %c\n", caracter[i]);
    		
    		//return;
			}
}
void edo7(){
		i++;
		k++;
		archivo_escritura = fopen ("resultado.txt", "a");
			if(caracter[i]== '='){
			 printf("caracter leido E7 = %c\n", caracter[i]);
			 //fprintf(archivo_escritura, "%c", caracter[i]);
			 s[k] = caracter[i]; //asigno a una cadeba para poder compararlas después
    		edo7();}
    		
    		else if(caracter[i]==' '||caracter[i]=='\n'||caracter[i]=='\t'||caracter[i]== EOF){
    		printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 4\n", s); //inserto la cadena en el archivo con el tipo 4 asignacion	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
    			edo0();
			}
		else if( (caracter[i]>=97 && caracter[i]<=122) || (caracter[i]>=65 && caracter[i]<=90) || caracter[i]=='_'){
			
					printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 4\n", s); //inserto la cadena en el archivo con el tipo 4 asignacion	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
				edo1();
    		//return;
    	}
		else if(caracter[i]>=48 && caracter[i]<=57){
			
				printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 4\n", s); //inserto la cadena en el archivo con el tipo 4 asignacion	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
    		edo2();
		}
		else if(caracter[i]== '('|| caracter[i]== ')'|| caracter[i]== ','|| caracter[i]== '.'|| caracter[i]== '{'|| caracter[i]== '}'|| caracter[i]== '['|| caracter[i]== ']'){
    
    		printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 4\n", s); //inserto la cadena en el archivo con el tipo 4 asignacion	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
		edo3();
	}
		else if(caracter[i]== '"'){
			printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 4\n", s); //inserto la cadena en el archivo con el tipo 4 asignacion	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
    		edo4();
    	}else if(caracter[i]== '+'|| caracter[i]== '-'|| caracter[i]== '/'|| caracter[i]== '*'){
    			printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 4\n", s); //inserto la cadena en el archivo con el tipo 4 asignacion	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
    		edo6();
    		}else if(caracter[i]== '<'|| caracter[i]== '>'){
    			printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 4\n", s); //inserto la cadena en el archivo con el tipo 4 asignacion	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
    		edo8();
		}
    	else{
			printf("i= %i, caracter leido No Valido en E7= %c\n", caracter[i]);
    		
    		//return;
			}
	}
void edo8(){
		i++;
		k++;
		archivo_escritura = fopen ("resultado.txt", "a");
		if(caracter[i]=='<'|| caracter[i]== '>' ){
			 printf("caracter leido E8 = %c\n", caracter[i]);
			 s[k] = caracter[i]; //asigno a una cadeba para poder compararlas después
			 //fprintf(archivo_escritura, "%c", caracter[i]);
    		edo8();}
    		else if(caracter[i]==' '||caracter[i]=='\n'||caracter[i]=='\t'||caracter[i]== EOF){
    		printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 5\n", s); //inserto la cadena en el archivo con el tipo 5 comparacion	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
    			edo0();
    		//return;
			}
				else if( (caracter[i]>=97 && caracter[i]<=122) || (caracter[i]>=65 && caracter[i]<=90) || caracter[i]=='_'){
			printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 5\n", s); //inserto la cadena en el archivo con el tipo 5 comparacion	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
				edo1();
    		//return;
    	}
		else if(caracter[i]>=48 && caracter[i]<=57){
			printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 5\n", s); //inserto la cadena en el archivo con el tipo 5 comparacion	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
    		edo2();
		}
		else if(caracter[i]== '('|| caracter[i]== ')'|| caracter[i]== ','|| caracter[i]== '.'|| caracter[i]== '{'|| caracter[i]== '}'|| caracter[i]== '['|| caracter[i]== ']'){
    		printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 5\n", s); //inserto la cadena en el archivo con el tipo 5 comparacion	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
		edo3();
	}
		else if(caracter[i]== '"'){
		printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 5\n", s); //inserto la cadena en el archivo con el tipo 5 comparacion	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
    		edo4();
    	}
		else if(caracter[i]== '+'|| caracter[i]== '-'|| caracter[i]== '/'|| caracter[i]== '*'){
    	printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 5\n", s); //inserto la cadena en el archivo con el tipo 5 comparacion	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
    		edo6();
		}
		else if(caracter[i]== '='){
			printf("Cadena valida: %s\n", s);   
    	///////////////////////////////// Recorrer el arreglo en todas las posiciones para saber si la palabra ya esta insertado o no
			for(a=0;a<=w;a++){
	   	   			for(b=0;b<=v;b++){
	   	   				cad[b]=apt[a][b];}
						  res = strcmp(cad, s); //compara la cadena obtenida por el arreglo contra la cadena leida
						  if (res == 0) //entra si las cadenas son iguales
							{
					 			printf ("iguales\n");
					 			encontro = 1; 
							}}
				/////////////////////////////////////////////elimino el contenido de cad
				for(p=0;p<b;p++){
		    			cad[p]=NULL;}
				////////////////////////////////////////////		  
	    	
	    	if(encontro != 1){ //si es diferente de uno significa que no se ha insertado
				///////////////////////////////////////// Guarda la plabra en el arreglo
				for(a=0;a<k;a++){	
					apt[w][v]=s[a];
					printf("%i, %i=%c\n", w, v, apt[w][v]);	
					v++;}
	   	   		w++;
	   	   		fprintf(archivo_escritura, "%s 5\n", s); //inserto la cadena en el archivo con el tipo 5 comparacion	
	    	}    	
	    	for(p=0;p<k;p++){
	    			s[p]=NULL;
				}
				k=-1;
	    		encontro = 0;
	    			i=i-1;
    		edo7();
    	}

	else{
		printf("i= %i, caracter leido No Valido en E8= %c\n", caracter[i]);
	}
}
