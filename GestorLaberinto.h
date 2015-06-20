/* 
 * File:   GestorLaberinto.h
 * Author: alulab14
 *
 * Created on 12 de junio de 2015, 11:37 AM
 */

#ifndef GESTORLABERINTO_H
#define	GESTORLABERINTO_H
#include "Laberinto.h"
#define cantArchivos 9
#define letrasNombre 9
class GestorLaberinto {
public:
    GestorLaberinto();
    GestorLaberinto(const GestorLaberinto& orig);
    virtual ~GestorLaberinto();
    Laberinto* crear(char archivos[cantArchivos][letrasNombre], int* );
private:

};

#endif	/* GESTORLABERINTO_H */

