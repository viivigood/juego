/* 
 * File:   main.cpp
 * Author: usuario
 *
 * Created on 6 de junio de 2015, 02:17 PM
 */

#include <cstdlib>
#include <iostream>
#include <windows.h>
#include "Conio Archivos/include/constream"
#include "Conio Archivos/include/conio2.h"
#include "Laberinto.h"
#include "Dibujador.h"
#include "GestorLaberinto.h"
#include "auxiliar.h"
#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
#include "Heroe.h"
using namespace std;

/*
 * 
 */
void prueba(){
    cout << "*";
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = 4;
    dwPos.Y = 5;
    SetConsoleCursorPosition(hCon,dwPos);
    cout << "*";
}
void ocultarCursor(){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hCon,&cci);
}
void test_Movimiento_con_teclas(){
    ocultarCursor();
    int juego = 0;
    int x = 10,y = 10;
    gotoxy(x,y);
    cout << "*";
    textcolor(3);
    while(juego!=1){        
        
        if(kbhit()){
            char tecla = getch();
            gotoxy(x,y);
            cout << " ";
            if(tecla == ARRIBA) y--;
            if(tecla == IZQUIERDA) x--;
            if(tecla == ABAJO) y++;
            if(tecla == DERECHA) x++;
            if(tecla == 'x') juego = 1;
            gotoxy(x,y);
            cout << "*";
        }
        Sleep(30);
    }
}

void dibujarLaberinto(){
    //int cantArchivos = 9;
    Heroe principe("Carlo");
    Dibujador dibujante;
    GestorLaberinto gestor;
    Laberinto* laberintos;
    char archivos[9][9]={"lab1.txt","lab2.txt","lab3.txt","lab4.txt","lab5.txt","lab6.txt","lab7.txt","lab7.txt","lab7.txt"};
    cout << "creo " << endl;
    cout << archivos[0] << endl;
    int *indices=crearArreglo(cantArchivos);
    laberintos = gestor.crear(archivos,indices );
    //cout << "carga laberintos" << endl;
    //dibujante.dibujaLaberinto(laberintos[0]);
    clrscr();
    cout << " vista Laberinto ";
    //Le paso la posición del "heroe"
    dibujante.dibujaLaberinto(laberintos[0],5,7);
    dibujante.dibujarAccionesLaberinto();
}
int main(int argc, char** argv) {
    //test_Movimiento();
    dibujarLaberinto();
    return 0;
}

