/* 
 * File:   Arma.cpp
 * Author: usuario
 * 
 * Created on 17 de junio de 2015, 06:33 PM
 */

#include "Arma.h"

Arma::Arma() {
}


Arma::Arma(const Arma& orig) {
    
}

Arma::~Arma() {
    
}

void Arma::usar(Entidad& tipo){
    int danhoMin = tipo.GetDanhoMin(),danhoMax = tipo.GetDanhoMax();
    danhoMin = danhoMin + this->danhoMin;
    danhoMax = danhoMax + this->danhoMax;
    tipo.SetDanhoMax(danhoMax);
    tipo.SetDanhoMin(danhoMin);
}