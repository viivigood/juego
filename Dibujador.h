/* 
 * File:   Dibujador.h
 * Author: usuario
 *
 * Created on 20 de junio de 2015, 08:42 AM
 */

#ifndef DIBUJADOR_H
#define	DIBUJADOR_H

class Laberinto;
class Entidad;
class Dibujador {
public:
    Dibujador();
    Dibujador(const Dibujador& orig);
    virtual ~Dibujador();
    void dibujaLaberinto(const Laberinto&);
    void dibujaLaberinto(const Laberinto&, int x, int y);
    void dibujarAccionesLaberinto();
private:
    int A;
    int B;
};

#endif	/* DIBUJADOR_H */

