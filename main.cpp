#include<fstream>
#include<iostream>
#include<sstream>
#include<string>
#include "interprete.hpp"
#include "programa.hpp"
#include "instrucciones.hpp"


void procesar_instruccion(const std::string& comando, Interprete& interpreter) {
    if (comando == "c") {
        int n;
        std::cin >> n;  // Leer el índice del programa       
        interpreter.cargar_programa(n);
        
    } else if (comando == "e") {
        interpreter.ejecutar_programa();
        std::cout <<  std::endl;
    } else if (comando == "m") {
        interpreter.mostrar_programa_cargado();
    } else {
        //interpreter.terminar_ejecucion();
    }
}

int main() {
    std::string comando;
    int cant_programas = 0, largo_max = 0;
    std::string *instruccion = nullptr;
    instrucciones("Programas.txt", instruccion, cant_programas, largo_max);


    Interprete interpreter(cant_programas, largo_max);


    while (true) {

        std::cin >> comando;
        

        if (comando == "s") {
            procesar_instruccion(comando, interpreter);
            break;
        }

        procesar_instruccion(comando, interpreter);
    }

    return 0;
}
