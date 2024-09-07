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


        int numero_programa;
        std::string *instruccion;


    public :
        Interprete ( int cant_programas , int largo_salidas ) ;     //LISTO
        void cargar_programa ( int n ) ;                         //LISTO            
        void ejecutar_programa () ;                 //LISTO 
        void mostrar_programa_cargado () ;                                  //LISTO
        void terminar_ejecucion () ;

        ~Interprete() ;                                             //LISTO 
        void extraer_datos();                                   //LISTO


};

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Interprete::~Interprete() {

}

Interprete::Interprete(int cant_programas, int largo_salida) {
    this->cant_programas = cant_programas;
    this->largo_salida = largo_salida;
    //this->cargado = 0;
    this->programas = new Programa[cant_programas];
    this->salida = new int[largo_salida];
    
};

void Interprete::extraer_datos(){
    instrucciones("Programas.txt", instruccion, cant_programas, largo_salida);
};


void Interprete::cargar_programa(int n) {
    extraer_datos();
    std::cout<<instruccion[n].length()<<std::endl;
    programas[n] = Programa((int)instruccion[n].length());
    numero_programa = n;
 
};

void Interprete::ejecutar_programa() {
    programas[numero_programa].crear_arreglo_operaciones(instruccion[numero_programa], largo_salida);
    programas[numero_programa].ejecutar();
    

};

void Interprete::mostrar_programa_cargado(){
   std::cout<<instruccion[numero_programa]<<std::endl;
}

void Interprete::terminar_ejecucion(){
    programas->terminar_programa();
    delete [] programas;
    delete [] salida;
    delete [] instruccion;
}
#endif




































// Interprete::Interprete(int cant_programas, int largo_salida) {
//     this->cant_programas = cant_programas;
//     this->largo_salida = largo_salida;
// };




// void Interprete::recibir_instrucciones(std::string *instruccion, int &cant_programas) {
//     instrucciones_recibidas =  instruccion;
// };



// void Interprete::cargar_programa(int n) {
    
//     Programa programa_interprete((int)instrucciones_recibidas[n].length());

//     char *operaciones_caracter;
//     operaciones_caracter = new char[(int)instrucciones_recibidas[n].length()];
//     for(int i = 0; i<(int)instrucciones_recibidas[n].length(); i++){
//         operaciones_caracter[i] = instrucciones_recibidas[n][i];
//     }   

//     programa_interprete.recibir_datos(operaciones_caracter, (int)instrucciones_recibidas[n].length());


//};