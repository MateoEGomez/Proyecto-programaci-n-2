#pragma once
#include "Pelicula.h"
#include "Venta.h"
#include "Sala.h"
#include "Funcion.h"
#include "Cliente.h"
class ServicioVenta{
public:

    bool crearVenta(Venta v);
    int contadorVentas();
    Venta buscarPosicionVenta(int pos);
    bool listarVentas();
    Venta buscarVentaPorId(int idVenta);

 bool asignarAsientos(Funcion funcion, Venta venta);

    float CalcularPrecioTotal(const Sala& sala) const;

};
