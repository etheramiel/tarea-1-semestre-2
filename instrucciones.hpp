#ifndef INSTRUCCIONES_HPP
#define INSTRUCCIONES_HPP

#include <iostream>
#include <fstream>
#include <string>






void instrucciones(std::string nombre_archivo, std::string *&instruccion, int &cant_programas, int &largo_max) {


    int cant_instrucciones = 0;
    std::ifstream archivo(nombre_archivo);

    if (archivo.is_open()) {

        std::string linea;
        int largo_maximo, cantidad_programas;
        archivo>>largo_maximo>>cantidad_programas;
        largo_max = largo_maximo;
        cant_programas = cantidad_programas;

        archivo.clear(); // Restablecer el puntero del archivo al inicio
        archivo.seekg(0, std::ios::beg); // Mover el puntºero del archivo al inicio


        while (std::getline(archivo, linea)) {
            cant_instrucciones++;
        }

        archivo.clear(); // Restablecer el puntero del archivo al inicio
        archivo.seekg(0, std::ios::beg); // Mover el puntºero del archivo al inicio
        std::string *aux;
        aux = new std::string[cant_instrucciones];

        instruccion = new std::string[cant_instrucciones];  //BORRAR AL FINALIZAR EL PROGRAMA
        int i = 0;
        while(std::getline(archivo, linea)){

            aux[i] = linea;
            

            i++;
        }
        int j = 0;
        for(int i = 2; i<cant_instrucciones; i++){
            instruccion[j++] = aux[i];
        }
        delete[] aux;

        archivo.clear(); // Restablecer el puntero del archivo al inicio
        archivo.seekg(0, std::ios::beg); // Mover el puntero del archivo al inicio
        archivo.close();
    } else {
        std::cerr << "Error: No se pudo abrir el archivo " << nombre_archivo << std::endl;
    }
}
    
#endif