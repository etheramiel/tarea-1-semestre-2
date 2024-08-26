#include<fstream>
#include<iostream>
#include<sstream>
#include<string>


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




};


//LISTO


void instrucciones(std::string nombre_archivo, std::string *&instruccion){


    int cant_instrucciones = 0;
    std::ifstream archivo(nombre_archivo);

    if (archivo.is_open()) {
        
        std::string linea;
        int largo_max, cant_programas;
        archivo>>largo_max>>cant_programas;

        
        archivo.clear(); // Restablecer el puntero del archivo al inicio
        archivo.seekg(0, std::ios::beg); // Mover el puntºero del archivo al inicio
        

        while (std::getline(archivo, linea)) {
            cant_instrucciones++;
        }
        
        archivo.clear(); // Restablecer el puntero del archivo al inicio
        archivo.seekg(0, std::ios::beg); // Mover el puntºero del archivo al inicio

        instruccion = new std::string[cant_instrucciones];  //BORRAR AL FINALIZAR EL PROGRAMA
        int i = 0;
        while(std::getline(archivo, linea)){
            
            instruccion[i] = linea;
            //std::cout<<instruccion[i]<<std::endl;
            
            i++;  
        }        

        std::cout<<largo_max<<std::endl;
        std::cout<<cant_programas<<std::endl;


        archivo.clear(); // Restablecer el puntero del archivo al inicio
        archivo.seekg(0, std::ios::beg); // Mover el puntero del archivo al inicio
        archivo.close();
    } else {
        std::cerr << "Error: No se pudo abrir el archivo " << nombre_archivo << std::endl;
    }
}


/*
Programa::Programa(int largo_operaciones){
    this->largo_operaciones = largo_operaciones;
    this->puntero_operaciones = new char[largo_operaciones];
    this->puntero_salida = new int[1];
    this->operaciones = new char[largo_operaciones];
}
*/


void Programa::ejecutar(){

    largo_operaciones = 1;


}



int main(){
std::string *instruccion = nullptr;
instrucciones("Programas.txt", instruccion);
//char maximo_salida = instruccion[0];

//Programa programa(maximo_salida);
//std::cout<<instruccion[0]<<std::endl;
/*
    int *arreglo;
    arreglo = new int[5];

    for(int i = 0 ; i<5; i++){
        arreglo[i] = i*2;
        std::cout<<arreglo[i];
        if(i<4){
            std::cout<<";";
        }
    }

    std::cout<<std::endl;

    char eskere = 'a' + 2;
    char eskere2 = 'A' + 2;
    char eskere3 = '0' + 2;

    std::cout<<eskere<<std::endl;
    std::cout<<eskere2<<std::endl;
    std::cout<<eskere3<<std::endl;
*/




    return 0;
}
