#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* cifradoAutollave(char* mensaje,char* llave);

int main(){
	char palabra[1024]={0};
	char llave[1024]={0};
	printf("Introduce el mensaje: ");
	gets(palabra);
	printf("Introduce llave: ");
	gets(llave);
	cifradoAutollave(palabra,llave);
	return 0;
}




char* cifradoAutollave(char* mensaje,char* llave){
	int i,tam_mensaje,tam_llave;
	char cifrado[1024];
	tam_llave=strlen(llave);
	tam_mensaje=strlen(mensaje);
	char nuevo_alfabeto[26];
	char alfabeto[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for(i=0;i<=tam_llave;i++){
		nuevo_alfabeto[i]=llave[i];
	}
	printf(nuevo_alfabeto);
	printf("\n");
	int j=0;
	for(i=tam_llave;i<26;i++){
		nuevo_alfabeto[i]=alfabeto[j];
		j++;
	}
	printf(nuevo_alfabeto);
        printf("\n");
	i=0;
	j=0;
	for(i=0;i<tam_mensaje;i++){
		for(j=0;j<26;j++){
			if(mensaje[i]==alfabeto[j]){
				printf("Entro %d",j);
				printf("\n");
				cifrado[i]=nuevo_alfabeto[j];
			}
			if(mensaje[i]==" "){
				cifrado[i]=" ";
			}
		}
	}
	printf(cifrado);
	printf("\n");
	return cifrado;
}
