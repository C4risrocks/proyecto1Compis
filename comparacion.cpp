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
void edo4(void); //estado inicial cadenas
void edo5(void); // estado final cadenas
void edo6(void);//estado final operadores
void edo7(void);//estado final símbolos de asignación
void edo8(void);//estado final símbolos de comparación
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
		else if(caracter[i]== '('|| caracter[i]== ')'|| caracter[i]== ','|| caracter[i]== '.'|| caracter[i]== '{'|| caracter[i]== '}'|| caracter[i]== '['|| caracter[i]== ']'){
			 printf("caracter leido E0 = %c\n", caracter[i]);
			fprintf(archivo_escritura, "%c", caracter[i]);
    		edo3();
		}else if(caracter[i]== '"'){
			 printf("caracter leido E0 = %c\n", caracter[i]);
			fprintf(archivo_escritura, "%c", caracter[i]);
    		edo4();
    	}else if(caracter[i]== '+'|| caracter[i]== '-'|| caracter[i]== '/'|| caracter[i]== '*'){
			 printf("caracter leido E0 = %c\n", caracter[i]);
			fprintf(archivo_escritura, "%c", caracter[i]);
    		edo6();
    	}else if(caracter[i]== '='){
			 printf("caracter leido E0 = %c\n", caracter[i]);
			fprintf(archivo_escritura, "%c", caracter[i]);
    		edo7();
    	}else if(caracter[i]== '<'|| caracter[i]== '>'){
			 printf("caracter leido E0 = %c\n", caracter[i]);
			fprintf(archivo_escritura, "%c", caracter[i]);
    		edo8();
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
    }else if(caracter[i]== '('|| caracter[i]== ')'|| caracter[i]== ','|| caracter[i]== '.'|| caracter[i]== '{'|| caracter[i]== '}'|| caracter[i]== '['|| caracter[i]== ']'){
    
    	printf("Cadena valida");
    				fprintf(archivo_escritura, " 1\n");
		edo3();
	}else if(caracter[i]== '+'|| caracter[i]== '-'|| caracter[i]== '/'|| caracter[i]== '*'){
	
			printf("Cadena valida");
    				fprintf(archivo_escritura, " 1\n");
    		edo6();
    }else if(caracter[i]== '='){
    	
		printf("Cadena valida");
    			fprintf(archivo_escritura, " 1\n");
    		edo7();
    }else if(caracter[i]== '<'|| caracter[i]== '>'){
    
			 printf("Cadena valida");
    			fprintf(archivo_escritura, " 1\n");
    		edo8();
    }
	else{
		printf("i= %i, caracter leido No Valido en E1= %c\n", caracter[i]);
	}
//	return;
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
    			fprintf(archivo_escritura, " 2\n");
    			edo0();
    	}else if( (caracter[i]>=97 && caracter[i]<=122) || (caracter[i]>=65 && caracter[i]<=90) || caracter[i]=='_'){
		
				
			("Cadena valida");
    			fprintf(archivo_escritura, " 2\n");
				edo1();
    		//return;
    	}
    		
    		
			
		else if(caracter[i]== '('|| caracter[i]== ')'|| caracter[i]== ','|| caracter[i]== '.'|| caracter[i]== '{'|| caracter[i]== '}'|| caracter[i]== '['|| caracter[i]== ']'){
    
    	printf("Cadena valida");
    				fprintf(archivo_escritura, " 2\n");
		edo3();
    
    
    	}else if(caracter[i]== '"'){
    	
			 printf("Cadena valida");
    				fprintf(archivo_escritura, " 2\n");
    		edo4();
    		
    	}else if(caracter[i]== '+'|| caracter[i]== '-'|| caracter[i]== '/'|| caracter[i]== '*'){
    		
			 printf("Cadena valida");
    				fprintf(archivo_escritura, " 2\n");
    		edo6();
    		
    	}else if(caracter[i]== '='){
    	
		printf("Cadena valida");
    				fprintf(archivo_escritura, " 2\n");
    		edo7();
    		
    	}else if(caracter[i]== '<'|| caracter[i]== '>'){
    		
			 printf("Cadena valida");
    				fprintf(archivo_escritura, " 2\n");
    		edo8();
		}
		//fprintf(archivo_escritura, " 1\n");

    else{
		printf("i= %i, caracter leido No Valido en E2= %c\n", caracter[i]);
	}
}

