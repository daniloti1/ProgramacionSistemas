#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* cifradoContrasena(char* mensaje,char* llave);

int main(){
	char palabra[1024]={0};
	char llave[1024]={0};
	printf("Introduce el mensaje: ");
	gets(palabra);
	printf("Introduce llave: ");
	gets(llave);
	cifradoContrasena(palabra,llave);
	return 0;
}

char* cifradoContrasena(char* mensaje,char* llave){
	int i,j,tam_mensaje,tam_llave;
	char cifrado[1024];
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
	printf(nueva_llave);
	printf("\n");
	i=0;
	j=0;
	int tam_nuevallave=strlen(nueva_llave);
	for(i=0;i<tam_nuevallave;i++){
		//VALIDAR SI HAY ESPACIO
		if(nueva_llave[i]!=" "){
			for(j=0;j<26;j++){
				if(nueva_llave[i]==alfabeto[j]){
					A[i]=j;
				}
			}
		}else{
		//SI HAY ESPACIO ESA CASILLA DARLE CUALQUIER VALOR
			A[i]=69;
		}
	}
	i=0;
	j=0;
	for(i=0;i<tam_nuevallave;i++){
		printf("%d",A[i]);
	}
	printf("\n");
	i=0;
	for(i=0;i<tam_nuevallave;i++){ 
		//VALIDAR SI HAY ESPACIO
                if(nueva_llave[i]!=" "){
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
		printf("%d",B[i]);
	}
	printf("\n");
	i=0;
	for(i=0;i<tam_nuevallave;i++){
		if(A[i]!=69){		
			j=A[i]+B[i];
			cifrado[i]=alfabeto[j%26];
		}else{
		//SI HAY ESPACIO EN LA CADENA CIFRADO AGREGAR UN ESPACIO
			cifrado[i]=" ";
		}
	}
	printf(cifrado);
	return cifrado;
}
