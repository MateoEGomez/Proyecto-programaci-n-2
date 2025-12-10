
#include <iostream>
#include <cstring>
#include "ServicioPelicula.h"
#include "rlutil.h"
#include "Pelicula.h"

using namespace std;

servicioPelicula::servicioPelicula(){

}


///crear/guardar
bool servicioPelicula::guardarPelicula(Pelicula peli){
    FILE* archivoPelicula = fopen ("Peliculas.dat", "ab");
    if(archivoPelicula != nullptr)
    {
        fwrite(&peli, sizeof(Pelicula),1,archivoPelicula);
        fclose (archivoPelicula);
        return true;
    }
    else
    {
        return false;
    }

}


/// contador de registros
int servicioPelicula::contadorPeliculas(){

    FILE* archivoPelicula  = fopen ("Peliculas.dat", "rb");

    if(archivoPelicula != nullptr)
    {
        fseek(archivoPelicula,0,SEEK_END);
        int cantidadDeRegistros = ftell(archivoPelicula)/ sizeof(Pelicula);
        fclose(archivoPelicula);
        return cantidadDeRegistros;
    }
    else
    {
        return 0;
    }
}


/// buscar por posicion leer

Pelicula servicioPelicula:: buscarPosicionPelicula(int posicion){

    FILE* archivoPelicula = fopen ("Peliculas.dat", "rb");

    if(archivoPelicula == nullptr)
    {
        return Pelicula();
    }

    Pelicula peli;

    fseek(archivoPelicula, sizeof(peli)* posicion, SEEK_SET),
    fread(&peli, sizeof(Pelicula),1, archivoPelicula);

    fclose(archivoPelicula);
    return peli;

}

/// modificar pelicula
bool  servicioPelicula:: modificarPelicula(Pelicula peli, int posicion){

    FILE* archivoPelicula = fopen ("Peliculas.dat", "rb+");

    if(archivoPelicula == nullptr)
    {
        return false;
    }

    fseek(archivoPelicula, sizeof(Pelicula)* posicion, SEEK_SET);
    bool ok = (fwrite(&peli, sizeof(Pelicula), 1, archivoPelicula)==1);
    fclose(archivoPelicula);
    return ok;
}

 // baja logica pelicula
bool servicioPelicula:: bajaPelicula(int id){

    Pelicula peli;

    int cantRegistros= contadorPeliculas();
    int posi;

    /// se comprueba que hayan registros cargados
     if ( cantRegistros == 0){
        cout<<"no se encontraron registros"<< endl;
        return false;
     }

    for(int i=0; i< cantRegistros; i++)
    {

        peli = buscarPosicionPelicula(i);

        if(peli.GetIdPelicula() == id)
        {
            posi= i;
            // comprobar si cierra el for
            break;
        }

    }

    peli.SetActivo(false);

    if (modificarPelicula(peli, posi))
    {

        return true;

    }

    return false;

}


bool servicioPelicula:: listarPelicula(int activo){

    int cantRegistros= contadorPeliculas();
    int cont=0;

    if ( cantRegistros == 0){
        cout<<"no se encontraron registros"<< endl;
        return false;
     }

    Pelicula peli;
     cout<<endl;

    for (int i=0; i < cantRegistros; i++){

           peli= buscarPosicionPelicula(i);

           if(peli.GetActivo()== activo){

            cont++;

           cout<<" id: "<< peli.GetIdPelicula()<< endl;
           cout<<" nombre: "<< peli.GetNombrePelicula()<< endl;
           cout<<" director: "<< peli.GetDirector()<< endl;
           cout<<" clasificacion: "<< peli.GetClasificacion()<< endl;
           cout<<" estado: "<<(peli.GetActivo()?"Activo": "Inactivo")<< endl;
           cout<<" genero:  "<< peli.GetGenero()<<endl;
           cout<<"---------------------"<< endl;
        }


        }

            if(cont<1){

                cout<<endl<<endl<<endl;
                cout<< "no hay registros activos para mostrar!!!"<< endl;
                return false;
            }

          return true;


}



Pelicula servicioPelicula::BuscarPeliculaPorId(int id){


    Pelicula peli;

    int cantRegistros= contadorPeliculas();
    int posi=-1;


     if ( cantRegistros == 0){
        cout<<"no se encontraron registros"<< endl;
        return Pelicula();
     }

    for(int i=0; i< cantRegistros; i++)
    {

        peli= buscarPosicionPelicula(i);

        if(peli.GetIdPelicula() == id)
        {
            posi= i;

            break;
        }

    }

    if (posi == -1) {
    return Pelicula();
    }

    return buscarPosicionPelicula(posi);

}



bool servicioPelicula::reactivarPelicula(int id){

    Pelicula peli;

    int cantRegistros= contadorPeliculas();
    int posi=-1;

    /// se comprueba que hayan registros cargados
     if ( cantRegistros == 0){
        cout<<"no se encontraron registros"<< endl;
        return false;
     }

    for(int i=0; i< cantRegistros; i++)
    {
        peli= buscarPosicionPelicula(i);

        if(peli.GetIdPelicula() == id)
        {
            posi= i;

            break;
        }

    }

    if (posi == -1) {
    cout << "Pelicula no encontrado." << endl;
    return false;
    }

    peli.SetActivo(true);



    return modificarPelicula(peli, posi);

}



