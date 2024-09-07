#ifndef INTERPRETE_HPP
#define INTERPRETE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "programa.hpp"
#include "instrucciones.hpp"

class Interprete {
    private :
        int cant_programas ;
        int largo_salida ;
        int cargado ;
        Programa * programas ;
        int * salida ;

        bool programa_cargado;
        int numero_programa;
        std::string *instruccion;

    public :
        Interprete ( int cant_programas , int largo_salidas ) ;
        void cargar_programa ( int n ) ;                                    
        void ejecutar_programa () ;                 
        void mostrar_programa_cargado () ;                                  
        void terminar_ejecucion () ;

        ~Interprete() ;                                            
        void extraer_datos();                                   


};



Interprete::~Interprete() {

}

Interprete::Interprete(int cant_programas, int largo_salida) {
    this->cant_programas = cant_programas;
    this->largo_salida = largo_salida;
    this->cargado = 0;
    this->programas = new Programa[cant_programas];
    this->salida = new int[largo_salida];
    this->programa_cargado = false;
    
};

void Interprete::extraer_datos(){
    instrucciones("Programas.txt", instruccion, cant_programas, largo_salida);
};


void Interprete::cargar_programa(int n) {
    
    extraer_datos();
    programa_cargado = true;
    programas[n] = Programa((int)instruccion[n].length());
    numero_programa = n;
    
};

void Interprete::ejecutar_programa() {
    
    if(programa_cargado){
        programas[numero_programa].crear_arreglo_operaciones(instruccion[numero_programa], largo_salida);
    
        programas[numero_programa].ejecutar();
    }

};

void Interprete::mostrar_programa_cargado(){
    if(programa_cargado){
        std::cout<<instruccion[numero_programa]<<std::endl;
    }
    else{
        std::cout<<"sin instrucciones"<<std::endl;
    }
}

void Interprete::terminar_ejecucion(){
    programas->terminar_programa();
    delete [] programas;
    delete [] salida;
    delete [] instruccion;
}
#endif



