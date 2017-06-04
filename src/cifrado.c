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
	int i,j,tam_mensaje,tam_llave;
	char cifrado[1024]={0};
	tam_llave=strlen(llave);
	tam_mensaje=strlen(mensaje);
	char nueva_llave[1024];
	int A[tam_mensaje];
	int B[tam_mensaje];
	char alfabeto[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if(tam_mensaje>tam_llave){
		for(i=0;i<tam_llave;i++){
			//VALIDAR SI HAY ESPACIO
			if(mensaje[i]==32){
				//AGREGAR EL ESPACIO A LA LLAVE
				nueva_llave[i]=32;
			}else{
				nueva_llave[i]=llave[i];
			}
		}

		i=0;
		for(j=tam_llave;j<tam_mensaje;j++){
			//VALIDAR SI HAY ESPACIO
			if(mensaje[i]==32){
				//AGREGAR EL ESPACIO A LA LLAVE
				nueva_llave[i]=32;
			}else{
				nueva_llave[j]=mensaje[i];
			}
			i++;
		}
	}else if(tam_mensaje<tam_llave){
		for(i=0;i<tam_mensaje;i++){
			nueva_llave[i]=llave[i];
		}
	}else{
		for(i=0;i<tam_llave;i++){
			//VALIDAR SI HAY ESPACIO
			if(mensaje[i]==32){
				//AGREGAR EL ESPACIO A LA LLAVE
				nueva_llave[i]=32;
			}else{
				nueva_llave[i]=llave[i];
			}
                }
	}
	i=0;
	j=0;
	int tam_nuevallave=strlen(nueva_llave);
	for(i=0;i<tam_nuevallave;i++){
		//VALIDAR SI HAY ESPACIO
		if(nueva_llave[i]!=32){
			for(j=0;j<26;j++){
				if(nueva_llave[i]==alfabeto[j]){
					A[i]=j;
				}
			}
		}else {
		//SI HAY ESPACIO ESA CASILLA DARLE CUALQUIER VALOR
			A[i]=69;
		}
	}
	i=0;
	j=0;

	for(i=0;i<tam_nuevallave;i++){ 
		//VALIDAR SI HAY ESPACIO
                if(nueva_llave[i]!=32){
			for(j=0;j<26;j++){
				if(mensaje[i]==alfabeto[j]){
					B[i]=j;
				}
			}
		}else{
			B[i]=69;
		}
        }
	i=0;
	j=0;
	for(i=0;i<tam_nuevallave;i++){
		if(A[i]!=69){		
			j=A[i]+B[i];
			cifrado[i]=alfabeto[j%26];
		}else if (A[i]==32){
		//SI HAY ESPACIO EN LA CADENA CIFRADO AGREGAR UN ESPACIO
			cifrado[i]=32;
		}
	}
	printf("Mensaje cifrado por contraseña: ");
	printf(cifrado);
	printf("\n");
	return cifrado;
}

