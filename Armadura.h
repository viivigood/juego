/* 
 * File:   Armadura.h
 * Author: usuario
 *
 * Created on 17 de junio de 2015, 06:32 PM
 */

#ifndef ARMADURA_H
#define	ARMADURA_H
#include "Artefacto.h"
#include "Entidad.h"
#include <string>
using namespace std;

class Armadura : public Artefacto{
public:
    Armadura();
    Armadura(const Armadura& orig);
    virtual ~Armadura();
    virtual void usar( Entidad &);
private:
    string nombre;
    int defensa;
};

#endif	/* ARMADURA_H */

