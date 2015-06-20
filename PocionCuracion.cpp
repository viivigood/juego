/* 
 * File:   PocionCuracion.cpp
 * Author: usuario
 * 
 * Created on 17 de junio de 2015, 06:38 PM
 */

#include "PocionCuracion.h"

PocionCuracion::PocionCuracion() {
    
}

PocionCuracion::PocionCuracion(const PocionCuracion& orig) {
    
}

PocionCuracion::~PocionCuracion() {
    
}

void PocionCuracion::usar(Entidad& tipo){
    int vida = tipo.GetVidaActual();
    vida = vida + this->puntosVida;
    tipo.SetVidaActual(vida);
}