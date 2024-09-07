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
        std::cout << "Cargar programa número: " << n << std::endl;
        interpreter.cargar_programa(n);
        
    } else if (comando == "e") {
        std::cout << "Ejecutar programa cargado" << std::endl;
        interpreter.ejecutar_programa();
    } else if (comando == "m") {
        std::cout << "Mostrar programa cargado" << std::endl;
        interpreter.mostrar_programa_cargado();
    } else {
        std::cout << "Terminar ejecución" << std::endl;
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
        std::cout << "Ingresa una instrucción: ";
        std::cin >> comando;
        

        if (comando == "s") {
            procesar_instruccion(comando, interpreter);
            break;
        }

        procesar_instruccion(comando, interpreter);
    }

    return 0;
}
// int main(){
//     std::string  consola;
//     char opcion1, opcion2;
//     int cant_programas = 0, largo_max = 0;
//     std::string *instruccion = nullptr;
//     instrucciones("Programas.txt", instruccion, cant_programas, largo_max);
    

//     Interprete interpreter(cant_programas, largo_max);

//     while(opcion1 != 's'){
//         std::cout << "Ingrese Opcion:" << std::endl;
//         std::cin >> consola;
//         std::cout << consola.length() << std::endl;
//         if ((int)consola.length() > 1){
//             opcion1 = consola[0];
//             opcion2 = consola[2];
//             std::cout << "Opcion 1: " << opcion1 << std::endl;
//             std::cout << "Opcion 2: " << opcion2 << std::endl;
//         }
//         else{
//             opcion1 = consola[0];
//             std::cout << "Opcion 1: " << opcion1 << std::endl;
//         }

//     }

//     return 0;


// }






// int main(){

// int cant_programas = 0, largo_max = 0;
// std::string *instruccion = nullptr;

// instrucciones("Programas.txt", instruccion, cant_programas, largo_max);



// Interprete interpreter(cant_programas, largo_max);
// interpreter.recibir_instrucciones(instruccion, cant_programas);
// interpreter.cargar_programa(1);


//     return 0;
// }
