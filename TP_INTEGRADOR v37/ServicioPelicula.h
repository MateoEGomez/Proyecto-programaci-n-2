#pragma once
#include <string>
#include "Pelicula.h"

class servicioPelicula{

public:

    servicioPelicula();

    bool guardarPelicula(Pelicula Peli);

    int contadorPeliculas();

    Pelicula buscarPosicionPelicula(int posicion);

    bool modificarPelicula(Pelicula Peli, int pos);

    bool bajaPelicula(int id);

    bool listarPelicula();

    Pelicula BuscarPeliculaPorId(int id);

    ///int elimin

    bool listarPelicula(int activo);

    bool reactivarPelicula(int id);


};
