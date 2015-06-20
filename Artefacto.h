/* 
 * File:   Artefacto.h
 * Author: usuario
 *
 * Created on 6 de junio de 2015, 02:19 PM
 */

#ifndef ARTEFACTO_H
#define	ARTEFACTO_H

class Entidad;

using namespace std;
class Artefacto {    
friend class Saco;
public:
    Artefacto();
    Artefacto(const Artefacto& orig);
    virtual ~Artefacto();

    virtual void usar(Entidad&) = 0;
private:
    Artefacto* sig;
};

#endif	/* ARTEFACTO_H */

