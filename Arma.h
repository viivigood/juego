/* 
 * File:   Arma.h
 * Author: usuario
 *
 * Created on 17 de junio de 2015, 06:33 PM
 */

#ifndef ARMA_H
#define	ARMA_H
#include "Artefacto.h"
#include "Entidad.h"
#include <string>
using namespace std;

class Arma : public Artefacto {
public:
    Arma();
    Arma(const Arma& orig);
    virtual ~Arma();
    virtual void usar(Entidad&);
private:
    string nombre;
    int danhoMin;
    int danhoMax;
};

#endif	/* ARMA_H */

