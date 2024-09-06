#include <iostream>
#include <fstream>
#include <string>
#include "interprete.hpp"

class Programa {

private :
int largo_operaciones ;
char * puntero_operaciones ;
int * puntero_salida ;
char * operaciones ;


public :
void ejecutar_operador () ;
void mover ( char dir ) ;
void asignar ( int valor , int * salida ) ;
char obtener () ;
void terminar_programa () ;
Programa ( int largo_operaciones ) ;
void ejecutar () ;

void recibir_datos(char *operaciones, int largo_operaciones);

};

Programa::Programa(int largo_operaciones){
    this->largo_operaciones = largo_operaciones;


    this->puntero_operaciones = new char[largo_operaciones];
    this->puntero_salida = new int[1];
    this->operaciones = new char[largo_operaciones];
}


void Programa::recibir_datos(char *operaciones_interprete, int largo_operaciones){
    operaciones = operaciones_interprete;
    std::cout<<operaciones[1];

    for(int i = 0; i<largo_operaciones; i++){
        std::cout<<operaciones[i];
    }
}


void Programa::ejecutar_operador(){


};




