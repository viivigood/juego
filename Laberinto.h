/* 
 * File:   Laberinto.h
 * Author: alulab14
 *
 * Created on 12 de junio de 2015, 11:28 AM
 */

#ifndef LABERINTO_H
#define	LABERINTO_H
#include "Celda.h"
#define MAX 500
#define niveles 3
class Laberinto {
public:
    Laberinto();
    Laberinto(int M,int N,Celda lab[MAX][MAX]);
    Laberinto(const Laberinto& orig);
    friend class Dibujador;
    virtual ~Laberinto();
    void SetNivelesArtefacto(int*nivelesArtefacto);
    void SetPctArtefacto(double pctArtefacto);
    void SetNivelesMonstruo(int*nivelesMonstruo);
    void SetPctMonstruo(double pctMonstruo);
    void setLab(int M,int N,Celda lab[MAX][MAX]);
    Laberinto& operator=(Laberinto&lab);
    void imprimir();
private:
    int M;
    int N;
    double pctMonstruo;
    int nivelesMonstruo[niveles];
    double pctArtefacto;
    int nivelesArtefacto[niveles];
    Celda lab[MAX][MAX];    
    
};

#endif	/* LABERINTO_H */

