#include <iostream>
#include "Pantallas.h"
#include "rlutil.h"
#include <limits>
#include "Cliente.h"
#include "Empleado.h"
#include "MisFunciones.h"
#include "ServicioCliente.h"
#include "ServicioEmpleado.h"
#include "ServicioPelicula.h"
#include "Pelicula.h"
#include "Sala.h"
#include "ServicioSala.h"
#include "cstring"
#include "ServicioVenta.h"
#include "ServicioFuncion.h"

using namespace std;

Pantallas:: Pantallas()
{

}



void Pantallas::avisoError()
{
    rlutil::locate(5,26);
    cout<<"Eleccion incorrecta intente nuevamente!!!! "<<endl;

    rlutil::msleep(1000);
    rlutil::locate(5,26);
    cout<<"                                               "<<endl;

}



void Pantallas::marcoPantalla(int x, int y)
{
    rlutil::cls();
    int ancho=x;
    int alto=y;
    rlutil::setColor(4);
///esquina sup izq
    rlutil::locate(3,4);
    cout<<(char)201<<endl;

///lateral izq
    for(int i=0; i<alto; i++)
    {
        rlutil::locate(3,5+i);
        cout<<(char)186<<endl;

    }
///esquina inf izq

    rlutil::locate(3,alto+5);
    cout<<(char)200<<endl;



/// lineas superior inferior
    for(int i=0; i<ancho; i++)
    {

        rlutil::locate(4+i,4);
        cout<<(char)205<<endl;

        rlutil::locate(4+i,alto+5);
        cout<<(char)205<<endl;
        rlutil::msleep(4) ;

    }

    /// esquina inf derecha
    rlutil::locate(ancho+4,alto +5);
    cout<<(char)188<<endl;
    /// esquiina sup derecha
    rlutil::locate(ancho+4,4);
    cout<<(char)187<<endl;


    for(int i=0; i<alto; i++)
    {
        rlutil::locate(ancho+4,5+i);
        cout<<(char)186<<endl;
    }

}



/*
void limpiarBuffer()
{
    cin.clear() ;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

}

  */



int Pantallas::menuPrincipal()
{
    int aux;
    rlutil:: cls();
    marcoPantalla(60,20) ;

    ///contenido
    rlutil::setColor(4);
    rlutil::locate(30,8);
    cout<<"MENU PRINCIPAL "<<endl;
    rlutil::setColor(15);
    rlutil::locate(15,12);
    cout<<"1- Ventas "<<endl;
    rlutil::locate(15,14);
    cout<<"2- Administracion "<<endl;
    rlutil::locate(15,16);
    cout<<"3- Informes "<<endl;
    rlutil::locate(15,18);
    cout<<"0- Salir "<<endl;

    rlutil::locate(5,26);
    cout <<"Eleccion: ";
    cin>>aux;

    return aux;

}




/// menu principal

int Pantallas::menuVentas()
{
    int aux;

    rlutil:: cls();

    marcoPantalla(60,20);

    ///contenido
    rlutil::setColor(4);
    rlutil::locate(30,8);
    cout<<"MENU VENTAS "<<endl;

    rlutil::setColor(15);
    rlutil::locate(15,12);
    cout<<"1- Ventas de entradas "<<endl;
    rlutil::locate(15,14);
    cout<<"2- Salas "<<endl;
    rlutil::locate(15,16);
    cout<<"3- Ticket para el cliente  "<<endl;

    rlutil::locate(15,18);
    cout<<"0- Salir "<<endl;

    rlutil::locate(5,26);
    cout <<"Eleccion: ";
    cin>> aux;

    return aux;

}



int Pantallas::menuAdmin()
{
    int aux;
    rlutil:: cls();

    marcoPantalla(60,20);
    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"MENU ADMINISTRACION "<<endl;
    rlutil::setColor(15);
    rlutil::locate(15,12);
    cout<<"1- Administrar cliente  "<<endl;
    rlutil::locate(15,14);
    cout<<"2- Administrar empleado  "<<endl;
    rlutil::locate(15,16);
    cout<<"3- Administrar pelicula  "<<endl;
    rlutil::locate(15,18);
    cout<<"4- Administrar Sala "<<endl;
    rlutil::locate(15,20);
    cout<<"5- Administrar funciones"<<endl;
    rlutil::locate(15,22);
    cout<<"0- Salir "<<endl;

    rlutil::locate(5,26);
    cout <<"Eleccion: ";
    cin>> aux;

    return aux;
}



int Pantallas::menuInformes()
{
    int aux;
    rlutil:: cls();

    marcoPantalla(60,20);
    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"MENU INFORMES "<<endl;
    rlutil::setColor(15);
    rlutil::locate(15,12);
    cout<<"1- RECAUDACION MENSUAL "<<endl;
    rlutil::locate(15,14);
    cout<<"2- RECAUDACION ANUAL "<<endl;
    rlutil::locate(15,16);
    cout<<"3- RECAUDACION POR SALA "<<endl;
    rlutil::locate(15,18);
    cout<<"4- RECAUDACION PELICULA "<<endl;
    rlutil::locate(15,20);
    cout<<"0- Salir "<<endl;

    rlutil::locate(5,26);
    cout <<"Eleccion: ";
    cin>> aux;

    return aux;

}



/// sub menu


int Pantallas::menuAdministrarCliente()
{
    int aux;
    rlutil:: cls();

    marcoPantalla(60,20);
    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"MENU CLIENTE "<<endl;
    rlutil::setColor(15);
    rlutil::locate(15,10);
    cout<<"1- Agregar cliente nuevo  "<<endl;
    rlutil::locate(15,12);
    cout<<"2- Listar clientes  "<<endl;

    rlutil::locate(15,14);
    cout<<"3- Modificar cliente "<<endl;

    rlutil::locate(15,16);
    cout<<"4- Buscar cliente "<<endl;

    rlutil::locate(15,18);
    cout<<"5- Eliminar cliente "<<endl;

    rlutil::locate(15, 20);
    cout<<"6- reactivar cliente"<< endl;

    rlutil::locate(15,22);
    cout<<"0- Salir "<<endl;

    rlutil::locate(5,26);
    cout <<"Eleccion: ";
    cin>> aux;

    return aux;

}


