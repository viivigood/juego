/* 
 * File:   Entidad.h
 * Author: usuario
 *
 * Created on 6 de junio de 2015, 02:19 PM
 */

#ifndef ENTIDAD_H
#define	ENTIDAD_H
#include <string>
#include "Saco.h"
class Saco;
using namespace std;

class Entidad {
public:
    Entidad();
    Entidad(string);
    Entidad(const Entidad& orig);
    virtual ~Entidad();
    void ataca(Entidad);
    void SetVidaActual(int);
    int GetVidaActual();
    void SetDefensa(int);
    int GetDefensa();
    void SetDanhoMin(int danhoMin);
    int GetDanhoMin() const;
    void SetDanhoMax(int danhoMax);
    int GetDanhoMax() const;
    void usar(int);
    friend ostream& operator<<(ostream&,const Entidad&);
    //void usar(Entidad);
    //void guarda(class Artefacto);
private:
    int maxVida;
    int vidaActual;
    string nombre;
    int x;
    int y;
    int defensa;
    int danhoMax;
    int danhoMin;
    Saco bolsa;
};

#endif	/* ENTIDAD_H */

