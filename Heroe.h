/* 
 * File:   Heroe.h
 * Author: usuario
 *
 * Created on 18 de junio de 2015, 10:14 PM
 */

#ifndef HEROE_H
#define	HEROE_H
#include "Entidad.h"

class Heroe : public Entidad {
public:
    Heroe();
    Heroe(string );
    Heroe(const Heroe& orig);
    virtual ~Heroe();
private:

};

#endif	/* HEROE_H */

