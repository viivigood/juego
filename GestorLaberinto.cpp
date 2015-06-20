/* 
 * File:   GestorLaberinto.cpp
 * Author: alulab14
 * 
 * Created on 12 de junio de 2015, 11:37 AM
 */

#include "GestorLaberinto.h"
#include "Celda.h"
 #include "auxiliar.h"
#include "Laberinto.h"
#include "Celda.h"
#include <cstdlib>
#include <fstream>
 #include <time.h>
#define pctM 0.005
#define pctA 0.01
//#define cantArchivos 2
using namespace std;

GestorLaberinto::GestorLaberinto() {
}

GestorLaberinto::GestorLaberinto(const GestorLaberinto& orig) {
}

GestorLaberinto::~GestorLaberinto() {
    
}

Laberinto* GestorLaberinto::crear(char archivos[][letrasNombre],int*indices ){
    Laberinto *laberintos=new Laberinto[cantArchivos];
    double probM,probA;
    for (int i=0;i<cantArchivos;i++){
        
        ifstream arch(archivos[i],ios::in);
        int M=0,N=0,col=0;    
        Celda celdita;
        Celda lab2[MAX][MAX];
        
        srand(time(NULL));
        
        while(!arch.eof()){
            arch>>celdita;
            if(celdita.GetTipo()=='\n'){
                N=col;
                //cout<<endl;
                M++;
                col=0;
            }
            else if(celdita.GetTipo()==' '){
                probM=(fRand(0,1));
                probA=(fRand(0,1));
                if(pctM*i>=probM&&probA>pctA*i)//Si salio monstruo
                    celdita.SetTipo('M');
                else if(pctM*i<probM&&probA<=pctA*i)//Si salio artefacto
                    celdita.SetTipo('A');
                else if(pctM*i>=probM&&probA<=pctA*i)//Si puede ser monstruo o artefacto se coloca un artefacto
                    celdita.SetTipo('A');
                lab2[M][col]=celdita;
                col++;
            }
            else {
                lab2[M][col]=celdita;
                col++;
                //cout<<celdita.GetTipo();
            }
            
        }

        //Laberinto laberinto(M,N,lab2);
        laberintos[i].setLab(M,N,lab2);
        arch.close();
    }
    
   
    return laberintos;
        
}


/*Laberinto* GestorLaberinto::crear(char archivos[cantArchivos][letrasNombre] ){
    cout << "definió" << endl;
    Laberinto *laberintos=new Laberinto[9];
    for (int i=0;i<9;i++){        
        ifstream arch(archivos[i],ios::in);
        cout << archivos[i] << endl;
        int M=0,N=0,col=0;    
        Celda celdita;
        Celda lab2[MAX][MAX];
        while(!arch.eof()){
            arch>>celdita;
            if(celdita.GetTipo()=='\n'){
                N=col;
                //cout<<endl;
                M++;
                col=0;
            }
            else {
                lab2[M][col]=celdita;
                col++;
                //cout<<celdita.GetTipo();
            }
        }

        //Laberinto laberinto(M,N,lab2);
        laberintos[i].setLab(M,N,lab2);
        arch.close();
    }
    
   
    return laberintos;
        
}*/