#include <iostream>
#include "ServicioEmpleado.h"
#include "Empleado.h"


using namespace std;

ServicioEmpleado::ServicioEmpleado(){
}

///crear/guardar cliente
bool ServicioEmpleado::guardarEmpleado(Empleado emp1)
{
    FILE* archivoEmpleado = fopen ("Empleado.dat", "ab");
    if(archivoEmpleado != nullptr)
    {
        fwrite(&emp1, sizeof(Empleado),1,archivoEmpleado);
        fclose (archivoEmpleado);
        return true;
    }
    else
    {
        return false;
    }

}

/// contador de registros empleado.dat
int ServicioEmpleado::contadorEmpleados()
{

    FILE* archivoEmpleado = fopen ("Empleado.dat", "rb");

    if(archivoEmpleado != nullptr)
    {
        fseek(archivoEmpleado,0,SEEK_END);
        int cantidadDeRegistros = ftell(archivoEmpleado)/ sizeof(Empleado);
        fclose(archivoEmpleado);
        return cantidadDeRegistros;
    }
    else
    {
        return 0;
    }
}


/// buscar / leer por posicion

Empleado ServicioEmpleado::buscarPosicionEmpleado(int posicion)
{

    FILE* archivoEmpleado = fopen ("Empleado.dat", "rb");

    if(archivoEmpleado == nullptr)
    {
        return Empleado();
    }

    Empleado emp1;

    fseek(archivoEmpleado, sizeof(emp1)* posicion, SEEK_SET),
          fread(&emp1, sizeof(Empleado),1, archivoEmpleado);
    fclose(archivoEmpleado);
    return emp1;

}


/// modificar empleado
bool  ServicioEmpleado::modificarEmpleado(Empleado emp1, int posicion)
{

    FILE* archivoEmpleado = fopen ("Empleado.dat", "rb+");

    if(archivoEmpleado == nullptr)
    {
        return false;
    }

    fseek(archivoEmpleado, sizeof(Empleado)* posicion, SEEK_SET);
    bool ok = (fwrite(&emp1, sizeof(Empleado), 1, archivoEmpleado)==1);
    fclose(archivoEmpleado);
    return ok;
}


// baja logica empleado
bool ServicioEmpleado:: bajaEmpleado(int id)
{

    Empleado emp1;

    int cantRegistros = contadorEmpleados();
    int posi=-1;

    /// se comprueba que hayan registros cargados
     if ( cantRegistros == 0){
        cout<<"no se encontraron registros"<< endl;
        return false;
     }

    for(int i=0; i< cantRegistros; i++)
    {
        emp1= buscarPosicionEmpleado(i);

        if(emp1.getidPersona() == id)
        {
            posi= i;
            // comprobar si cierra el for
            break;
        }

    }

    if (posi == -1) {
    cout << "Empleado no encontrado." << endl;
    return false;
    }

    emp1.setactivo(false);

    if (modificarEmpleado(emp1, posi))
    {

        return true;

    }

    return false;

}


bool ServicioEmpleado:: listarEmpleados(int activ){

    int cantRegistros= contadorEmpleados();
    int cont=0;

    if ( cantRegistros == 0){

         cout<< "no hay registros cargados"<< endl;

         return false;
     }

      Empleado emp1;

      cout<<endl;

    for (int i=0; i < cantRegistros; i++){

           emp1= buscarPosicionEmpleado(i);

           if(emp1.getactivo()== activ){
           cont++;

           cout<<" id: "<< emp1.getidPersona()<< endl;
           cout<<" nombre: "<< emp1.getnombre()<< endl;
           cout<<" apellido: "<< emp1.getapellido()<< endl;
           cout<<" dni: "<< emp1.getdniPersona()<< endl;
           cout<<" estado: "<< emp1.getactivo()<< endl;
           cout<<" es empleado : "<< emp1.getEsEmpleado()<< endl;

           cout<<" numero de legajo: " << emp1.get_numeroLegajo()<<endl;
           cout<<" es administrador: " << emp1.get_admin()<< endl;

           cout<<"---------------------"<< endl;

           }
    }


                if(cont<1){

                    cout<<endl<<endl<<endl;
                    cout<< "no hay registros activos para mostrar!!!"<< endl;

                }

    return true;

}


Empleado ServicioEmpleado::buscarEmpleadoPorId(int id){


    Empleado emple;

    int cantRegistros= contadorEmpleados();
    int posi=-1;


     if ( cantRegistros == 0){
        cout<<"no se encontraron registros"<< endl;
        return Empleado();
     }

    for(int i=0; i< cantRegistros; i++)
    {

        emple= buscarPosicionEmpleado(i);

        if(emple.getidPersona() == id)
        {
            posi= i;

            break;
        }

    }

    if (posi == -1) {
    return Empleado();
    }


    return buscarPosicionEmpleado(posi);

}



bool ServicioEmpleado:: reactivarEmpleado(int id){

    Empleado emple;

    int cantRegistros = contadorEmpleados();
    int posi=-1;

    if(cantRegistros ==0){
       cout<<"no se encontraron registros"<< endl;
        return false;
    }

     for(int i=0; i< cantRegistros; i++)
    {
        emple= buscarPosicionEmpleado(i);

        if(emple.getidPersona() == id)
        {
            posi= i;
            break;
        }

    }

     if (posi == -1) {
    cout << "Empleado  no encontrado." << endl;
    return false;
    }

    emple.setactivo(true);

    if (modificarEmpleado(emple, posi))
    {
        return true;
    }

    return false;


}




