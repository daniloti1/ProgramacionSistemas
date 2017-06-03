#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define TAMANO 1024

void morse(char mensaje[TAMANO]){
	char alfabetoMorse[36][6]={".-","_...","_._.","_..",".",".._.","__.","....","..",".___","_._","._..","__","_.","___",".__.","__._","._.","...","_",".._","..._",".__","_.._","_.__","__..","_____",".____","..___","...__","...._",".....","_....","__...","___..","____."};
	char auxiliar[TAMANO]={0};
	for (int i=0;i<strlen(mensaje);i++){
		strncpy(auxiliar,mensaje,TAMANO);
		int indice=(int)auxiliar[i];
		if (indice>=65 && indice<=90){
			indice-=65;
		}
		else if (indice>=97 && indice<=122){
			indice-=97;
		}
		else{
			indice-=22;
		}
		if (mensaje[i]==32){
			printf("/ ");
		}
		else {
			printf("%s ",alfabetoMorse[indice]);
		}
	}
	printf("\n");
}

int verificar(char letra){
	if (letra>='a' && letra<='z'){
		return 0;
	}
	if (letra>='A' && letra<='Z'){
		return 1;
	}
	return -1;
}

int buscar(char a, char texto[TAMANO]){
	int indice=-1;
	for (int i=0;i<strlen(texto);i++){
		if (a==texto[i]){
			indice=i;
			break;
		}
	}
	if (indice>25){
		indice=-1;
	}
	return indice;
}