int Pantallas::menuAdministrarEmpleado()
{
    int aux;
    rlutil:: cls();

    marcoPantalla(60,20);
    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"MENU EMPLEADO "<<endl;
    rlutil::setColor(15);
    rlutil::locate(15,10);
    cout<<"1- Agregar empleado nuevo  "<<endl;
    rlutil::locate(15,12);
    cout<<"2- Listar empleado  "<<endl;

    rlutil::locate(15,14);
    cout<<"3- Modificar empleado "<<endl;

    rlutil::locate(15,16);
    cout<<"4- Buscar empleados "<<endl;

    rlutil::locate(15,18);
    cout<<"5- Eliminar empleado "<<endl;

    rlutil::locate(15, 20);
    cout<<"6- reactivar empleado "<<endl;

    rlutil::locate(15,22);
    cout<<"0- Salir "<<endl;

    rlutil::locate(5,26);
    cout <<"Eleccion: ";
    cin>> aux;

    return aux;

}


int Pantallas::menuAdministrarSala()
{
    int aux;
    rlutil::cls();

    marcoPantalla(60,20);
    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"MENU SALA "<<endl;

    rlutil::setColor(15);
    rlutil::locate(15,10);
    cout<<"1- Agregar sala nueva"<<endl;

    rlutil::locate(15,12);
    cout<<"2- Listar salas"<<endl;

    rlutil::locate(15,14);
    cout<<"3- Modificar sala"<<endl;

    rlutil::locate(15,16);
    cout<<"4- Buscar sala"<<endl;

    rlutil::locate(15,18);
    cout<<"5- Eliminar sala"<<endl;

    rlutil::locate(15,20);
    cout<<"6- Reactivar sala"<<endl;

    rlutil::locate(15,22);
    cout<<"0- Salir"<<endl;

    rlutil::locate(5,26);
    cout <<"Eleccion: ";
    cin >> aux;

    return aux;
}



/// 2do sub-sub menu

///cliente empleado

Cliente  Pantallas::pAgregarCliente()
{

    limpiarBuffer();
    Cliente cli;


    int dni;
    char nombre[50], apellido[50], email[50];


    marcoPantalla(60,20);

    rlutil::setColor(4);
    rlutil::locate(30,8);
    cout<<"Crear Cliente "<<endl;

    rlutil::setColor(15);
    rlutil::locate(15,12);
    cout <<"Apellido: ";
    rlutil::locate(26,12);
    cin >> apellido;
    cli.setapellido(apellido) ;

    rlutil::locate(15,14);
    cout<<"Nombre: ";
    rlutil::locate(26,14);
    cin>> nombre;
    cli.setnombre(nombre);

    rlutil::locate(15,16);
    cout <<"DNI: ";
    rlutil::locate(26,16);
    cin >>dni;
    cli.setdniPersona(dni);

    rlutil::locate(15,18);
    cout <<"Email: ";
    rlutil::locate(26,18);
    cin >>email;
    cli.set_email(email);

    cli.setactivo(true);
    cli.setEsEmpleado(false);
    cli.setidPersona(generacionId(1));

    return cli;




}


Empleado  Pantallas::pAgregarEmpleado()
{

    limpiarBuffer();
    Empleado emple;


    int dni, numlegajo;
    char nombre[50], apellido[50];
    bool admin;

    marcoPantalla(60,20);

    rlutil::setColor(4);
    rlutil::locate(30,8);
    cout<<"Crear Empleado "<<endl;

    rlutil::setColor(15);
    rlutil::locate(15,12);
    cout <<"APELLIDO: ";
    rlutil::locate(26,12);
    cin >> apellido;
    emple.setapellido(apellido) ;

    rlutil::locate(15,14);
    cout<<"NOMBRE: ";
    rlutil::locate(26,14);
    cin>> nombre;
    emple.setnombre(nombre);

    rlutil::locate(15,16);
    cout <<"DNI: ";
    rlutil::locate(26,16);
    cin >>dni;
    emple.setdniPersona(dni);

    rlutil::locate(15,18);
    cout <<"LEGAJO: ";
    rlutil::locate(26,18);
    cin >>numlegajo;
    emple.set_numeroLegajo(numlegajo);

    rlutil::locate(15,20);
    cout <<"ES ADMIN: ";
    rlutil::locate(26,20);
    cin >>admin;
    emple.set_admin(admin);


    emple.setactivo(true);

    emple.setEsEmpleado(true);

    emple.setidPersona(generacionId(2));



    return emple;

}



Venta Pantallas::pAgregarVenta()
{

    limpiarBuffer();
    Venta v;

    int idVenta, idCliente, idEmpleado, idFuncion, cantEntradas;

    marcoPantalla(60,20);

    rlutil::setColor(4);
    rlutil::locate(30,8);
    cout << "Crear Venta" << endl;

    rlutil::setColor(15);

    rlutil::locate(15,12);
    cout << "ID VENTA: ";
    rlutil::locate(30,12);
    cin >> idVenta;
    v.SetIdVenta(idVenta);

    rlutil::locate(15,14);
    cout << "ID CLIENTE: ";
    rlutil::locate(30,14);
    cin >> idCliente;
    v.SetIdCliente(idCliente);

    rlutil::locate(15,16);
    cout << "ID EMPLEADO: ";
    rlutil::locate(30,16);
    cin >> idEmpleado;
    v.SetIdEmpleado(idEmpleado);

    rlutil::locate(15,18);
    cout << "ID FUNCION: ";
    rlutil::locate(30,18);
    cin >> idFuncion;
    v.SetIdFuncion(idFuncion);

    rlutil::locate(15,20);
    cout << "CANT. ENTRADAS: ";
    rlutil::locate(30,20);
    cin >> cantEntradas;
    v.SetCantidadEntradas(cantEntradas);

    // Reservar array dinámico para los asientos
    v.SetNumeroAsiento(cantEntradas);



    int* asientos = v.GetNumeroAsiento();
    for (int i = 0; i < cantEntradas; i++)
    {

        asientos[i] = i + 1;   // acá después vas a cargar los asientos reales
    }

    Fecha fech;
    fech.fechaActual();
    v.Setfecha(fech);

    return v;
}





void Pantallas::pBuscarClienteId()
{

    int aux;
    ServicioCliente servicli;
    Cliente cli;

    marcoPantalla(60,20);

    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"Buscar Cliente "<<endl;

    rlutil::locate(15,10);
    cout<<"Indique el id: "<<endl;
    rlutil::locate(30,10);
    cin>> aux;

    cli= servicli.buscarClientePorId(aux);

    if(cli.getidPersona()>0)
    {

        rlutil::setColor(15);
        rlutil::locate(15,12);
        cout <<"Apellido: "<<cli.getapellido()<<endl;
        //rlutil::locate(26,12);
        rlutil::msleep(500);

        rlutil::locate(15,14);
        cout<<"Nombre: "<< cli.getnombre()<<endl;
        //rlutil::locate(26,14);
        rlutil::msleep(500);

        rlutil::locate(15,16);
        cout <<"DNI: "<< cli.getdniPersona()<<endl;
        //rlutil::locate(26,16);
        rlutil::msleep(500);

        rlutil::locate(15,18);
        cout <<"Email: "<< cli.get_email()<<endl;
        //rlutil::locate(26,18);
        rlutil::msleep(500);

        rlutil::locate(15,20);
        cout <<"Es Empleado: "<<(cli.getEsEmpleado()? "si" : "no" )<<endl;
        rlutil::msleep(500);

        rlutil::locate(15,22);
        cout <<"Es Activo: "<<(cli.getactivo()? "si" : "no")<<endl;
        rlutil::msleep(500);


        rlutil::locate(5,26);
        cout <<"Precione cualquier tecla para continuar..... ";
        rlutil::anykey();

    }
    else
    {
        rlutil::setColor(15);
        rlutil::locate(15,16);
        cout<<"El id buscado es incorrecto!!"<< endl;
        rlutil::msleep(2000);
    }


}


