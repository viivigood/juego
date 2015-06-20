#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

#include "auxiliar.h"

int* crearArreglo(int cant){ 
    int i, j, a, b, aleatorio; 

    int *arreglo = new int[cant]; 

    for(j=0;j<cant;++j) arreglo[j]=-1; 

    /* Conseguimos una semilla */ 
    srand(time(NULL)); 

    /* Usamos la función para obtener números */ 
    for(i=0;i<cant;i++){ 
        aleatorio=alea(0,cant-1); 
        for(j=0;j<cant;++j){ 
            if(arreglo[j] == aleatorio){ 
                aleatorio = alea(0,cant-1); 
                j=-1; 
            } 
            else if(arreglo[j]==-1){ 
                arreglo[j] = aleatorio; 
                break; 
            } 
        } 
        printf("%i\n", arreglo[i]); 
        //getchar(); 
    } 
    return arreglo; 
} 


int alea(int desde, int hasta){  
    return rand()%(hasta-desde+1)+desde; 
} 

void crearArregloPorcentajes(double*& pctMon, double*& pctArt, int cant){
    double porcentajeInicial = 0.25; //Monstruos inicia con 25% y Artefactos con 75%
    for(int i = 0; i < cant; i++){
        pctMon[i] = porcentajeInicial + i*0.05; //sube 5% por nivel
        pctArt[i] = 1-porcentajeInicial - i*0.05; //Disminuye 5% por nivel
    }
}

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}