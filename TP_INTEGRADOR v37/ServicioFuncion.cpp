
#include <iostream>
#include "ServicioFuncion.h"
#include <cstdio>


using namespace std;


bool ServicioFuncion::crearFuncion(Funcion fun) {

    FILE* archivo = fopen("Funcion.dat", "ab");
    if (archivo == nullptr) return false;

    // 1) Guardar parte fija SIN el puntero dinámico

    fwrite(&fun, sizeof(Funcion) - sizeof(int*), 1, archivo);

    // 2) Guardar array dinámico _asientosDisponibles
    int cant = fun.GetcantidadAsientos();
    int* vec = fun.GetAsientosDisponibles();

    fwrite(vec, sizeof(int), cant, archivo);

    fclose(archivo);
    return true;
}


int ServicioFuncion::contarFuncion()
{
    FILE* archivo = fopen("Funcion.dat", "rb");
    if (archivo == nullptr) return 0;

    Funcion fun;
    int cont = 0;

    while ( fread(&fun, sizeof(Funcion) - sizeof(int*), 1, archivo) == 1 )
    {
        cont++;

        int cant = fun.GetcantidadAsientos();
        fseek(archivo, sizeof(int) * cant, SEEK_CUR);   // salto el vector de asientos
    }

    fclose(archivo);
    return cont;
}


Funcion ServicioFuncion::buscarPosicionFuncion(int pos)
{
    Funcion fun;

    FILE* archivo = fopen("Funcion.dat", "rb");
    if (archivo == nullptr) return fun;

    // Mover hasta el registro pos
    for(int i = 0; i <= pos; i++)
    {
        fread(&fun, sizeof(Funcion) - sizeof(int*), 1, archivo);

        int cant = fun.GetcantidadAsientos();
        fseek(archivo, sizeof(int) * cant, SEEK_CUR);
    }

    fclose(archivo);
    return fun;
}





bool ServicioFuncion::listarFunciones(int activo)
{
    int cantFunciones = contarFuncion();
    int cont = 0;

    if (cantFunciones == 0) {
        cout << "No se encontraron registros" << endl;
        return false;
    }

    Funcion fun;

    for (int i = 0; i < cantFunciones; i++)
    {
        fun = buscarPosicionFuncion(i);

        if (fun.GetActiva() == activo)
        {
            cont++;

            cout << "---------------------------" << endl;
            cout << "ID Funcion: "   << fun.GetIdFuncion()   << endl;
            cout << "ID Pelicula: "  << fun.GetIdPelicula()  << endl;
            cout << "ID Sala: "      << fun.GetIdSala()      << endl;

            cout << "Fecha: ";
            fun.GetFecha().mostrarFecha();
            cout << endl;

            cout << "Cantidad de asientos: " << fun.GetcantidadAsientos() << endl;
            cout << "Estado: " << (fun.GetActiva() ? "Activo" : "Inactivo") << endl;


            int* asientos = fun.GetAsientosDisponibles();
            int libres = 0;

            if (asientos == nullptr) {

                fun.crearAsientosDisponibles(fun.GetcantidadAsientos());
                asientos = fun.GetAsientosDisponibles();
            }

            for (int h = 0; h < fun.GetcantidadAsientos(); h++) {
                if (asientos[h] == 0) libres++;
            }

            cout << "Asientos disponibles: " << libres << endl;

            cout << "[PANTALLA]" << endl << endl;
            int aux=0;
            for (int j = 0; j < fun.GetcantidadAsientos(); j++) {

                cout << "[" << asientos[j] << "] ";
                aux++;
                if(aux==10){
                     cout<<endl;
                     aux=0;
                }

            }
            cout << endl;


            cout << "---------------------------" << endl;
        }
    }

    if (cont < 1)
    {
        cout << endl << endl;
        cout << "No hay registros activos para mostrar!!!" << endl;
    }

    return true;
}

