#ifndef PROGRAMA_HPP
#define PROGRAMA_HPP

#include <iostream>
#include <fstream>
#include <string>


class Programa {

private :
int largo_operaciones ;
char * puntero_operaciones ;
int * puntero_salida ;
char * operaciones ;


std::string *instruccion;

int largo_max;
int contador = 0;

public :
void ejecutar_operador () ;
void mover ( char dir ) ;
void asignar ( int valor , int * salida ) ;
char obtener () ;
void terminar_programa () ;
Programa();
Programa ( int largo_operaciones ) ;
~Programa();
void ejecutar () ;

void extraer_datos();
void crear_arreglo_operaciones(std::string instrucciones, int largo_salida);


};


Programa::~Programa() {
    delete[] operaciones;
    delete[] puntero_salida;
}

Programa::Programa() {

    largo_operaciones = 0;
    operaciones = new char [ largo_operaciones ] ;
    puntero_operaciones = operaciones ;
    puntero_salida = NULL ;

}

Programa::Programa(int largo_operaciones){
    this->largo_operaciones = largo_operaciones;
    this->operaciones = new char[largo_operaciones];
    this->puntero_salida = new int[1];
    *puntero_salida = 0;
}

char Programa::obtener(){

    char especiales[] = {'.' , ':' , '+' , '-' , '<', '>' , '[' , ']' , '!'};  
  

    if(*puntero_salida > 71 || *puntero_salida < 0){
        *puntero_salida = abs(*puntero_salida) % 72;
    }

    if(*puntero_salida == 0){
        return ' ';
    }

    else if (*puntero_salida > 0 && *puntero_salida < 27){
        return 'a' + (*puntero_salida - 1);
    }

    else if (*puntero_salida > 26 && *puntero_salida < 53){
        return 'A' + (*puntero_salida - 27);
    }

    else if (*puntero_salida > 52 && *puntero_salida < 63){
        return '0' + (*puntero_salida - 53);
    }

    else if (*puntero_salida > 62 && *puntero_salida < 72){
        return especiales[*puntero_salida - 63];
    }
    return ' ';
}

void Programa::ejecutar_operador(){

      
    
    while (*puntero_operaciones != '!') {        

        if(*puntero_operaciones == '>'){
            mover('>'); 
            contador++;
        }

        else if(*puntero_operaciones == '<'){
            mover('<');
            contador--;
        }

        else if(*puntero_operaciones == '+'){
            ++(*puntero_salida);
        }

        else if(*puntero_operaciones == '-'){
            --(*puntero_salida);
        }

        else if(*puntero_operaciones == '.'){
            std::cout<<*puntero_salida;
            
        }

        else if(*puntero_operaciones == ':'){
            std::cout<<obtener();
            
        }
        
        else if(*puntero_operaciones == '['){
            if(*puntero_salida == 0){
                int contador = 1;
                while(contador != 0){
                    ++puntero_operaciones;
                    if(*puntero_operaciones == '['){
                        ++contador;
                    }
                    else if(*puntero_operaciones == ']'){
                        --contador;
                    }
                }
            }
        }
        else if(*puntero_operaciones == ']'){
            if(*puntero_salida != 0){
                int contador = 1;
                while(contador != 0){
                    --puntero_operaciones;
                    if(*puntero_operaciones == '['){
                        --contador;
                    }
                    else if(*puntero_operaciones == ']'){
                        ++contador;
                    }
                }
            }     
        }
       
        ++puntero_operaciones;
            
    }
    
};

void Programa::crear_arreglo_operaciones(std::string instrucciones, int largo_salida){
    operaciones = new char[largo_salida];
    for(int i = 0; i < (int)instrucciones.length(); i++){
        
        operaciones[i] = instrucciones[i];
     
    }

   
    largo_max = largo_salida;

}

void Programa::ejecutar() {
    puntero_salida = new int[largo_max];
    puntero_operaciones = operaciones;
    for(int i = 0; i < largo_max; i++){
        puntero_salida[i] = 0;
        
    }
    

    for (int i = 0; i < largo_operaciones; i++) {
        //std::cout<<operaciones[i];
        ejecutar_operador();
        
        
    }
    std::cout<<std::endl;
    
}


void Programa::mover(char dir){
    
    if (dir=='<'){
        --puntero_salida;
    }
    else if (dir=='>'){
        
        ++puntero_salida;
        
    }
}


void Programa::asignar ( int valor , int * salida ) {

    *salida = valor;
}


//LISTO

void Programa::terminar_programa(){
    delete [] puntero_operaciones;
    delete [] puntero_salida;
    delete [] operaciones;
    delete [] instruccion;
   


}






// Programa::Programa(int largo_operaciones){
//     this->largo_operaciones = largo_operaciones;


//     this->puntero_operaciones = new char[largo_operaciones];
//     this->puntero_salida = new int[1];
//     this->operaciones = new char[largo_operaciones];
// }


// void Programa::recibir_datos(char *operaciones_interprete, int largo_operaciones){
//     operaciones = operaciones_interprete;
//     std::cout<<operaciones[1];

//     for(int i = 0; i<largo_operaciones; i++){
//         std::cout<<operaciones[i];
//     }
// }


// void Programa::ejecutar_operador(){


// };




#endif