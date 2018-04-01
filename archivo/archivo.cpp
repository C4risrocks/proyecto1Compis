#include<stdio.h>
#include<string.h>

int main(){
	FILE *apt = fopen("texto.txt","r");
	FILE *nuevo = fopen("nuevo.txt","w");
	char c;
	int countline=0;
	int i=0;
	char palabra[30];

	if(apt==NULL){
		perror("ERROR: 404");
		return 0;
	}else{


		while (feof(apt) == NULL) {

			i=0;
			for(int j=0;j<30;j++)
			palabra[j]=' ';


			do{
				c = fgetc(apt);
				palabra[i]=c;
				i++;
			}while(c!=' '||c=='\n'||c== EOF||c=='\t');

			fprintf(nuevo, "%s",palabra);

			if (c=='\n'||c== EOF)
			countline++;
			printf("%c\n",c);

		}
		printf ("%i ",countline);


	}

}


