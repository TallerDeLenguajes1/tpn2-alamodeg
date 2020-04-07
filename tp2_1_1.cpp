#include <stdio.h>

#define FILA 4
#define COLUMNA 5

int main(){
    int f,c;
    double Matriz[FILA][COLUMNA];
    for(f = 0;f<FILA; f++)
    {
        for(f = 0;f<FILA; f++)
        {
            printf("%lf   ", Matriz[f][c]);
        }
    }    
    printf("\n");
    getchar();
    return 0;
}
