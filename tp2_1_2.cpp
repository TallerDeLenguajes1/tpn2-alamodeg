#include <stdio.h>

#define FILA 2
#define COLUMNA 3

int main(){
    int i,j;
    double Matriz[FILA][COLUMNA];
    //Matriz[i][j] == *(Matriz + (i * COLUMNA + j));

    for(i = 0; i < FILA; i++)
    {
        for(j = 0; j < COLUMNA; j++)
        {
            printf("%.2lf   ", *(Matriz + i)+j);
        }
        printf("\n");
    }    
    getchar();
    return 0;
}
