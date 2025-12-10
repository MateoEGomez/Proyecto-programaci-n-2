#include <iostream>
#include <cstring>
#include "Funcion.h"
using namespace std;

Funcion::Funcion()
{
    _idFuncion = 0;
    _idSala = 0;
    _idPelicula = 0;
    _cantidad = 0;
    _activa = false;
    _asientosDisponibles = nullptr;
}

Funcion::~Funcion()
{
    delete[] _asientosDisponibles;
}

//Getters
int Funcion::GetIdFuncion()
{
    return _idFuncion;
}
int Funcion::GetIdPelicula()
{
    return _idPelicula;
}
int Funcion::GetIdSala()
{
    return _idSala;
}
bool Funcion::GetActiva()
{
    return _activa;
}

int Funcion::GetcantidadAsientos()
{
    return _cantidad;
}


void Funcion::SetAsientosDisponibles(int* asientos) {

    delete[] _asientosDisponibles;

    _asientosDisponibles = asientos;
}



Fecha Funcion::GetFecha(){
    return _fecha;
}


//Setters
void Funcion::SetIdFuncion(int idFuncion)
{
    _idFuncion = idFuncion;
}

void Funcion::SetIdPelicula(int idPelicula)
{
    _idPelicula = idPelicula;
}

void Funcion::SetIdSala(int idSala)
{
    _idSala = idSala;
}


void Funcion::SetActiva(bool activa)
{
    _activa = activa;
}

void Funcion::SetCantidadAsientos(int cant)
{
    _cantidad= cant;
}


void Funcion::SetFecha(Fecha fecha){
        _fecha = fecha;

}



int* Funcion::GetAsientosDisponibles() {
    return _asientosDisponibles;
}


void Funcion::crearAsientosDisponibles(int capacidadSala)
{
    delete[] _asientosDisponibles;

    _cantidad = capacidadSala;
    _asientosDisponibles = new int[_cantidad]{};

     if( _asientosDisponibles== nullptr){

            cout<<"no se pudo asignar memoria";

        }

    for (int i = 0; i < _cantidad; i++)
    {
        _asientosDisponibles[i] = 0;
    }
}



