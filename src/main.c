
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "cifrado.h"
#include "codificacion.h"
#define TAMANO 1024

char* cifrar(char cadena[TAMANO], int n);
int buscar(char a, char texto[TAMANO]);
int verificar(char letra);
void morse(char codigo[TAMANO]);

int main(int argc, char **argv){
	char* porConsola;
	porConsola=(char *)argv[2];
	char* otro1=argv[1];
	int otro=0;
	if (argc==3){
		for (int j=0;j<strlen(otro1);j++){
                	otro+=(otro1[j]-'0')*(pow(10,(strlen(otro1)-1-j)));
        	}
                char* retorno=cifrar(porConsola,otro);
		printf("Mensaje cifrado: %s \n",retorno);
		printf("Mensaje cifrado en Morse: ");
		morse(retorno);
		return 0;
        }
	char tipo[TAMANO];
	printf("Ingrese el tipo de cifrado que desea usar (C,A,P):\n");
	scanf("%s", tipo);
	
	if (strcmp(tipo,"C")==0){
		printf("Cifrado ciclico\n");
		printf("Ingrese el mensaje a cifrar: \n");
		char cadenaCode[TAMANO];
		scanf("%d", tipo);
		scanf("%[a-z A-Z0-9.,@_|°!#$%&\"\\/()*={}]", cadenaCode);
		printf("Ingrese la clave numerica: \n");
		int num;
		scanf("%d", &num);
		
		char* mensajeCifrado;
		mensajeCifrado=cifrar(cadenaCode,num);
		printf("Mensaje cifrado: %s \n", mensajeCifrado);

		printf("Mensaje cifrado en Morse: ");

		morse(mensajeCifrado);
	}
	if (strcmp(tipo,"A")==0){
		printf("Cifrado ciclico\n");
		printf("Ingrese el mensaje a cifrar: \n");
		char cadenaCode[TAMANO];
		scanf("%d", tipo);
		scanf("%[a-z A-Z0-9.,@_|°!#$%&\"\\/()*={}]", cadenaCode);
		char llave[1024]={0};
		printf("%s \nIntroduce llave: ",cadenaCode);
		
		scanf("%s", llave);
		cifradoAutollave(cadenaCode,llave);
	}

	return 0;
}




