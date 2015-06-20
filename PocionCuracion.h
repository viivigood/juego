/* 
 * File:   PocionCuracion.h
 * Author: usuario
 *
 * Created on 17 de junio de 2015, 06:38 PM
 */

#ifndef POCIONCURACION_H
#define	POCIONCURACION_H
#include "Entidad.h"
#include "Artefacto.h"
class PocionCuracion : public Artefacto{
public:
    PocionCuracion();
    PocionCuracion(const PocionCuracion& orig);
    virtual ~PocionCuracion();
    virtual void usar(Entidad&);
private:
    int puntosVida;
};

#endif	/* POCIONCURACION_H */

