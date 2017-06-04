#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codificacion.h"
#define TAMANO 1024

char* cifrar(char cadena[TAMANO], int n){
        char* cifradoFinal=malloc(sizeof(char)*TAMANO);
        char cifrado[TAMANO];
        strcpy(cifrado,cadena);
        char alfabeto[26]="abcdefghijklmnopqrstuvwxyz";
        char alfabetoM[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int a=(int)strlen(cadena);
        for (int i=0;i<a;i++){
                if (verificar(cifrado[i])==0){
                        int b=buscar(cifrado[i],alfabeto);
                        b=(b+n)%26;
                        cifrado[i]=alfabeto[b];
                }
                else if (verificar(cifrado[i])==1){
                        int b=buscar(cifrado[i],alfabetoM);
                        b=(b+n)%26;
                        cifrado[i]=alfabetoM[b];
                }
        }
        strcpy(cifradoFinal,cifrado);
        return (char *)cifradoFinal;
}

char* cifradoAutollave(char* mensaje,char* llave){
	int i,tam_mensaje,tam_llave;
	char cifrado[1024]={0};
	
	tam_llave=strlen(llave);
	tam_mensaje=strlen(mensaje);
	char nuevo_alfabeto[26];
	char alfabeto[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for(i=0;i<=tam_llave;i++){
		nuevo_alfabeto[i]=llave[i];
	}
	int j=0;
	for(i=tam_llave;i<26;i++){
		nuevo_alfabeto[i]=alfabeto[j];
		j++;
	}
	i=0;
	j=0;
	for(i=0;i<tam_mensaje;i++){
		for(j=0;j<26;j++){
			if(mensaje[i]==alfabeto[j]){
				cifrado[i]=nuevo_alfabeto[j];
			}
			if(mensaje[i]==32){
				cifrado[i]=32;
			}
		}
	}
	printf("Mensaje encriptado por autollave: %s",cifrado);
	printf("\n");
	return cifrado;
}

char* cifradoContrasena(char* mensaje,char* llave){
	return "";
}