void Pantallas::pBuscarEmpleadoId()
{

    int aux;
    ServicioEmpleado serviemple;
    Empleado emple;

    marcoPantalla(60,20);

    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"Buscar Empleado "<<endl;

    rlutil::locate(15,10);
    cout<<"Indique el id: "<<endl;
    rlutil::locate(30,10);
    cin>> aux;

    emple= serviemple.buscarEmpleadoPorId(aux);

    if(emple.getidPersona()>0)
    {

        rlutil::setColor(15);
        rlutil::locate(15,12);
        cout <<"Apellido: "<<emple.getapellido()<<endl;
        //rlutil::locate(26,12);
        rlutil::msleep(500);

        rlutil::locate(15,14);
        cout<<"Numero legajo: "<< emple.getnombre()<<endl;
        //rlutil::locate(26,14);
        rlutil::msleep(500);

        rlutil::locate(15,16);
        cout<<"Nombre: "<< emple.getnombre()<<endl;
        //rlutil::locate(26,14);
        rlutil::msleep(500);

        rlutil::locate(15,18);
        cout <<"DNI: "<< emple.getdniPersona()<<endl;
        //rlutil::locate(26,16);
        rlutil::msleep(500);

        rlutil::locate(15,20);
        cout <<"Activo "<< (emple.getactivo()? "si" : "no") <<endl;
        //rlutil::locate(26,18);
        rlutil::msleep(500);

        rlutil::locate(15,22);
        cout <<"Es Empleado: "<<(emple.getEsEmpleado()?"si" : "no" ) <<endl;
        rlutil::msleep(500);

        rlutil::locate(15,24);
        cout <<"Es Administrador: "<<(emple.get_admin()?"si" : "no" ) <<endl;
        rlutil::msleep(500);




        rlutil::locate(5,26);
        cout <<"Precione cualquier tecla para continuar..... ";
        rlutil::anykey();

    }
    else
    {
        rlutil::setColor(15);
        rlutil::locate(15,16);
        cout<<"El id buscado es incorrecto!!"<< endl;
        rlutil::msleep(2000);
    }


}


void Pantallas::pEliminarCliente()
{

    int aux, eleccion;
    ServicioCliente servicli;
    rlutil:: cls();

    marcoPantalla(60,20);
    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"Eliminacion CLIENTE "<<endl;
    rlutil::setColor(15);
    rlutil::locate(15,10);
    cout<<"Indique el id a eliminar: "<<endl;

    rlutil::locate(41,10);
    cin>> aux;


    rlutil::locate(15,18);
    cout<<"1- guardar    0- cancelar"<<endl;


    do
    {
        rlutil::locate(5,26);
        cout <<"Eleccion: ";
        cin>> eleccion;


        if(eleccion== 1)
        {

            servicli.bajaCliente(aux);
            rlutil::locate(25,26);
            cout<<"Eliminacion exitosa ";
            rlutil::msleep(1500);

        }

        else if (eleccion ==0)
        {

            rlutil::locate(25,26);
            cout<<"Eliminacion cancelada "<<endl;
            rlutil::msleep(1500);
            return;
        }
        else
        {
            avisoError();
        }

    }
    while(eleccion <0 || eleccion>1);

}


void Pantallas::pEliminarEmpleado()
{

    int aux, eleccion;
    ServicioEmpleado serviEmple;
    rlutil:: cls();

    marcoPantalla(60,20);
    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"Eliminacion Empleado "<<endl;
    rlutil::setColor(15);
    rlutil::locate(15,10);
    cout<<"Indique el id a eliminar: "<<endl;

    rlutil::locate(41,10);
    cin>> aux;


    rlutil::locate(15,18);
    cout<<"1- guardar    0- cancelar"<<endl;


    do
    {

        rlutil::locate(5,26);
        cout <<"Eleccion: ";
        cin>> eleccion;


        if(eleccion== 1)
        {
            serviEmple.bajaEmpleado(aux);
            rlutil::locate(25,26);
            cout<<"Eliminacion exitosa ";
            rlutil::msleep(1500);

        }
        else if (eleccion ==0)
        {
            rlutil::locate(25,26);
            cout<<"Eliminacion cancelada "<<endl;
            rlutil::msleep(1500);
        }
        else
        {
            avisoError();
        }

    }
    while(eleccion <0 || eleccion>1);


}


