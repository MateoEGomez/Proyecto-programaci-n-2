#include <iostream>
#include <cstring>
#include "Persona.h"
using namespace std;

Persona:: Persona(){

}

void Persona::setidPersona(int idPersona)
{
    _idPersona=idPersona;
}

int Persona::getidPersona()
{
    return _idPersona;
}

void Persona::setdniPersona(int dniPersona)
{
    _dni=dniPersona;
}

int Persona::getdniPersona()
{
    return _dni;
}
void Persona::setnombre(const char *nombre)
{
    strcpy(_nombre,nombre);
    _nombre[49]='\0';

}
const char* Persona::getnombre()
{
    return _nombre;
}

void Persona::setapellido(const char *apellido)
{
    strcpy(_apellido,apellido);
    _nombre[49]='\0';
}
const char* Persona::getapellido()
{
    return _apellido;
}

void Persona::setactivo(bool activo)
{
    _activo=activo;
}
bool Persona::getactivo()
{
    return _activo;
}

void Persona::setEsEmpleado(bool esEmple){

   _esEmpleado = esEmple;
}

bool Persona::getEsEmpleado(){

    return _esEmpleado;
}





void Persona::cargarPersona()
{
    cout<<"Ingrese nombre: "<<endl;
    cin>>_nombre;
    cout <<"Ingrese apellido: "<<endl;
    cin >> _apellido;
    cout << "Ingrese DNI: "<<endl; //hacer validacion con set
    cin >> _dni;

}
void Persona::mostrarPersona()
{
    cout<<"NOMBRE: "<<_nombre<<endl;
    cout<<"APELLIDO: "<<_apellido<<endl;
    cout<<"DNI: "<<_dni<<endl;

}
