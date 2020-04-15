#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//PROTO//
int Aleatorio(int min,int max);
//
#define FILAS 15

int main()
{
    srand(time(NULL));
    int columnas = Aleatorio(5,15); //min + rand() % (max-min+1)
    int **Matriz = (int **)malloc(FILAS * sizeof(int*)); //Vector de vectores - Asignacion dinamica de filas
   //CREACION Y ASIGNACION DE LA MATRIZ
    if (Matriz == NULL)
    {
        printf("Error al asignar filas");
        exit(1);
    }
    for (int i = 0; i < FILAS; i++)
    {
        Matriz[i] = (int *)malloc(Aleatorio(5,15)*sizeof(int)); //Asignacion dinamica de las columnas
        if (Matriz == NULL)
        {
            printf("Error al asignar filas");
            exit(1);
        }
        for (int i = 0; i < FILAS; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                Matriz[i][j] = Aleatorio (100,999);
            }
            
        }
    }
    //MUESTRA LA MATRIZ
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("%d",Matriz[i][j]);
        }
    }
    scanf(" %c");
    return 0;
}
int Aleatorio(int min,int max){
    return min + rand() % (max-min+1);
}