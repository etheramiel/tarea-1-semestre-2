#include <iostream>
#include <fstream>
#include <string>
#include "programa.hpp"


class Interprete {
    private :
        int cant_programas ;
        int largo_salida ;
        int cargado ;
        Programa * programas ;
        int * salida ;


        std::string * instrucciones_recibidas ;

    public :
        Interprete ( int cant_programas , int largo_salidas ) ;
        void cargar_programa ( int n ) ;
        void ejecutar_programa () ;
        void mostrar_programa_cargado () ;
        void terminar_ejecucion () ;


        void recibir_instrucciones ( std::string *instrucciones, int &cant_programas ) ;
};

Interprete::Interprete(int cant_programas, int largo_salida) {
    this->cant_programas = cant_programas;
    this->largo_salida = largo_salida;
};




void Interprete::recibir_instrucciones(std::string *instrucciones, int &cant_programas) {
    instrucciones_recibidas =  instrucciones;
};



void Interprete::cargar_programa(int n) {
    
    Programa programa_interprete((int)instrucciones_recibidas[n].length());

    char *operaciones_caracter;
    operaciones_caracter = new char[(int)instrucciones_recibidas[n].length()];
    for(int i = 0; i<(int)instrucciones_recibidas[n].length(); i++){
        operaciones_caracter[i] = instrucciones_recibidas[n][i];
    }   

    programa_interprete.recibir_datos(operaciones_caracter, (int)instrucciones_recibidas[n].length());


};