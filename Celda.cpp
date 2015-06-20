/* 
 * File:   Celda.cpp
 * Author: alulab14
 * 
 * Created on 12 de junio de 2015, 11:25 AM
 */

#include "Celda.h"

Celda::Celda() {
    tipo=' ';
}
Celda::Celda(char x) {
    tipo=x;
}
Celda::Celda(const Celda& orig) {
    tipo=orig.tipo;
}

Celda::~Celda() {
}

char Celda::GetTipo(){
    return (char)tipo;
}

void Celda::SetTipo(char c){
    tipo=c;
}

istream& operator>>(istream&in,Celda&c){
    char car;
    in.get(car);
    //cout<<car;
    c.tipo=car;
    return in;
}

ostream& operator<<(ostream&out,Celda&c){
    out<<c.GetTipo();
    return out;
}

Celda& Celda::operator=(const Celda&orig){
    this->tipo=orig.tipo;
    return *this;       
}

Celda& Celda::operator=(char x){
    this->tipo = x;
    return *this;
}
