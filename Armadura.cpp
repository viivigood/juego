/* 
 * File:   Armadura.cpp
 * Author: usuario
 * 
 * Created on 17 de junio de 2015, 06:32 PM
 */

#include "Armadura.h"

Armadura::Armadura() {
    
}

Armadura::Armadura(const Armadura& orig) {
    
}

Armadura::~Armadura() {
    
}

void Armadura::usar( Entidad& tipo){
    int defensa = tipo.GetDefensa();
    defensa = defensa + this->defensa;
    tipo.SetDefensa(defensa);
}