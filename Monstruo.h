/* 
 * File:   Monstruo.h
 * Author: usuario
 *
 * Created on 18 de junio de 2015, 10:11 PM
 */

#ifndef MONSTRUO_H
#define	MONSTRUO_H
#include "Entidad.h"

class Monstruo : public Entidad {
public:
    Monstruo();
    Monstruo(const Monstruo& orig);
    virtual ~Monstruo();
private:
    int nivel;
};

#endif	/* MONSTRUO_H */