bool Pantallas::pModificarCliente()
{
    limpiarBuffer();

    int aux;
    char nombre[50], apellido[50], email[50], dni[12];


    ServicioCliente servicli;
    Cliente cli;

    marcoPantalla(60,20);

    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"Modificar Cliente "<<endl;

    rlutil::locate(10,10);
    cout<<"Indique el id: "<<endl;
    rlutil::locate(25,10);
    cin>> aux;

    cli= servicli.buscarClientePorId(aux);

    if(cli.getidPersona()>0)
    {


        rlutil::setColor(15);
        rlutil::locate(10,12);
        cout <<"Apellido: "<<cli.getapellido()<<endl;
        //rlutil::locate(26,12);
        rlutil::msleep(500);


        rlutil::locate(10,14);
        cout<<"Nombre: "<< cli.getnombre()<<endl;
        //rlutil::locate(26,14);
        rlutil::msleep(500);

        rlutil::locate(10,16);
        cout <<"DNI: "<< cli.getdniPersona()<<endl;
        //rlutil::locate(26,16);
        rlutil::msleep(500);

        rlutil::locate(10,18);
        cout <<"Email: "<< cli.get_email()<<endl;
        //rlutil::locate(26,18);
        rlutil::msleep(500);

        rlutil::locate(10,20);
        cout <<"Es Empleado: "<<(cli.getEsEmpleado()?"si": "no") <<endl;
        rlutil::msleep(500);

        rlutil::locate(10,22);
        cout <<"Es Activo: "<<(cli.getactivo()? "si" : "no")<<endl;
        rlutil::msleep(500);



    }
    else
    {
        rlutil::setColor(15);
        rlutil::locate(15,16);
        cout<<"El id buscado es incorrecto!!"<< endl;
        rlutil::msleep(2000);

    }

    /// modificacion

    limpiarBuffer();

    rlutil::setColor(15);
    rlutil::locate(40,12);
    cout<<"Apellido: ";
    cin.getline(apellido,50);
    if(strlen(apellido)>0)
    {
        cli.setapellido(apellido) ;
    }

    rlutil::locate(40,14);
    cout<<"Nombre: ";
    cin.getline(nombre,50);
    if (strlen(nombre)>0)
    {
        cli.setnombre(nombre);
    }


    rlutil::locate(40,16);
    cout <<"DNI: ";
    cin.getline(dni,12);
    if(strlen(dni)>0)
    {
        cli.setdniPersona(atoi(dni));
    }


    rlutil::locate(40,18);
    cout <<"Email: ";
    cin.getline(email,50);
    if(strlen(email)>0)
    {
        cli.set_email(email);
    }


    rlutil::locate(40,20);
    cout <<"item no editable" <<endl;

    rlutil::locate(15,22);
    cout <<"item no editable" <<endl;


    rlutil::anykey();


    do
    {

        rlutil::locate(5,26);
        cout<<" 1-Guardar  0-Cancelar: ";

        rlutil::locate(30,26);
        cin>> aux;

        if(aux==1)
        {

            return servicli.modificarCliente(cli, cli.getidPersona()-1);
        }
        else if(aux==0)
        {
            return false;
        }
        else
        {

            rlutil::locate(35,26);
            cout<<"eleccion incorrecta!!!!";
            rlutil::msleep(1500);
            rlutil::locate(30,26);
            cout<<"                                       ";

        }

    }
    while(aux<0 || aux>1);
}


bool Pantallas::PModificarEmpleado()
{

    limpiarBuffer();

    int aux, nLegajo;
    char nombre[50], apellido[50], edad[4], dni[12],admin[4];



    ServicioEmpleado serviEmple;
    Empleado emple;

    marcoPantalla(60,20);

    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"Modificar Empleado "<<endl;

    rlutil::locate(10,10);
    cout<<"Indique el id: "<<endl;
    rlutil::locate(25,10);
    cin>> aux;

    emple= serviEmple.buscarEmpleadoPorId(aux);

    if(emple.getidPersona()>0)
    {


        rlutil::setColor(15);
        rlutil::locate(10,12);
        cout <<"Apellido: "<<emple.getapellido()<<endl;
        //rlutil::locate(26,12);
        rlutil::msleep(500);

        rlutil::locate(10,14);
        cout<<"Nombre: "<< emple.getnombre()<<endl;
        //rlutil::locate(26,14);
        rlutil::msleep(500);

        rlutil::locate(10,16);
        cout <<"DNI: "<< emple.getdniPersona()<<endl;
        //rlutil::locate(emple16);
        rlutil::msleep(500);

        rlutil::locate(10,18);
        cout <<"Es Empleado: "<<(emple.getEsEmpleado()?"si" : "no" ) <<endl;
        rlutil::msleep(500);

        rlutil::locate(10,20);
        cout <<"numero Legajo "<< emple.get_numeroLegajo() <<endl;
        //rlutil::locate(26,18);
        rlutil::msleep(500);

        rlutil::locate(10,22);
        cout <<"Activo: "<<( emple.getactivo()? "si" : "no") <<endl;
        //rlutil::locate(26,18);
        rlutil::msleep(500);

        rlutil::locate(10,24);
        cout <<"es administrador: "<< (emple.get_admin()?"si" :"no") <<endl;
        //rlutil::locate(26,18);
        rlutil::msleep(500);


    }
    else
    {
        rlutil::setColor(15);
        rlutil::locate(15,16);
        cout<<"El id buscado es incorrecto!!"<< endl;
        rlutil::msleep(2000);

    }

    /// modificacion

    limpiarBuffer();

    rlutil::setColor(15);
    rlutil::locate(40,12);
    cout<<"Apellido: ";
    cin.getline(apellido,50);
    if(strlen(apellido)>0)
    {
        emple.setapellido(apellido) ;
    }

    rlutil::locate(40,14);
    cout<<"Nombre: ";
    cin.getline(nombre,50);
    if (strlen(nombre)>0)
    {
        emple.setnombre(nombre);
    }


    rlutil::locate(40,16);
    cout <<"DNI: ";
    cin.getline(dni,12);
    if(strlen(dni)>0)
    {
        emple.setdniPersona(atoi(dni));
    }

    rlutil::locate(40,18);
    cout <<"item no editable ";

    rlutil::locate(40,20);
    cout <<"item no editable ";

    rlutil::locate(40,22);
    cout <<"item no editable ";

    rlutil::locate(40,24);
    cout <<"item no editable ";


    do
    {

        rlutil::locate(5,26);
        cout<<" 1-Guardar  0-Cancelar: ";

        rlutil::locate(30,26);
        cin>> aux;

        if(aux==1)
        {

            return serviEmple.modificarEmpleado(emple, emple.getidPersona()-1);

        }
        else if(aux==0)
        {
            return false;
        }
        else
        {

            rlutil::locate(35,26);
            cout<<"eleccion incorrecta!!!!";
            rlutil::msleep(1500);
            rlutil::locate(30,26);
            cout<<"                                       ";
        }

    }
    while(aux<0 || aux>1);
}


void Pantallas:: pReactivarCliente()
{
    int num, eleccion;
    ServicioCliente servicli;
    rlutil::cls();

    ///lista todos los que estan inactivos

    if(!servicli.listarClientes(0))
    {
        rlutil::locate(5,5);
        cout<<"no hay registros cargados"<<endl;
        rlutil::msleep(2000);
        return;
    }

    /// pedimos el id a reactivar
    cout<<"indique el Id del usuario que quiere reactivar: ";
    cin>> num;
    cout<<endl<<endl;

    /// preguntamos que quiere hacer

    cout<<"1- confirmar    0- cancelar"<<endl<< endl;


    do
    {

        cout <<"Eleccion: ";
        cin>> eleccion;


        if(eleccion== 1)
        {

            servicli.reactivarCliente(num);



            cout<<"                    Reactivacion exitosa!!! ";
            rlutil::msleep(1500);

        }

        else if (eleccion ==0)
        {


            cout<<"                    reactivacion  cancelada!!! "<<endl;
            rlutil::msleep(1500);
            return;
        }
        else
        {
            avisoError();
        }

    }
    while(eleccion <0 || eleccion>1);

}


