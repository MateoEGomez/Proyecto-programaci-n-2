#include <iostream>
#include <cstring>
#include "Pelicula.h"
using namespace std;

Pelicula::Pelicula() {

}


// lista de generos
const char* Pelicula::listaGenero[5] = {"Comedia", "Accion", "Terror", "Suspenso", "Infantil"};

const char* Pelicula::listaClasificacion[3]={"ATP", "+15", "+18" };

int Pelicula::GetIdPelicula()  {
    return _idpelicula;
}

void Pelicula::SetIdPelicula(int idPelicula) {
    _idpelicula = idPelicula;
}

const char* Pelicula::GetNombrePelicula() {
    return _nombrePelicula;

}

void Pelicula::SetNombrePelicula(const char* nombrepelicula) {
    strcpy(_nombrePelicula, nombrepelicula);
    _nombrePelicula[sizeof(_nombrePelicula)-1] = '\0';
}

const char* Pelicula::GetDirector(){
    return _director;
}

void Pelicula::SetDirector(const char* director){
    strcpy(_director, director);
    _director[sizeof(_director)-1]='\0';
}



void Pelicula::SetActivo(bool activo)
{
    _activo=activo;
}
bool Pelicula::GetActivo()
{
    return _activo;
}


void Pelicula::SetClasificacion(int clasificacion) {

     strcpy(_clasificacion,Pelicula::listaClasificacion[clasificacion]);
    _clasificacion[sizeof(_clasificacion)-1]= '\0';
}


const char* Pelicula::GetClasificacion(){
    return _clasificacion;
}

void Pelicula::SetGenero(int numGenero) {

    strcpy(_genero, Pelicula::listaGenero[numGenero] );
    _genero[sizeof(_genero)-1]= '\0';

}

const char* Pelicula::GetGenero(){
    return _genero;
}








