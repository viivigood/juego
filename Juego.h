/* 
 * File:   Juego.h
 * Author: usuario
 *
 * Created on 18 de junio de 2015, 10:16 PM
 */

#ifndef JUEGO_H
#define	JUEGO_H
#include "Heroe.h"
#include "GestorLaberinto.h"
#include "Monstruo.h"
#include "Laberinto.h"

class Heroe;
class GestorLaberinto;
class Monstruo;
class Laberinto;

class Juego {
public:
    Juego();
    Juego(const Juego& orig);
    virtual ~Juego();
    void iniciarHistoria();
    int jugar();
private:
    Laberinto laberActual;
    Laberinto *listaLaberintos;
    Heroe heroe;
    GestorLaberinto gestor;
    Monstruo rivales[20];
};

#endif	/* JUEGO_H */

