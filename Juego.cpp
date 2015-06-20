/* 
 * File:   Juego.cpp
 * Author: usuario
 * 
 * Created on 18 de junio de 2015, 10:16 PM
 */

#include "Juego.h"
#include <iostream>
#include <string>
#define cantArchivos 9
#define letrasNombre 9
#include "auxiliar.h"
using namespace std;

Juego::Juego() {
}

Juego::Juego(const Juego& orig) {
}

Juego::~Juego() {
}

void Juego::iniciarHistoria(){
    //Imprime la intro del juego
    cout << "Juego de la vida" << endl;
    cout << "~-~-~-~-~-~-~-~-~" << endl;
}

int Juego::jugar(){
    string accion, direccion; //Pensado para recibir la acción que el usuario realizará
    double* pctMonstruos,*pctArtefactos; //Pensado para crear arreglos con los porcentajes
    this->iniciarHistoria();
    //Les pasamos los archivos con los nombres a gestor para que pueda cargar los laberintos
    char archivos[cantArchivos][letrasNombre]={"lab1.txt","lab2.txt","lab3.txt","lab4.txt","lab5.txt","lab6.txt","lab7.txt","lab7.txt","lab7.txt"};
    int *indices=crearArreglo(cantArchivos);
    //Creación de arreglos con los porcentajes para monstruos y artefactos
    crearArregloPorcentajes(pctMonstruos,pctArtefactos,cantArchivos);
    this->listaLaberintos=gestor.crear(archivos,indices);
    this->laberActual = this->listaLaberintos[0];
    //Crear Monstruos y artefactos
    /*for(int i=0;i<9;i++){ Y para atributo que falta Setear : NivelesMontruo y artefactos y porcentajeArtefactos
     *  arregloLaberintos[i].setPorcentajes(arregloPorcentajes[i]);
     * 
     *}
    */   
    //Insertar Monstruos y artefactos a todos los laberintos dependiendo de su nivel
    //Ubicar heroe en laberinto actual
    
    int salir = 0,ganar = 0,perder = 0; //Para determinar si el juego salió por el usuario o si se ganó o perdió

    //while( personaje.GetVida > 0 && salir != 1 && ganar != 1 && perder != 1){
        //string accionLucha;
        /*Imprimir en pantalla lo que se debe
         * Parte visible del laberinto
         * a la derecha las opciones (mover, interactuar, usar, salir
         * abajo ( nombre, vida, armadura, arma y lista de cosas en el saco)
         */
         //cin >> accion >> direccion;
         /* if (accion == "mover" ){
          *     if (direccion == A)
          *         Verificar si es posible
          *             si esa posición es SALIDA("-") && LaberintoActual != PrimerLaberinto
          *                 Regrsar a LaberintoAnterior
          *             si esa posición es ENTRADA("+")
          *                 si LaberintoActual != UltimoLaberinto
          *                     Avanzar a LaberintoSiguiente
          *                 sino
          *                     ganar = 1; //Se ganó el juego
          *         sino es posible
          *             mostrar mensaje de que hay en esa posición
          *     if (direccion == B)
          *         Verificar si es posible
          *             si esa posición es SALIDA("-") && LaberintoActual != PrimerLaberinto
          *                 Regrsar a LaberintoAnterior
          *             si esa posición es ENTRADA("+")
          *                 si LaberintoActual != UltimoLaberinto
          *                     Avanzar a LaberintoSiguiente
          *                 sino
          *                     ganar = 1; //Se ganó el juego
          *         sino es posible
          *             mostrar mensaje de que hay en esa posición
          *     if (direccion == I)
          *         Verificar si es posible
          *             si esa posición es SALIDA("-") && LaberintoActual != PrimerLaberinto
          *                 Regrsar a LaberintoAnterior
          *             si esa posición es ENTRADA("+")
          *                 si LaberintoActual != UltimoLaberinto
          *                     Avanzar a LaberintoSiguiente
          *                 sino
          *                     ganar = 1; //Se ganó el juego
          *         sino es posible
          *             mostrar mensaje de que hay en esa posición
          *     if (direccion == D)
          *         Verificar si es posible
          *             si esa posición es SALIDA("-") && LaberintoActual != PrimerLaberinto
          *                 Regrsar a LaberintoAnterior
          *             si esa posición es ENTRADA("+")
          *                 si LaberintoActual != UltimoLaberinto
          *                     Avanzar a LaberintoSiguiente
          *                 sino
          *                     ganar = 1; //Se ganó el juego
          *         sino es posible
          *             mostrar mensaje de que hay en esa posición
          * }
          * if (accion == "interactuar" ){ ->
          *     if (direccion == "A")
          *         verificar si es posible
          *         si esa posicion es A(artefacto)
          *             personaje.agregarASaco(artefacto)
          *         si esa posicion es M(monstruo)
          *             Mostrar vida de heroe y de monstruo en pantalla
          *             mostrar opciones al lado derecho (atacar, huir, usar)
          *             int huir = 0
          *             while(personaje.GetVida > 0 && huir != 1 && monstruo.GetVida > 0){
          *                 cin >> accionLucha;
          *                 if ( accionLucha == "atacar" ){
          *                     int nuevaVidaM = monstruo.GetVida() - (monstruo.GetDefensa - (personaje.GetDanhoMax() + personaje.GetDanhoMin())/2)
          *                     mosntruo.SetVida(nuevaVidaM);
          *                 }else{
          *                     if (accionLucha == "huir"){
          *                         huir = 1;
          *                         o break directo
          *                     }else{ //Usar objeto de la lista
          *                         int indice;
          *                         cout << "escoja indice" << endl;
          *                         cin >> indice;
          *                         personaje.usarObjeto(indice)                                                 
          *                     }
          *                 }
          *                 int nuevaVidaHeroe = personaje.GetVida() - (personaje.GetDefensa - (monstruo.GetDanhoMax() + monstruo.GetDanhoMin())/2)
          *                 personaje.SetVida(nuevaVidaHeroe)
          *                 if (personaje.GetVida <= 0){
          *                     perder = 1;
          *                     break;
          *              }
          *             }
          *     if (direccion == "B")
          *         verificar si es posible
          *         si esa posicion es A(artefacto)
          *             personaje.agregarASaco(artefacto)
          *         si esa posicion es M(monstruo)
          *             Mostrar vida de heroe y de monstruo en pantalla
          *             mostrar opciones al lado derecho (atacar, huir, usar)
          *             int huir = 0
          *             while(personaje.GetVida > 0 && huir != 1 && monstruo.GetVida > 0){
          *                 cin >> accionLucha;
          *                 if ( accionLucha == "atacar" ){
          *                     int nuevaVidaM = monstruo.GetVida() - (monstruo.GetDefensa - (personaje.GetDanhoMax() + personaje.GetDanhoMin())/2)
          *                     mosntruo.SetVida(nuevaVidaM);
          *                 }else{
          *                     if (accionLucha == "huir"){
          *                         huir = 1;
          *                         o break directo
          *                     }else{ //Usar objeto de la lista
          *                         int indice;
          *                         cout << "escoja indice" << endl;
          *                         cin >> indice;
          *                         personaje.usarObjeto(indice)                                                 
          *                     }
          *                 }
          *                 int nuevaVidaHeroe = personaje.GetVida() - (personaje.GetDefensa - (monstruo.GetDanhoMax() + monstruo.GetDanhoMin())/2)
          *                 personaje.SetVida(nuevaVidaHeroe)
          *                 if (personaje.GetVida <= 0){
          *                     perder = 1;
          *                     break;
          *              }
          *             }
          *     if (direccion == "I")
          *         verificar si es posible
          *         si esa posicion es A(artefacto)
          *             personaje.agregarASaco(artefacto)
          *         si esa posicion es M(monstruo)
          *             Mostrar vida de heroe y de monstruo en pantalla
          *             mostrar opciones al lado derecho (atacar, huir, usar)
          *             int huir = 0
          *             while(personaje.GetVida > 0 && huir != 1 && monstruo.GetVida > 0){
          *                 cin >> accionLucha;
          *                 if ( accionLucha == "atacar" ){
          *                     int nuevaVidaM = monstruo.GetVida() - (monstruo.GetDefensa - (personaje.GetDanhoMax() + personaje.GetDanhoMin())/2)
          *                     mosntruo.SetVida(nuevaVidaM);
          *                 }else{
          *                     if (accionLucha == "huir"){
          *                         huir = 1;
          *                         o break directo
          *                     }else{ //Usar objeto de la lista
          *                         int indice;
          *                         cout << "escoja indice" << endl;
          *                         cin >> indice;
          *                         personaje.usarObjeto(indice)                                                 
          *                     }
          *                 }
          *                 int nuevaVidaHeroe = personaje.GetVida() - (personaje.GetDefensa - (monstruo.GetDanhoMax() + monstruo.GetDanhoMin())/2)
          *                 personaje.SetVida(nuevaVidaHeroe)
          *                 if (personaje.GetVida <= 0){
          *                     perder = 1;
          *                     break;
          *              }
          *             }
          *     if (direccion == "D")
          *         verificar si es posible
          *         si esa posicion es A(artefacto)
          *             personaje.agregarASaco(artefacto)
          *         si esa posicion es M(monstruo)
          *             Mostrar vida de heroe y de monstruo en pantalla
          *             mostrar opciones al lado derecho (atacar, huir, usar)
          *             int huir = 0
          *             while(personaje.GetVida > 0 && huir != 1 && monstruo.GetVida > 0){ BUCLE PELEA
          *                 cin >> accionLucha;
          *                 if ( accionLucha == "atacar" ){
          *                     int nuevaVidaM = monstruo.GetVida() - (monstruo.GetDefensa - (personaje.GetDanhoMax() + personaje.GetDanhoMin())/2)
          *                     mosntruo.SetVida(nuevaVidaM);
          *                 }else{
          *                     if (accionLucha == "huir"){
          *                         huir = 1;
          *                         o break directo
          *                     }else{ //Usar objeto de la lista
          *                         int indice;
          *                         cout << "escoja indice" << endl;
          *                         cin >> indice;
          *                         personaje.usarObjeto(indice)                                                 
          *                     }
          *                 }
          *                 int nuevaVidaHeroe = personaje.GetVida() - (personaje.GetDefensa - (monstruo.GetDanhoMax() + monstruo.GetDanhoMin())/2)
          *                 personaje.SetVida(nuevaVidaHeroe)
          *                 if (personaje.GetVida <= 0){
          *                     perder = 1;
          *                     break;
          *              }
          *             }
          */
}