void Pantallas:: pReactivarEmpleado()
{

    int num, eleccion;
    ServicioEmpleado serviEmple;
    rlutil::cls();

    ///lista todos los que estan inactivos

    if(!serviEmple.listarEmpleados(0))
    {
        rlutil::locate(5,5);
        cout<<"no hay registros cargados"<<endl;
        rlutil::msleep(2000);
        return;
    }

    /// pedimos el id a reactivar
    cout<<"indique el Id del empleado que quiere reactivar: ";
    cin>> num;
    cout<<endl<<endl;

    /// preguntamos que quiere hacer

    cout<<"1- confirmar    0- cancelar"<<endl<< endl;


    do
    {

        cout <<"Eleccion: ";
        cin>> eleccion;


        if(eleccion== 1)
        {

            serviEmple.reactivarEmpleado(num) ;
            /// servicli.reactivarCliente(num);



            cout<<"                    Reactivacion exitosa!!! ";
            rlutil::msleep(1500);

        }

        else if (eleccion ==0)
        {


            cout<<"                    reactivacion  cancelada!!! "<<endl;
            rlutil::msleep(1500);
            return;
        }
        else
        {
            avisoError();
        }

    }
    while(eleccion <0 || eleccion>1);

}


/// PELICULAS

int Pantallas::menuAdminPeliculas()
{
    int aux;
    rlutil:: cls();

    marcoPantalla(60,20);
    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"MENU PELICULAS "<<endl;
    rlutil::setColor(15);
    rlutil::locate(15,10);
    cout<<"1- Agregar pelicula nueva  "<<endl;
    rlutil::locate(15,12);
    cout<<"2- Listar peliculas  "<<endl;

    rlutil::locate(15,14);
    cout<<"3- Modificar pelicula "<<endl;

    rlutil::locate(15,16);
    cout<<"4- Buscar pelicula "<<endl;

    rlutil::locate(15,18);
    cout<<"5- Eliminar pelicula "<<endl;

    rlutil::locate(15,20);
    cout<<"6- reactivar pelicula"<<endl;

    rlutil::locate(15,22);
    cout<<"0- Salir "<<endl;

    rlutil::locate(5,26);
    cout <<"Eleccion: ";
    cin>> aux;

    return aux;
}




void Pantallas::pAgregarPelicula ()
{
    limpiarBuffer();
    Pelicula peli;


    int idPelicula, numero, eleccion;
    char nombrePelicula[50],clasificacion[3], director[50],genero[3];


    marcoPantalla(60,20);

    rlutil::setColor(4);

    rlutil::locate(30,8);
    cout<<"Agregar Pelicula "<<endl;
    rlutil::setColor(15);

    rlutil::locate(15,12);
    cout <<"Nombre: ";

    cin.getline(nombrePelicula, 50);
    peli.SetNombrePelicula(nombrePelicula) ;


    int tam2= sizeof(Pelicula::listaClasificacion)/ sizeof(Pelicula::listaClasificacion[0]);

    do
    {
        rlutil::locate(15,14);
        cout<<"Clasificacion: ";

        rlutil::locate(25,26);
        for(int i=0; i<tam2; i++)
        {
            cout<<i+1<<"-"<<Pelicula::listaClasificacion[i]<<" ";
        }

        rlutil::locate(30,14);
        cin.getline(clasificacion, 3);

        numero = atoi(clasificacion); ///ATOI ASCII TO INTEGER

        if (numero > 0 && numero <= tam2)
        {
            peli.SetClasificacion(numero-1);

        }
        else
        {
            rlutil::locate(25,26);
            cout<<"eleccion incorrecta!!!!                               ";

            rlutil::msleep(1500);
            rlutil::locate(24,26);
            cout<<"                                             ";
            rlutil::locate(30,14);
            cout<<"                   ";
        }

    }
    while(numero <1 || numero >tam2);

    cin.clear();

    rlutil::locate(25,26);
    cout<<"                                                         ";




    int tam = sizeof(Pelicula::listaGenero) / sizeof(Pelicula::listaGenero[0]);

    do
    {
        rlutil::locate(15,16);
        cout<<"Genero: ";

        rlutil::locate(25,26);
        for(int i=0; i< tam; i++)
        {
            cout<<i+1<<"-"<<Pelicula::listaGenero[i]<<" ";
        }

        rlutil::locate(23,16);
        cin.getline(genero,3);


        numero = atoi(genero); ///ATOI se castea a entero

        if (numero > 0 && numero <= tam)
        {
            peli.SetGenero(numero-1);

        }
        else
        {
            rlutil::locate(25,26);
            cout<<"eleccion incorrecta!!!!                           ";

            rlutil::msleep(1500);
            rlutil::locate(24,26);
            cout<<"                                                ";
            rlutil::locate(23,16);
            cout<<"  ";
        }

    }
    while(numero <1 || numero >tam);

    cin.clear();

    rlutil::locate(25,26);
    cout<<"                                                         ";


    rlutil::locate(15,18);
    cout << "Director: ";
    rlutil::locate(25,18);
    cin.getline(director, 50);
    peli.SetDirector(director);

    peli.SetActivo(true);

    peli.SetIdPelicula(generacionId(3));



    rlutil::locate(15,22);
    cout<<"1- guardar    0- cancelar "<<endl;


    do
    {
        rlutil::locate(5,26);
        cout <<"Eleccion: ";
        cin>> eleccion;


        if(eleccion== 1)
        {
            servicioPelicula servipeli;

            servipeli.guardarPelicula(peli);
            rlutil::locate(25,26);
            cout<<"Guardado exitoso!! ";
            rlutil::msleep(1500);

        }

        else if (eleccion ==0)
        {

            rlutil::locate(25,26);
            cout<<"operacion cancelada "<<endl;
            rlutil::msleep(1500);
            return;
        }
        else
        {
            avisoError();
        }

    }
    while(eleccion <0 || eleccion>1);


}