void edo3(){
	i++;
	archivo_escritura = fopen ("resultado.txt", "a");
		if(caracter[i]== '('|| caracter[i]== ')'|| caracter[i]== ','|| caracter[i]== '.'|| caracter[i]== '{'|| caracter[i]== '}'|| caracter[i]== '['|| caracter[i]== ']'){
			 printf("caracter leido E3 = %c\n", caracter[i]);
			 fprintf(archivo_escritura, "%c", caracter[i]);
    		edo3();
		}

		else if(caracter[i]==' '||caracter[i]=='\n'||caracter[i]=='\t'||caracter[i]== EOF){
    	printf("Cadena valida");
    			fprintf(archivo_escritura, " simbolo especial\n");
    			edo0();
    		//return;
			}
			
		else if( (caracter[i]>=97 && caracter[i]<=122) || (caracter[i]>=65 && caracter[i]<=90) || caracter[i]=='_'){
			
				printf("Cadena valida");
    			fprintf(archivo_escritura, " simbolo especial\n");
				
				edo1();
    		//return;
    	}
		else if(caracter[i]>=48 && caracter[i]<=57){
			
			printf("Cadena valida");
    				fprintf(archivo_escritura, " simbolo especial\n");
    		edo2();
		}
		
		else if(caracter[i]== '"'){
		
			 printf("Cadena valida");
    				fprintf(archivo_escritura, " simbolo especial\n");
    		edo4();
    	}else if(caracter[i]== '+'|| caracter[i]== '-'|| caracter[i]== '/'|| caracter[i]== '*'){
    		
			 printf("Cadena valida");
    			fprintf(archivo_escritura, " simbolo especial\n");
    		edo6();
    	}else if(caracter[i]== '='){
    		
			 printf("Cadena valida");
    			fprintf(archivo_escritura, " simbolo especial\n");
    		edo7();
    	}else if(caracter[i]== '<'|| caracter[i]== '>'){
    		
			 printf("Cadena valida");
    				fprintf(archivo_escritura, " simbolo especial\n");
    		edo8();
		}
		
		
else{
		printf("i= %i, caracter leido No Valido en E2= %c\n", caracter[i]);
	}
}

