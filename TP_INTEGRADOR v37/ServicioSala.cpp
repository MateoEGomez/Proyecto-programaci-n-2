#include <iostream>
#include <string>
#include "rlutil.h"
#include "ServicioSala.h"
using namespace std;

ServicioSala :: ServicioSala ()
{

}

bool ServicioSala::crearSala(Sala sala) {

    FILE* pSala = fopen("Salas.dat", "ab");
    if (pSala == nullptr) return false;

    sala.SetIdSala(contadorSalas() + 1);
    sala.SetActivo(true);

    fwrite(&sala, sizeof(Sala), 1, pSala);
    fclose(pSala);
    return true;
}

int ServicioSala::contadorSalas() {

    FILE* pSala = fopen("Salas.dat", "rb");
    if (pSala == nullptr) return 0;

    fseek(pSala, 0, SEEK_END);
    int bytes = ftell(pSala);
    fclose(pSala);

    return bytes / sizeof(Sala);
}



bool ServicioSala::listarSalas(int activo) {

    int cantSalas= contadorSalas();
    int cont=0;


   if (cantSalas == 0) {
        cout << "No se encontraron registros" << endl;
        return false;
    }

    Sala sala;
    cout<<endl;

     for(int i=0; i<cantSalas;i++){

        sala = buscarPosicionSala(i);


        if (sala.GetActivo()== activo) {
                cont++;

            cout << "---------------------------" << endl;
            cout << "ID Sala: " << sala.GetIdSala() << endl;
            cout << "Nombre: " << sala.GetNombreSala() << endl;
            cout << "Tipo: " << sala.GetTipoSala() << endl;
            cout << "Capacidad: " << sala.GetCapacidadSala()<< " asientos " << endl;
            cout << "---------------------------" << endl;
        }

     }


    if(cont<1){
     cout<<endl<<endl<<endl;
     cout<< "no hay registros activos para mostrar!!!"<< endl;

    }
     return true;
}





Sala ServicioSala::buscarPosicionSala(int pos)
{
    FILE* archivoSalas = fopen("Salas.dat", "rb");

    if (archivoSalas == nullptr){
       return Sala();

    }

    Sala sala;

    fseek(archivoSalas, sizeof(Sala) * pos , SEEK_SET);
    fread(&sala, sizeof(Sala), 1, archivoSalas);

    fclose(archivoSalas);
    return sala;
}




Sala ServicioSala::buscarSala(int idsala){

    Sala sala;
    int cantregistros= contadorSalas();
    int posi=-1;

    if(cantregistros==0){
           cout<<"no se encontraron registros"<< endl;
           return Sala();
       }

     for(int i=0; i<cantregistros;i++){

        sala= buscarPosicionSala(i);
        if(sala.GetIdSala()== idsala ){
                 posi=i;
                 break;
        }


     }

     if (posi ==-1){

        return Sala();
     }
    return buscarPosicionSala(posi);

}



bool ServicioSala::modificarSala(Sala s , int pos){

FILE* archivoSala = fopen ("Salas.dat", "rb+");

    if(archivoSala == nullptr)
    {
        return false;
    }

    fseek(archivoSala, sizeof(Sala)* pos, SEEK_SET);
    bool ok = (fwrite(&s, sizeof(Sala), 1, archivoSala)==1);
    fclose(archivoSala);
    return ok;

}




 bool ServicioSala::eliminarSala(int id){

    Sala objetoSala;

    int cantRegistros= contadorSalas();
    int posi;

    /// se comprueba que hayan registros cargados
     if ( cantRegistros == 0){
        cout<<"no se encontraron registros"<< endl;
        return false;
     }

    for(int i=0; i< cantRegistros; i++)
    {

        objetoSala = buscarPosicionSala(i);

        if(objetoSala.GetIdSala() == id)
        {
            posi= i;
            // comprobar si cierra el for
            break;
        }

    }

    objetoSala.SetActivo(false);

    if (modificarSala(objetoSala, posi))
    {

        return true;

    }

    return false;

}



