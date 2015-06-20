/* 
 * File:   Celda.h
 * Author: alulab14
 *
 * Created on 12 de junio de 2015, 11:25 AM
 */

#ifndef CELDA_H
#define	CELDA_H
#include <iostream>
using namespace std;
class Celda {
public:
    Celda();
    Celda(char);
    Celda(const Celda& orig);
    virtual ~Celda();
    char GetTipo();
    void SetTipo(char c);
    friend istream& operator>>(istream&,Celda&c);
    friend ostream& operator<<(ostream&,Celda&c);
    Celda& operator=(const Celda&c);
    Celda& operator=(char);
private:
    int tipo;
};

#endif	/* CELDA_H */

