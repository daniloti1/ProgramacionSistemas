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
