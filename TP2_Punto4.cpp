/*g)Define una variable del tipo arreglo de estructura para guardar las características(punto a) de la nucleos de PC que 
ingrese el usuario (arreglodinámico).
h)Escribe una función que  devuelva  una  PC pasando  la  estructura  como  argumento  a  la función.
i)Escribe una función a la que se le pase el puntero al arreglo de estructuras y cargue el mismo con los valores 
asignados a las características de cada PC.
j)Escribe una función que presente la lista de las PC, cada una con sus características.
k)Escribe una función que presente la PC más vieja.
l)Escribe una función que presente la PC que tiene mayor velocidad.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"}; //Matriz de char

typedef struct
{
    int velocidad;  //entre 1 y 3 Gherz
    int anio;   //entre 2000 y 2017
    int nucleos;   //entre 1 y 4
    char *tipo_cpu; //valores del arreglo tipos
}T_compu;

int aleatorio(int min,int max);
void CargaPC(T_compu *PC);
void CargaMultiple(T_compu *arreglo_pc, int num);
void MostrarPCs(T_compu *arreglo_pc, int num);
void MuestraPCvieja(T_compu *arreglo_pc, int num);
void MuestraVeloz(T_compu *arreglo_pc, int num);

int main()
{
    srand(time(NULL));
    T_compu *computadoras;
    int cant_pc;
    
    printf("Ingrese el numero de computadoras que desea cargar:");
    scanf("%d",&cant_pc);
    computadoras = (T_compu*) malloc(cant_pc * sizeof(T_compu)); //Reserva para el arreglo de N
    CargaMultiple(computadoras,cant_pc);
    MostrarPCs(computadoras,cant_pc);
    MuestraPCvieja(computadoras,cant_pc);
    MuestraVeloz(computadoras,cant_pc);
    
    scanf(" %c");
    return 0;
}

//FUNCIONES//
int aleatorio(int min,int max)
{
    return min + rand() % (max-min+1);
}
void CargaPC(T_compu *PC)
{
    PC->velocidad = aleatorio(1,3);
    PC->anio = aleatorio(2000,2017);
    PC->nucleos = aleatorio(1,4);
    PC->tipo_cpu =(char *) malloc(10 * sizeof(char)); //Hago la reserva para el puntero tipo_cpu donde se guarda 
    strcpy(PC->tipo_cpu,tipos[aleatorio(0,5)]);
}
void CargaMultiple(T_compu *arreglo_pc, int num)
{
    for (int i = 0; i < num; i++)
    {
        CargaPC((arreglo_pc + i));
    }
}
void MostrarPCs(T_compu *arreglo_pc, int num)
{
    for (int i = 0; i<num; i++)
    {
        printf("PC N° %d\n",i+1);
        printf("Velocidad: %dGhz\n",(arreglo_pc + i)->velocidad);
        printf("Año de fabricacion: %d\n",(arreglo_pc + i)->anio);
        printf("Nucleos: %d\n",(arreglo_pc + i)->nucleos);
        printf("Fabricante: %s\n\n",(arreglo_pc + i)->tipo_cpu);
    }
}
void MuestraPCvieja(T_compu *arreglo_pc, int num)
{
    T_compu aux = *arreglo_pc; //Asigno a la primera pc como mas vieja
    for (int i = 0; i < num; i++)
    {
        if ((arreglo_pc+i)->anio < aux.anio)
        {
            aux = *(arreglo_pc+i); //Seteo al menor como mas viejo
        }
    }
    printf("Velocidad PCvieja: %dGhz - Fabricacion PCvieja: %d - Nucleos PCvieja: %d - Fabricante PCvieja: %s\n\n",aux.velocidad,aux.anio,aux.nucleos,aux.tipo_cpu);
}
void MuestraVeloz(T_compu *arreglo_pc, int num)
{
    T_compu aux = *arreglo_pc; //Asigno a la primera pc como mas vieja
    for (int i = 0; i < num; i++)
    {
        if ((arreglo_pc+i)->velocidad > aux.velocidad)
        {
            aux = *(arreglo_pc+i); //Seteo al menor como mas viejo
        }
    }
    printf("Velocidad PCveloz: %dGhz - Fabricacion PCveloz: %d - Nucleos PCveloz: %d - Fabricante PCveloz: %s",aux.velocidad,aux.anio,aux.nucleos,aux.tipo_cpu);
}
