#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int aleatorio();

#define FILAS 15

int main(){
    srand(time(NULL)); 
    //int columnas = 5 + rand() % 14; //minimo + rand() % maximo-1;
    //int Matrix[FILAS][aleatorio()];
    //printf("%d",);
    getchar();
    return 0;
}
int aleatorio(){
    int aux = 5 + rand() % 14;
    return aux;
}