void Pantallas:: pBuscarPeliculaId()
{

    servicioPelicula servipeli;
    Pelicula peli;

    int aux;

    marcoPantalla(60,20);

    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"Buscar Pelicula "<<endl;

    rlutil::locate(15,10);
    cout<<"Indique el id: "<<endl;
    rlutil::locate(30,10);
    cin>> aux;

    peli= servipeli.BuscarPeliculaPorId(aux);

    if(peli.GetIdPelicula()>0)
    {

        rlutil::setColor(15);
        rlutil::locate(15,12);
        cout <<"Nombre: "<<peli.GetNombrePelicula()<<endl;
        rlutil::msleep(500);


        rlutil::locate(15,14);
        cout<<"Clasificacion: "<< peli.GetClasificacion()<<endl;
        rlutil::msleep(500);

        rlutil::locate(15,16);
        cout<<"Genero: "<< peli.GetGenero()<<endl;
        //rlutil::locate(26,14);
        rlutil::msleep(500);


        rlutil::locate(15,18);
        cout <<"Director: "<< peli.GetDirector()<<endl;
        //rlutil::locate(26,16);
        rlutil::msleep(500);

        rlutil::locate(15,20);
        cout <<"Estado "<< (peli.GetActivo()? "Activo" : "Inactivo") <<endl;
        //rlutil::locate(26,18);
        rlutil::msleep(500);


    }
    else
    {
        rlutil::setColor(15);
        rlutil::locate(15,16);
        cout<<"El id buscado es incorrecto!!"<< endl;
        rlutil::msleep(2000);
    }



    rlutil::anykey();

}



bool Pantallas::pModificarPelicula()
{


    limpiarBuffer();

    int aux;
    char nombrePelicula[50];
    int genero;
    int clasificacion;
    char director [100];


    servicioPelicula serviPeli;
    Pelicula peli;

    marcoPantalla(60,20);

    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"Modificar Pelicula "<<endl;

    rlutil::locate(10,10);
    cout<<"Indique el id: "<<endl;
    rlutil::locate(25,10);
    cin>> aux;

    peli= serviPeli.BuscarPeliculaPorId(aux);

    if(peli.GetIdPelicula()>0)

    {


        rlutil::setColor(15);
        rlutil::locate(10,12);
        cout <<"Nombre: "<<peli.GetNombrePelicula()<<endl;
        //rlutil::locate(26,12);
        rlutil::msleep(500);


        rlutil::locate(10,14);
        cout<<"Director: "<< peli.GetDirector()<<endl;
        //rlutil::locate(26,14);
        rlutil::msleep(500);

        rlutil::locate(10,16);
        cout <<"Clasificacion "<< peli.GetClasificacion()<<endl;
        //rlutil::locate(emple16);
        rlutil::msleep(500);

        ///GENERO
        rlutil::locate(10,18);
        cout <<"Genero "<< peli.GetGenero()<<endl;
        rlutil::msleep(500);


        rlutil::locate(10,20);
        cout <<"Estado: "<<(peli.GetActivo()?"Activo": "Inactivo") <<endl; ///ACTIVO
        rlutil::msleep(500);


    }
    else
    {
        rlutil::setColor(15);
        rlutil::locate(15,16);
        cout<<"El id buscado es incorrecto!!"<< endl;
        rlutil::msleep(2000);
        return false;

    }

    /// modificacion

    limpiarBuffer();

    rlutil::setColor(15);
    rlutil::locate(40,12);
    cout<<"Nombre: ";
    cin.getline(nombrePelicula,50);

    if(strlen(nombrePelicula)>0)
    {
        peli.SetNombrePelicula(nombrePelicula) ;
    }

    rlutil::locate(40,14);
    cout<<"Director: ";
    cin.getline(director,100);
    if (strlen(director)>0)
    {
        peli.SetDirector(director);
    }


    rlutil::locate(40,16);
    cout <<"Clasificacion: ";

    int tam= sizeof(Pelicula::listaClasificacion)/ sizeof(Pelicula::listaClasificacion[0]);

    rlutil::locate(25,26);
    for(int i=0; i<tam; i++)
    {

        cout<<i+1<<"-"<< Pelicula::listaClasificacion[i]<<" ";
    }

    rlutil::locate(55,16);
    cin>>clasificacion;


    if(clasificacion>0 && clasificacion <=tam )
    {
        peli.SetClasificacion(clasificacion-1);
    }

    cin.clear();
    limpiarBuffer();

    ///genero
    int tam2 = sizeof(Pelicula::listaGenero) / sizeof(Pelicula::listaGenero[0]);


    rlutil::locate(40,18);
    cout <<"Genero: ";
    rlutil::locate(30,26);

    for(int i=0; i<tam2; i++)
    {

        cout<<i+1<<"-"<< Pelicula::listaGenero[i]<<" ";
    }


    rlutil::locate(48,18);
    cin>>genero;

    if(genero>0 && genero <=tam2 )
    {
        peli.SetGenero(genero-1);
    }

    limpiarBuffer();


    rlutil::locate(40,20);
    cout <<"item no editable";



    do
    {

        rlutil::locate(5,26);
        cout<<" 1-Guardar  0-Cancelar: ";

        rlutil::locate(30,26);
        cin>> aux;

        if(aux==1)
        {

            serviPeli.modificarPelicula(peli, peli.GetIdPelicula()-1);
            return true;

        }
        else if(aux==0)
        {
            return false;
        }
        else
        {

            rlutil::locate(35,26);
            cout<<"eleccion incorrecta!!!!";
            rlutil::msleep(1500);
            rlutil::locate(30,26);
            cout<<"                                       ";


        }

    }
    while(aux<0 || aux>1);

}












int Pantallas::pEliminarPelicula()
{

    int aux, eleccion;
    rlutil:: cls();

    marcoPantalla(60,20);
    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"Eliminacion Pelicula "<<endl;
    rlutil::setColor(15);
    rlutil::locate(15,10);
    cout<<"Indique el id a eliminar: "<<endl;

    rlutil::locate(41,10);
    cin>> aux;

    rlutil::locate(15,18);
    cout<<"1- guardar    0- cancelar"<<endl;


    do
    {

        rlutil::locate(5,26);
        cout <<"Eleccion: ";
        cin>> eleccion;


        if(eleccion== 1)
        {
            return aux;


        }
        else if (eleccion ==0)
        {
            return -1;
        }
        else
        {
            avisoError();
        }

    }
    while(eleccion <0 || eleccion>1);


}


void Pantallas::pReactivarPelicula()
{

    int num, eleccion;
    servicioPelicula servipeli;
    rlutil::cls();

    ///lista todos los que estan inactivos

    if(!servipeli.listarPelicula(0))
    {
        rlutil::locate(5,5);
        cout<<"no hay registros cargados"<<endl;
        rlutil::msleep(2000);
        return;
    }

    /// pedimos el id a reactivar
    cout<<"indique el Id del usuario que quiere reactivar: ";
    cin>> num;
    cout<<endl<<endl;

    /// preguntamos que quiere hacer

    cout<<"1- confirmar    0- cancelar"<<endl<< endl;


    do
    {

        cout <<"Eleccion: ";
        cin>> eleccion;


        if(eleccion== 1)
        {

            servipeli.reactivarPelicula(num);

            cout<<"                    Reactivacion exitosa!!! ";
            rlutil::msleep(1500);

        }

        else if (eleccion ==0)
        {


            cout<<"                    reactivacion  cancelada!!! "<<endl;
            rlutil::msleep(1500);
            return;
        }
        else
        {
            avisoError();
        }

    }
    while(eleccion <0 || eleccion>1);

}


