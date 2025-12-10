
#include <iostream>
#include "Venta.h"
#include "rlutil.h"
#include "Pelicula.h"
#include "Sala.h"
using namespace std;

Venta::Venta() {
    _idventa=0;
    _idCliente=0;
    _idFuncion=0;
    _cantidadEntradas=0;
    _precio=1500;

    _numeroAsiento=nullptr;


}


Venta::~Venta() {

  delete[] _numeroAsiento;

}


void Venta::SetIdVenta(int idVenta) {
    _idventa = idVenta;
}

int Venta::GetIdVenta(){
    return _idventa;
}


void Venta::SetIdCliente(int idCliente){
    _idCliente = idCliente;
}
int Venta::GetIdCliente(){
    return _idCliente;
}


int Venta::GetIdFuncion(){
    return _idFuncion;
}
void Venta::SetIdFuncion(int idfuncion) {
        _idFuncion = idfuncion;
}


void Venta::SetCantidadEntradas(int cantidadEntradas) {
    _cantidadEntradas = cantidadEntradas;
}

int Venta::GetCantidadEntradas() {
    return _cantidadEntradas;
}

float Venta::GetPrecio(){
    return _precio;
}

void Venta::SetPrecio(float precio){
    _precio = precio;
}





 void Venta::SetNumeroAsiento(int cantidadEntradas){
    // liberar memoria anterior (si existe)
    delete[] _numeroAsiento;
    _numeroAsiento = nullptr;

    // caso sin asientos

    if (cantidadEntradas <= 0) {
    _numeroAsiento = nullptr;
    return;
    }


    // reservar nuevo array e inicializar a 0
    _numeroAsiento = new int[cantidadEntradas]{};
    if (_numeroAsiento == nullptr) {

        cout << "no se pudo asignar memoria";
        _cantidadEntradas = 0;
        return;
    }

    // actualizar el tamaño interno: esto es CRUCIAL
    _cantidadEntradas = cantidadEntradas;
}


int* Venta::GetNumeroAsiento(){
    return _numeroAsiento;
}


 int Venta::GetIdEmpleado(){
    return _idEmpleado;
 }

 void Venta::SetIdEmpleado(int idEmple){

        _idEmpleado = idEmple;

 }

 void Venta::Setfecha(Fecha fe){
    _fecha = fe;
 }

 Fecha Venta::Getfecha(){
    return _fecha;
 }




