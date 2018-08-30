#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE_VISIBLE 100
int main(int argc, char **argv)
{
    int *a;
    int size, n, i, j;

    // Obtenemos el número de elementos a buscar
    printf("Entre cuantos números queremos buscar? ");
    scanf("%d", &size);

    // Reservamos el espacio para el arreglo según el tamaño que nos indicaron
    a = static_cast<int *>(malloc(size * sizeof(int)));

    // Generamos la semilla para números aleatorios y llenamos el arreglo
    srand(time(NULL));
    for(i=0;i<size;i++)
    {
        a[i]=rand()/100;
    }

    // Imprimirmos el arreglo
    if(size<MAX_SIZE_VISIBLE)
    {
        for(i=0;i<size;i++)
        {
            printf("%d: %d\n",i,a[i]);
        }
    }

    // Obtenemos el número a buscar.
    printf("Que numero desea buscar ");
    scanf("%d", &n);
    j = 0;

    // recorremos el arreglo en búsqueda del elemento. Si se encuentra se imprime la posición
    for(i=0;i<size;i++)
    {
        if( a[i]==n )
        {
            printf("%d se encuentra en la posición %d\n",n,i);
            j = 1;
            return 0;
        }
    }
    // Si no se encontró número al finalizar el ciclo no existe este número en el arreglo.
    if(!j)
    {
        printf("No se encontro el número\n");
    }

    // Debemos liberar el arreglo que habíamos reservado.
    free(a);
    return 0;
}