///SALAS


Sala Pantallas::pAgregarSala()
{

    int tipoSala, capacidad, auxActivo;

    char nombre[50];

    Sala sal;

    limpiarBuffer();
    marcoPantalla(60,20);

    rlutil::setColor(4);
    rlutil::locate(30,8);
    cout<<"Crear Sala"<<endl;

    rlutil::setColor(15);
    rlutil::locate(15,12);
    cout <<"Nombre:";
    rlutil::locate(26,12);
    cin.getline(nombre,50);
    sal.SetNombreSala(nombre);

    rlutil::locate(15,14);
    cout<<"Tipo de sala: ";

    rlutil::locate(25,26);
    for(int i=0; i<3; i++)
    {
        cout<< i+1 << "-" << Sala::listaTipoSala[i] << "  ";
    }

    int tam= (sizeof(Sala::listaTipoSala)/ sizeof(Sala::listaTipoSala[0]));

    rlutil::locate(30,14);
    cin>>tipoSala;

    if(tipoSala>0 || tipoSala<=tam)
    {

        sal.SetTipoSala(tipoSala-1);
    }

    rlutil::locate(25,26);
    cout<<"                                  ";

    rlutil::locate(15,16);
    cout <<"Capacidad: ";
    rlutil::locate(26,16);
    cin >>capacidad;
    sal.SetCapacidadSala( capacidad);


    sal.SetActivo(true);
    sal.SetIdSala(generacionId(4));


    limpiarBuffer();


    return sal;
}






void Pantallas::pBuscarSalaPorId()
{
    int aux;
    ServicioSala serviSala;
    Sala sala;

    marcoPantalla(60, 20);

    rlutil::setColor(4);
    rlutil::locate(25, 8);
    cout << "Buscar Sala" << endl;

    rlutil::setColor(15);
    rlutil::locate(15, 10);
    cout << "Indique el id: ";
    rlutil::locate(30, 10);
    cin >> aux;

    sala = serviSala.buscarSala(aux);

    if (sala.GetIdSala() > 0)
    {

        rlutil::setColor(15);

        rlutil::locate(15, 12);
        cout << "Nombre: " << sala.GetNombreSala() << endl;
        rlutil::msleep(500);

        rlutil::locate(15, 14);
        cout << "Tipo: " << sala.GetTipoSala() << endl;
        rlutil::msleep(500);

        rlutil::locate(15, 16);
        cout << "Capacidad: " << sala.GetCapacidadSala() << endl;
        rlutil::msleep(500);

        rlutil::locate(15, 18);
        cout << "Estado: " << (sala.GetActivo() ? "Activo" : "Inactivo") << endl;
        rlutil::msleep(500);

        rlutil::locate(5, 22);
        cout << "Presione cualquier tecla para continuar..... ";
        rlutil::anykey();
    }
    else
    {
        rlutil::setColor(15);
        rlutil::locate(15, 16);
        cout << "El ID buscado es incorrecto!!" << endl;
        rlutil::msleep(2000);
    }
}






/*
void Pantallas::pMostrarSala(Sala* sala) {
   if (sala == nullptr) {
       cout << "No hay sala para mostrar.\n";
       return;
   }

   limpiarBuffer();
   marcoPantalla(80, 30);

   rlutil::setColor(4);
   rlutil::locate(35, 2);
   cout << "Sala Creada" << endl;

   rlutil::setColor(15);
   rlutil::locate(10, 4);
   cout << "Nombre: " << sala->GetNombreSala();

   rlutil::locate(10, 5);
   cout << "Tipo de sala: " << sala->GetTipoSala();

   rlutil::locate(10, 6);
   cout << "Filas: " << sala->GetFilas();

   rlutil::locate(10, 7);
   cout << "Columnas: " << sala->GetColumnas();

   rlutil::locate(10, 8);
   cout << "Activa: " << (sala->GetActivo() ? "Sí" : "No");

   rlutil::setColor(14);
   rlutil::locate(10, 10);
   cout << "Estado de los asientos (1 = ocupado, 0 = libre):";

   bool** matriz = sala->GetAsientos();
   int filas = sala->GetFilas();
   int columnas = sala->GetColumnas();

   for (int i = 0; i < filas; ++i) {
       rlutil::locate(10, 12 + i);
       for (int j = 0; j < columnas; ++j) {
           cout << (matriz[i][j] ? "1 " : "0 ");
       }
   }

   rlutil::setColor(15);
   rlutil::locate(10, 13 + filas);
   cout << "Presione una tecla para continuar...";
   rlutil::anykey();
}





*/


/// funciones

int Pantallas::menuAdministrarFuncion()
{
    int aux;
    rlutil:: cls();

    marcoPantalla(60,20);
    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"MENU FUNCION "<<endl;
    rlutil::setColor(15);
    rlutil::locate(15,10);
    cout<<"1- Agregar Funcion  "<<endl;
    rlutil::locate(15,12);
    cout<<"2- Listar Funciones  "<<endl;

    rlutil::locate(15,14);
    cout<<"3- Modificar Funcion "<<endl;

    rlutil::locate(15,16);
    cout<<"4- Buscar Fucion "<<endl;

    rlutil::locate(15,18);
    cout<<"5- Eliminar Funcion "<<endl;

    rlutil::locate(15, 20);
    cout<<"6- reactivar Funcion "<<endl;

    rlutil::locate(15,22);
    cout<<"0- Salir "<<endl;

    rlutil::locate(5,26);
    cout <<"Eleccion: ";
    cin>> aux;

    return aux;
}



