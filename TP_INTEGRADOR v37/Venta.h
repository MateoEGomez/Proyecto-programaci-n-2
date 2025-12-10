#pragma once
#include "Pelicula.h"
#include "Sala.h"
#include "Funcion.h"
#include "Cliente.h"
#include "Fecha.h"

class Venta {
public:
    Venta();
    virtual ~Venta();

    int GetIdVenta() ;
    int GetIdCliente();
    int GetIdFuncion();
    int GetCantidadEntradas();
    float GetPrecio() ;
    int* GetNumeroAsiento();
    int GetIdEmpleado();
    Fecha Getfecha();

    void SetIdVenta(int idventa);
    void SetIdCliente(int idCliente);
    void SetIdFuncion(int idFuncion);
    void SetCantidadEntradas(int cantidadEntradas);
    void SetPrecio(float precio);
    void SetIdEmpleado(int idEmple);

    void SetNumeroAsiento(int numeroAsiento);

    void Setfecha(Fecha);





private:
    int _idventa;
    int _idCliente;
    int _idFuncion;
    int _cantidadEntradas;
    int _idEmpleado;

    int* _numeroAsiento;

    float _precio;
    Fecha _fecha ;
};
