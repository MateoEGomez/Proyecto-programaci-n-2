#pragma once
#include "Pelicula.h"
#include "Sala.h"
#include "Fecha.h"

class Funcion {

public:
Funcion ();
Funcion(int idFuncion, int idPelicula, int idSala, bool activa);
~Funcion();

void crearAsientosDisponibles(int capacidadSala);

//Getters
    int GetIdFuncion();
    int GetIdPelicula();
    int GetIdSala();
    bool GetActiva();
    int GetcantidadAsientos();
    int* GetAsientosDisponibles();

    Fecha GetFecha();

// Setters
    void SetIdFuncion(int funcion);
    void SetIdPelicula(int peli);
    void SetIdSala(int sala);
    void SetActiva(bool val);

    void SetCantidadAsientos(int cant);
    void SetAsientosDisponibles(int* asientos);
    void SetFecha(Fecha);


private:
    int _idFuncion;
    int _idSala;
    int _idPelicula;
    int _cantidad;
    Fecha _fecha;
    bool _activa;

   int* _asientosDisponibles;




};
