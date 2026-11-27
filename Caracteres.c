#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

int main()
{
    setlocale(LC_ALL, "");
    
    char cadena1[100];

    //Variables de acumuladores
    int v=0,co=0,d=0,e=0,ca=0,p=0,pa=0,t;
    const char*vocales="aeiou";
    
    printf("Estadísticas de caracteres\n");
    
    printf("Ingresar una cadena de caracteres[0...100]\n");
    fgets(cadena1, sizeof(cadena1),stdin);
    
    //Recorrer cadena de caracteres
    for (int x=0;cadena1[x]!='\0';x++){
        char c=tolower((unsigned char) cadena1[x]);
        printf("%c",c);
        
        if(c=='\0')//si es final de caracter, salga del for
            continue;
        //Buscar una vocal dentro de una cadena 
        if (strchr(vocales,c)!=NULL){
            v++;
        }
        //Determinar si un caracter es consonante isalpha
        else if (isalpha((unsigned char)c)){
            co++;
        //Dígitos (0-9)
        }else if (isdigit((unsigned char)c)) {
            d++;  
        //Otros caracteres
        }else if(ispunct((unsigned char)c)){
            ca++; 
        }
        //Espacios
        if (isspace((unsigned char)c)) {
            e++; 
            pa = 0;
        //Palabras en la frase
        }else if (pa == 0) {
        pa = 1;
        p++;
        }
        
        
    }
    printf("Numero de vocales: %d\n",v);
    printf("Numero de consonantes: %d\n",co);
    printf("Numero de digitos: %d\n",d);
    printf("Numero de espacios en blanco: %d\n",e-1);
    printf("Numero de caracteres especiales: %d\n",ca);
    printf("Cantidad de palabras de la frase: %d\n",p);
    t=v+co+d+e+ca;
    printf("Cantidad total de caracteres: %d\n",t);   
    return 0;
}