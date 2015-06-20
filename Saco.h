/* 
 * File:   Saco.h
 * Author: usuario
 *
 * Created on 17 de junio de 2015, 06:49 PM
 */

#ifndef SACO_H
#define	SACO_H
class Artefacto;
#include <vector>

using namespace std;

class Saco {
public:
    Saco();
    Saco(const Saco& orig);
    virtual ~Saco();
    void guardarEnSaco(Artefacto*);
    void RemoverDeSaco(int);

private:
    vector< Artefacto*> artefactos;
    int totalArtefactos;
};

#endif	/* SACO_H */

