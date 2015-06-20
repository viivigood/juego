/* 
 * File:   Entidad.cpp
 * Author: usuario
 * 
 * Created on 6 de junio de 2015, 02:19 PM
 */

#include "Entidad.h"
#include <iostream>
using namespace std;

Entidad::Entidad() {
    this->maxVida = 25;
    this->vidaActual = this->maxVida;
    this->danhoMin = 10;
    this->danhoMax = 20;
    this->defensa = 5;
}

Entidad::Entidad(string nombre) {
    this->nombre = nombre;
}

Entidad::Entidad(const Entidad& orig) {
}

Entidad::~Entidad() {
}

void Entidad::SetVidaActual(int vida) {
    if (vida > this->maxVida) {
        this->vidaActual = this->maxVida;
    } else {
        this->vidaActual = vida;
    }
}

int Entidad::GetVidaActual() {
    return this->vidaActual;
}

void Entidad::SetDefensa(int defensa) {
    this->defensa = defensa;
}

int Entidad::GetDefensa() {
    return this->defensa;
}

void Entidad::SetDanhoMin(int danhoMin) {
    this->danhoMin = danhoMin;
}

int Entidad::GetDanhoMin() const {
    return danhoMin;
}

void Entidad::SetDanhoMax(int danhoMax) {
    this->danhoMax = danhoMax;
}

int Entidad::GetDanhoMax() const {
    return danhoMax;
}

void Entidad::usar(int indice){
    //Primero usar
    
    //Luego sacar del saco
    this->bolsa.RemoverDeSaco(indice);
}

ostream& operator<<(ostream&,const Entidad& personaje){
    cout << personaje.nombre << " " << personaje.vidaActual << "hp" << endl;
    cout << personaje.defensa << " " << (personaje.danhoMax + personaje.danhoMin)/2 << endl;
}