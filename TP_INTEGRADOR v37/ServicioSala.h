#pragma once
#include <string>
#include "Sala.h"

class ServicioSala{

public:
    ServicioSala();

    bool crearSala(Sala s);

    int contadorSalas ();

    bool modificarSala(Sala s , int pos);

    bool listarSalas (int activo);

    Sala buscarPosicionSala (int pos);

    Sala* leerSala(FILE* archivo);

    Sala buscarSala(int idsala);


    bool eliminarSala(int id);




};

