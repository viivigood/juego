/* 
 * File:   Saco.cpp
 * Author: usuario
 * 
 * Created on 17 de junio de 2015, 06:49 PM
 */

#include "Saco.h"
#include "Artefacto.h"
#include <iterator>

Saco::Saco() {
}

Saco::Saco(const Saco& orig) {
}

Saco::~Saco() {
}

void Saco::guardarEnSaco(Artefacto* elemento){
    this->totalArtefactos = this->totalArtefactos + 1;
    this->artefactos.push_back(elemento);
}

void Saco::RemoverDeSaco(int indice){
    vector<Artefacto*>::iterator iterador;
    int contador = 0;
    iterador = this->artefactos.begin();
    while(contador != indice){
        iterador++;
    }
    this->artefactos.erase(iterador);
}