void edo4(){
	i++;
	archivo_escritura = fopen ("resultado.txt", "a");
		if(caracter[i]== '"'){
			 printf("Cadena valida");
			 printf("caracter leido E4 = %c\n", caracter[i]);
			 fprintf(archivo_escritura, "%c", caracter[i]);
    			fprintf(archivo_escritura, "cadena\n");
    			edo5();
		}

		else if((caracter[i]>=48 && caracter[i]<=57) || (caracter[i]>=97 && caracter[i]<=122) || (caracter[i]>=65 && caracter[i]<=90) || caracter[i]=='_' || caracter[i]==' '||caracter[i]=='\n'||caracter[i]=='\t'){
    	printf("Cadena valida");
    			printf("caracter leido E4 = %c\n", caracter[i]);
			 fprintf(archivo_escritura, "%c", caracter[i]);
    			edo4();
    		//return;
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
		if(caracter[i]==' '||caracter[i]=='\n'||caracter[i]=='\t'||caracter[i]== EOF){
    	printf("Estado final cadenas");
		edo0();}
else{
		printf("i= %i, caracter leido No Valido en E2= %c\n", caracter[i]);
	}
}
void edo6(){
		i++;
	archivo_escritura = fopen ("resultado.txt", "a");
		if(caracter[i]== '+'|| caracter[i]== '-'|| caracter[i]== '/'|| caracter[i]== '*'){
		
			 printf("caracter leido E6 = %c\n", caracter[i]);
			 fprintf(archivo_escritura, "%c", caracter[i]);
    		edo6();}
    		else if(caracter[i]==' '||caracter[i]=='\n'||caracter[i]=='\t'||caracter[i]== EOF){
    	printf("Cadena valida");
    			fprintf(archivo_escritura, " Operador\n");
    			edo0();
    		
    		}else if( (caracter[i]>=97 && caracter[i]<=122) || (caracter[i]>=65 && caracter[i]<=90) || caracter[i]=='_'){
		
				printf("Cadena valida");
    			fprintf(archivo_escritura, " Operador\n");
				edo1();
    		//return;
    	}
		else if(caracter[i]>=48 && caracter[i]<=57){
		
			 printf("Cadena valida");
    		fprintf(archivo_escritura, " Operador\n");
    		edo2();
		}
		else if(caracter[i]== '('|| caracter[i]== ')'|| caracter[i]== ','|| caracter[i]== '.'|| caracter[i]== '{'|| caracter[i]== '}'|| caracter[i]== '['|| caracter[i]== ']'){
    		
    		printf("Cadena valida");
    			fprintf(archivo_escritura, " Operador\n");
			edo3();
		}
		
		else if(caracter[i]== '"'){
		
			 printf("Cadena valida");
    			fprintf(archivo_escritura, " Operador\n");
    		edo4();
    		
    	}else if(caracter[i]== '='){
    		
			 printf("Cadena valida");
    			fprintf(archivo_escritura, " Operador\n");
    		edo7();
    	}else if(caracter[i]== '<'|| caracter[i]== '>'){
    	
			 printf("Cadena valida");
    			fprintf(archivo_escritura, " Operador\n");
    		edo8();
		}
    	else{
			printf("i= %i, caracter leido No Valido en E6= %c\n", caracter[i]);
    		
    		//return;
			}
}
			
			
			

void edo7(){
		i++;
	archivo_escritura = fopen ("resultado.txt", "a");
		if(caracter[i]== '='){
		
			 printf("caracter leido E7 = %c\n", caracter[i]);
			 fprintf(archivo_escritura, "%c", caracter[i]);
    		edo7();}
    		else if(caracter[i]==' '||caracter[i]=='\n'||caracter[i]=='\t'||caracter[i]== EOF){
    	printf("Cadena valida");
    			fprintf(archivo_escritura, " Simbolo de asignacion\n");
    			edo0();
    		//return;
			}
		else if( (caracter[i]>=97 && caracter[i]<=122) || (caracter[i]>=65 && caracter[i]<=90) || caracter[i]=='_'){
			
				printf("Cadena valida");
    		fprintf(archivo_escritura, " Simbolo de asignacion\n");
				edo1();
    		//return;
    	}
		else if(caracter[i]>=48 && caracter[i]<=57){
			
			 printf("Cadena valida");
    			fprintf(archivo_escritura, " Simbolo de asignacion\n");
    		edo2();
		}
		else if(caracter[i]== '('|| caracter[i]== ')'|| caracter[i]== ','|| caracter[i]== '.'|| caracter[i]== '{'|| caracter[i]== '}'|| caracter[i]== '['|| caracter[i]== ']'){
    
    	printf("Cadena valida");
    			fprintf(archivo_escritura, " Simbolo de asignacion\n");
		edo3();
	}
		else if(caracter[i]== '"'){
		
			 printf("Cadena valida");
    			fprintf(archivo_escritura, " Simbolo de asignacion\n");
    		edo4();
    	}else if(caracter[i]== '+'|| caracter[i]== '-'|| caracter[i]== '/'|| caracter[i]== '*'){
    		
			printf("Cadena valida");
    		fprintf(archivo_escritura, " Simbolo de asignacion\n");
    		edo6();
    		}else if(caracter[i]== '<'|| caracter[i]== '>'){
    		
			 printf("Cadena valida");
    			fprintf(archivo_escritura, " Simbolo de asignacion\n");
    		edo8();
		}
    	else{
			printf("i= %i, caracter leido No Valido en E7= %c\n", caracter[i]);
    		
    		//return;
			}
	}
void edo8(){
		i++;
	archivo_escritura = fopen ("resultado.txt", "a");
		if(caracter[i]=='<'|| caracter[i]== '>' ){
		
			 printf("caracter leido E8 = %c\n", caracter[i]);
			 fprintf(archivo_escritura, "%c", caracter[i]);
    		edo8();}
    		else if(caracter[i]==' '||caracter[i]=='\n'||caracter[i]=='\t'||caracter[i]== EOF){
    	printf("Cadena valida");
    			fprintf(archivo_escritura, " Simbolo de Comparacion\n");
    			edo0();
    		//return;
			}
				else if( (caracter[i]>=97 && caracter[i]<=122) || (caracter[i]>=65 && caracter[i]<=90) || caracter[i]=='_'){
			
				printf("Cadena valida");
    			fprintf(archivo_escritura, " Simbolo de Comparacion\n");
				edo1();
    		//return;
    	}
		else if(caracter[i]>=48 && caracter[i]<=57){
			
			 printf("Cadena valida");
    			fprintf(archivo_escritura, " Simbolo de Comparacion\n");
    		edo2();
		}
		else if(caracter[i]== '('|| caracter[i]== ')'|| caracter[i]== ','|| caracter[i]== '.'|| caracter[i]== '{'|| caracter[i]== '}'|| caracter[i]== '['|| caracter[i]== ']'){
    		
    		printf("Cadena valida");
    			fprintf(archivo_escritura, " Simbolo de Comparacion\n");
		edo3();
	}
		else if(caracter[i]== '"'){
		
			printf("Cadena valida");
    			fprintf(archivo_escritura, " Simbolo de Comparacion\n");
    		edo4();
    	}else if(caracter[i]== '+'|| caracter[i]== '-'|| caracter[i]== '/'|| caracter[i]== '*'){
    	
			printf("Cadena valida");
    			fprintf(archivo_escritura, " Simbolo de Comparacion\n");
    		edo6();
		}else if(caracter[i]== '='){
			
			printf("Cadena valida");
    			fprintf(archivo_escritura, " Simbolo de Comparacion\n");
    		edo7();
    	}

	else{
		printf("i= %i, caracter leido No Valido en E8= %c\n", caracter[i]);
	}
}