Funcion Pantallas::pAgregarFuncion()
{

    Funcion fun;
    int idSala, idfuncion, idPelicula;
    int dia, mes, anio, hora, minuto;

    limpiarBuffer();
    marcoPantalla(60,22);

    rlutil::setColor(4);
    rlutil::locate(30,8);
    cout << "Crear Funcion" << endl;

    rlutil::setColor(15);


    // ID Funcion
    rlutil::locate(15,10);
    idfuncion =generacionId(5);
    cout<<"ID FUNCION: "<< idfuncion;

    // ID SALA


    rlutil::locate(15,12);
    cout << "ID Sala: ";
    rlutil::locate(26,12);
    cin>> idSala;

    ServicioSala serviSala;
    Sala sala = serviSala.buscarSala(idSala);

    if(sala.GetIdSala() == 0)
    {
        cout << "No se encontro IdSala";
        rlutil::msleep(1500);
        fun.SetIdSala(0);
        return fun;
    }

    fun.SetIdSala(idSala);
    fun.SetCantidadAsientos(sala.GetCapacidadSala());
    fun.crearAsientosDisponibles(sala.GetCapacidadSala());   // inicializo asientos



    // ID PELICULA

    rlutil::locate(15,14);
    cout << "ID Pelicula: ";
    rlutil::locate(29,14);
    cin >> idPelicula;

    servicioPelicula servipeli;
    Pelicula peli = servipeli.BuscarPeliculaPorId(idPelicula);

    if(peli.GetIdPelicula() == 0)
    {
        cout << "No se encontro IdPelicula";
        rlutil::msleep(1500);
        fun.SetIdPelicula(0);  // bandera de error
        return fun;
    }

    fun.SetIdPelicula(idPelicula);



    // FECHA

    rlutil::locate(15,16);
    cout << "Dia: ";
    rlutil::locate(22,16);
    cin >> dia;

    rlutil::locate(28,16);
    cout << "Mes: ";
    rlutil::locate(33,16);
    cin >> mes;

    rlutil::locate(38,16);
    cout << "Anio: ";
    rlutil::locate(44,16);
    cin >> anio;

    rlutil::locate(15,18);
    cout << "Hora funcion: ";
    rlutil::locate(29,18);
    cin >> hora;
    cout<<" ";
    rlutil::locate(32,18);
    cout << "Minutos: ";
    rlutil::locate(41,18);
    cin >> minuto;


    Fecha f;
    f.SetMinuto(minuto);
    f.SetHora(hora);
    f.SetDia(dia);
    f.SetMes(mes);
    f.SetAnio(anio);

    fun.SetFecha(f);



    // ESTADO + ID

    fun.SetActiva(true);
    fun.SetIdFuncion(idfuncion);

    limpiarBuffer();

    return fun;
}

/*
 bool Pantallas::pAsignarAsientos() {
    ServicioVenta serviVenta;
    ServicioFuncion serviFuncion;

    int idFuncion, idVenta;
    cout << "Ingrese el ID de la funcion: ";
    cin >> idFuncion;
    cout << "Ingrese el ID de la venta: ";
    cin >> idVenta;

    Funcion funcion = serviFuncion.buscarPosicionFuncion(idFuncion - 1);
    Venta venta = serviVenta.buscarPosicionVenta(idVenta - 1);

    if (funcion.GetIdFuncion() == 0 || venta.GetIdVenta() == 0) {
        cout << "Función o venta no encontrada." << endl;
        return false;
    }

    if (serviVenta.asignarAsientos(funcion, venta)) {
        cout << "Asientos asignados correctamente." << endl;
        serviFuncion.modificarFuncion(funcion, idFuncion - 1);
        return true;
    } else {
        cout << "Error al asignar los asientos." << endl;
        return false;
    }
}

  */



int Pantallas::pEliminarSala() {
    int aux, eleccion;
    rlutil::cls();

    marcoPantalla(60, 20);
    rlutil::setColor(4);
    rlutil::locate(25, 8);
    cout << "Eliminacion Sala" << endl;

    rlutil::setColor(15);
    rlutil::locate(15, 10);
    cout << "Indique el id a eliminar: " << endl;

    rlutil::locate(41, 10);
    cin >> aux;

    rlutil::locate(15, 18);
    cout << "1- guardar    0- cancelar" << endl;

    do {
        rlutil::locate(5, 26);
        cout << "Eleccion: ";
        cin >> eleccion;

        if (eleccion == 1) {
            return aux;
        } else if (eleccion == 0) {
            return -1;
        } else {
            avisoError();
        }
    } while (eleccion < 0 || eleccion > 1);
}



bool Pantallas::pModificarSala() {
    limpiarBuffer();

    int aux;
    char nombreSala[50];
    bool activo;
    int tipoSala;
    int capacidadSala;

    ServicioSala serviSala;
    Sala sala;

    marcoPantalla(60, 20);

    rlutil::setColor(4);
    rlutil::locate(25, 8);
    cout << "Modificar Sala " << endl;

    rlutil::locate(10, 10);
    cout << "Indique el id: " << endl;
    rlutil::locate(25, 10);
    cin >> aux;

    sala = serviSala.buscarSala(aux);

    if (sala.GetIdSala() > 0) {
        rlutil::setColor(15);
        rlutil::locate(10, 12);
        cout << "Nombre: " << sala.GetNombreSala() << endl;
        rlutil::msleep(500);

        rlutil::locate(10, 14);
        cout << "Activo: " << sala.GetActivo() << endl;
        rlutil::msleep(500);

        rlutil::locate(10, 16);
        cout << "Tipo Sala: " << sala.GetTipoSala() << endl;
        rlutil::msleep(500);

        rlutil::locate(10, 18);
        cout << "Capacidad sala: " << sala.GetCapacidadSala() << endl;
        rlutil::msleep(500);
    } else {
        rlutil::setColor(15);
        rlutil::locate(15, 16);
        cout << "El id buscado es incorrecto!!" << endl;
        rlutil::msleep(2000);
        return false;
    }

    limpiarBuffer();

    rlutil::setColor(15);
    rlutil::locate(40, 12);
    cout << "Nombre: ";
    cin.getline(nombreSala, 50);

    if (strlen(nombreSala) > 0) {
        sala.SetNombreSala(nombreSala);
    }

    rlutil::locate(40, 14);
    cout << "Activo: 0=NO , 1=SI ";
    cin >> activo;
    sala.SetActivo(activo);

    rlutil::locate(40, 16);
    cout << "Tipo de sala: 1=2D , 2=3D, 3=4D ";
    int tam = (sizeof(Sala::listaTipoSala) / sizeof(Sala::listaTipoSala[0]));

    rlutil::locate(30, 18);
    cin >> tipoSala;

    if (tipoSala > 0 && tipoSala <= tam) {
        sala.SetTipoSala(tipoSala - 1);
    }

    cin.clear();
    limpiarBuffer();

    rlutil::locate(40, 20);
    cout << "Capacidad: ";
    cin >> capacidadSala;
    sala.SetCapacidadSala(capacidadSala);

    do {
        rlutil::locate(5, 26);
        cout << "1-Guardar  0-Cancelar: ";
        rlutil::locate(30, 26);
        cin >> aux;

        if (aux == 1) {
            serviSala.modificarSala(sala, sala.GetIdSala() - 1);
            return true;
        } else if (aux == 0) {
            return false;
        } else {
            rlutil::locate(35, 26);
            cout << "Eleccion incorrecta!!!!";
            rlutil::msleep(1500);
            rlutil::locate(30, 26);
            cout << "                                       ";
        }
    } while (aux < 0 || aux > 1);
}


