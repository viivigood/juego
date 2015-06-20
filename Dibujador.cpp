/* 
 * File:   Dibujador.cpp
 * Author: usuario
 * 
 * Created on 20 de junio de 2015, 08:42 AM
 */

#include "Dibujador.h"
#include "Laberinto.h"
#include "Monstruo.h"
#include "Heroe.h"
#include "Entidad.h"
#include "Conio Archivos/include/constream"
#include "Conio Archivos/include/conio2.h"
Dibujador::Dibujador() {
    this->A = 3;
    this->B = 3;
}

Dibujador::Dibujador(const Dibujador& orig) {
}

Dibujador::~Dibujador() {
}

void Dibujador::dibujaLaberinto(const Laberinto& actual){
    int x = 0, y = 0;
    gotoxy(x, y);
    for(int i = 0; i < (2*A+1); i++){//para el completo actual.N;
       gotoxy(x, y+i);
        for(int j = 0; j < (2*B+1); j++){//actual.M;
            Celda celdita;
            celdita = actual.lab[i][j];
            cout << celdita.GetTipo();
            //cout << actual.lab[i][j].GetTipo();
        }
        cout << endl;
   }
}

void Dibujador::dibujaLaberinto(const Laberinto& actual, int x, int y){
    //x e y son la posicion del heroe
    int _x = x, _y = y;
    Celda heroe('O');
    if(x-A < 0) x = A;
    if(x+A > actual.M) x = actual.M-A;
    if(y-B < 0) y = B;
    if(y+B > actual.N) y = actual.N - B;
    //gotoxy(_x, _y);
    cout << endl;
    
    for(int i = x-A; i <= (x+A); i++){//para el completo actual.N;
       //gotoxy(_x, _y++);
        for(int j = y-B; j <= (y+B); j++){//actual.M;
            Celda celdita;            
            
            celdita = actual.lab[i][j];
            if( i == _x && j == _y)
                cout << heroe.GetTipo();
            else
                cout << celdita.GetTipo();
            //cout << actual.lab[i][j].GetTipo();
        }
        cout << endl;
   }
}

void Dibujador::dibujarAccionesLaberinto(){
    textcolor(YELLOW);
    gotoxy(22,0);
    gotoxy(22,1);
    cout << "mover";
    gotoxy(22,2);
    cout << "interactuar";
    gotoxy(22,3);
    cout << "usar";
    gotoxy(22,4);
    cout << "salir";
    gotoxy(40,5);
}

