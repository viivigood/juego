/* 
 * File:   Laberinto.cpp
 * Author: alulab14
 * 
 * Created on 12 de junio de 2015, 11:28 AM
 */

#include "Laberinto.h"
#include <cstdlib>
#include <iostream>

using namespace std;
Laberinto::Laberinto() {
    M=0;
    N=0;
    pctMonstruo=0;
    pctArtefacto=0;
}
Laberinto::Laberinto(int M,int N,Celda lab[MAX][MAX]){
    setLab(M,N,lab);
}
Laberinto::Laberinto(const Laberinto& orig) {
}

Laberinto::~Laberinto() {
    
}

void Laberinto::SetNivelesArtefacto(int*nivelesArtefacto) {
    for (int i=0;i<niveles;i++)
        this->nivelesArtefacto[i] = nivelesArtefacto[i];
}

void Laberinto::SetPctArtefacto(double pctArtefacto) {
    this->pctArtefacto = pctArtefacto;
}

void Laberinto::SetNivelesMonstruo(int*nivelesMonstruo) {
    for (int i=0;i<niveles;i++)
        this->nivelesMonstruo[i] = nivelesMonstruo[i];
}

void Laberinto::SetPctMonstruo(double pctMonstruo) {
    this->pctMonstruo = pctMonstruo;
}

Laberinto& Laberinto::operator=( Laberinto&orig){
    setLab(orig.M,orig.N,orig.lab);
    SetNivelesArtefacto(orig.nivelesArtefacto);
    SetPctArtefacto(orig.pctArtefacto);
    SetNivelesMonstruo(orig.nivelesMonstruo);
    SetPctMonstruo(orig.pctMonstruo);
    return *this;
}

void Laberinto::setLab(int M,int N,Celda lab[MAX][MAX]){
    this->M=M;
    this->N=N;
    for (int i=0;i<=M;i++)
        for(int j=0;j<=N;j++)
            this->lab[i][j]=lab[i][j];   
}

void Laberinto::imprimir(){
    for (int i=0;i<=M;i++){
        for(int j=0;j<=N;j++)
            cout<<lab[i][j];
        cout<<endl;
    }
}