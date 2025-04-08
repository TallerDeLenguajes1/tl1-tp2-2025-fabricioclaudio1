#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int N = 5;

struct compu {
    int velocidad; // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio; // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu; // Tipo de procesador (apuntador a cadena de caracteres)
   }typedef PC;

   void listarPCs(struct compu pcs[], int cantidad);
   void mostrarMasVieja(struct compu pcs[], int cantidad);


int main (){
    srand(time(NULL));

    PC pcGeneradas[N];
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    
    //Genero las caracteristicas de las 5 compus de forma aleatoria
    for (int i = 0; i < N; i++)
    {
        pcGeneradas[i].velocidad = rand()%3+1; //Genero aleatorio del 0 al 2 le sumo 1 al valor que salga
        pcGeneradas[i].anio = rand()%10+2015; //Genero aleatorio del 0 al 9 le sumo 2015 al valor que salga
        pcGeneradas[i].cantidad_nucleos = rand()%8+1; //Genero aleatorio del 0 al 7 y le sumo 1 al valor que salga
        pcGeneradas[i].tipo_cpu = tipos[rand()%6]; //Genero aleatorio del 0 al 5 que representan a cada cpu de la variable tipos
    }

    listarPCs(pcGeneradas, N);
    mostrarMasVieja(pcGeneradas, N);

    return 0;
}

void listarPCs(struct compu pcs[], int cantidad){

    for (int i = 0; i < N; i++)
    {
        printf("--- Computadora: %d ---\n",i+1);
        printf("Velocidad: %d \n", pcs[i].velocidad);
        printf("Anio: %d \n",pcs[i].anio);
        printf("Cantidad de Nucleos: %d\n",pcs[i].cantidad_nucleos);
        printf("Tipo de cpu: %s\n",pcs[i].tipo_cpu);  
        printf("------------------------\n"); 
    }

}

void mostrarMasVieja(struct compu pcs[], int cantidad){

    PC pcMasVieja;
    pcMasVieja.anio = 2025;
    
    for (int i = 0; i < N; i++)
    {
        if (pcs[i].anio < pcMasVieja.anio)
        {
            pcMasVieja = pcs[i];
        }
    }
    printf("--- La computadora mas vieja es ---\n");
    printf("Velocidad: %d \n", pcMasVieja.velocidad);
    printf("Anio: %d \n",pcMasVieja.anio);
    printf("Cantidad de Nucleos: %d\n",pcMasVieja.cantidad_nucleos);
    printf("Tipo de cpu: %s\n",pcMasVieja.tipo_cpu);  
    printf("------------------------\n"); 
}

