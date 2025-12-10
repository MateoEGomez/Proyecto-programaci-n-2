
#include <iostream>
#include "Manager.h"
#include "Cliente.h"
#include "rlutil.h"
#include "MisFunciones.h"
#include "ServicioCliente.h"
#include "Empleado.h"
#include "ServicioEmpleado.h"
#include "Pantallas.h"
#include "ServicioSala.h"
#include "Sala.h"
#include "Pelicula.h"
#include "ServicioPelicula.h"
#include "ServicioFuncion.h"
#include "Venta.h"
#include "ServicioVenta.h"

using namespace std;

//cliente

void Manager:: m_crearCliente(){

    Pantallas panta;
    Cliente cli;

    cli= panta.pAgregarCliente();

    ServicioCliente servi;

    /// muestro mesaje segun el resultado
    resultadoAccion(servi.guardarCliente(cli));



}

void Manager::m_listarClientes(){

    ServicioCliente servi;

    rlutil::cls();
    servi.listarClientes(1);

    limpiarBuffer();
    rlutil::anykey();

}

void Manager::m_eliminarCliente(){

    Pantallas panta;
    panta.pEliminarCliente();


}

void Manager::m_buscarClienteId(){

    Pantallas panta;
    panta.pBuscarClienteId();


}

void Manager::m_modificarCliente(){
    ServicioCliente servicli;
    Pantallas panta;
    if(panta.pModificarCliente())
    {
        rlutil::locate(30,26);
        cout<<"modificado correctamente!!! "<<endl;
        rlutil::msleep(2000);
    }
    else
    {
        rlutil::locate(30,26);
        cout<<" no se pudo completar la modificacion"<< endl;
        rlutil::msleep(2000);
    }
}


void Manager::m_reactivarCliente(){

    Pantallas panta;

    panta.pReactivarCliente();


}


/// empleado
void Manager::m_crearEmpleado(){

    Pantallas panta;
    Empleado emple;

    emple=panta.pAgregarEmpleado();

    ServicioEmpleado serviemple;

    /// muestro mesaje segun el resultado
    resultadoAccion(serviemple.guardarEmpleado(emple));

}

void Manager::m_listarEmpleados(){

    limpiarBuffer();
    ServicioEmpleado serviEmple;
    rlutil::cls();

    serviEmple.listarEmpleados(1);


    rlutil::anykey();

}

void Manager::m_eliminarEmpleado(){

    Pantallas panta;
    panta.pEliminarEmpleado();
}

//falta completar buscar
void Manager::m_buscarEmpleadoId(){
    Pantallas panta;
    panta.pBuscarEmpleadoId();


}

void Manager::m_modificarEmpleado(){
    ServicioEmpleado serviEmple;
    Pantallas panta;
    if(panta.PModificarEmpleado())
    {

        rlutil::locate(30,26);
        cout<<"modificado correctamente!!! "<<endl;
        rlutil::msleep(2000);
    }
    else
    {
        rlutil::locate(30,26);
        cout<<" no se pudo completar la modificacion"<< endl;
        rlutil::msleep(2000);
    }

}

void Manager::m_reactivarEmpleado(){

    Pantallas panta;

    panta.pReactivarEmpleado();

}

///pelicula



void Manager::m_crearPelicula(){

    Pantallas panta;
   // Pelicula peli;

    panta.pAgregarPelicula();

    //servicioPelicula serviPeli;

    /// muestro mesaje segun el resultado
    //resultadoAccion(serviPeli.guardarPelicula(peli));  ///

}


void Manager::m_listarPelicula(){
    limpiarBuffer();
    servicioPelicula serviPeli;

    rlutil::cls();
    serviPeli.listarPelicula(1);

    rlutil::anykey();
}

void Manager::m_buscarPeliculaId(){

    Pantallas panta;
    panta.pBuscarPeliculaId();

}


void Manager::m_modificarPelicula(){

    ServicioCliente servicli;
    Pantallas panta;
    if(panta.pModificarPelicula())
    {
        rlutil::locate(30,26);
        cout<<"modificado correctamente!!! "<<endl;
        rlutil::msleep(2000);
    }
    else
    {
        rlutil::locate(30,26);
        cout<<" no se pudo completar la modificacion"<< endl;
        rlutil::msleep(2000);
    }

}



void Manager::m_eliminarPelicula(){

    Pantallas panta;
    servicioPelicula servipeli;

    int auxId = panta.pEliminarPelicula();

    if(auxId>=0)
    {
        servipeli.bajaPelicula(auxId);
        rlutil::locate(25,26);
        cout<<"Eliminacion exitosa ";
        rlutil::msleep(1500);
    }
    else
    {

        rlutil::locate(25,26);
        cout<<"Eliminacion cancelada "<<endl;
        rlutil::msleep(1500);
    }
}


 void Manager::m_reactivarPelicula(){

    Pantallas panta;

    panta.pReactivarPelicula();

}








/// sala



void Manager::m_crearsala() {
    Pantallas panta;
    Sala sal = panta.pAgregarSala();

   if (sal.GetIdSala() == 0) {
       resultadoAccion(false);;
        return;
    }

    ServicioSala servisal;

    if (servisal.crearSala(sal)) {
        resultadoAccion(true);
    } else {
        resultadoAccion(false);
    }

}



void Manager::m_listarSalas(){

    limpiarBuffer();
    ServicioSala serviSala;
    rlutil::cls();

    serviSala.listarSalas(1);


    rlutil::anykey();

}



void Manager::m_buscarSalaPorId(){

          Pantallas panta;
          panta.pBuscarSalaPorId();

          rlutil::anykey();
}


 void Manager::m_modificarSala() {
    ServicioSala serviSala;
    Pantallas panta;

    if (panta.pModificarSala()) {
        rlutil::locate(30, 26);
        cout << "Modificado correctamente!!!" << endl;
        rlutil::msleep(2000);
    } else {
        rlutil::locate(30, 26);
        cout << "No se pudo completar la modificacion" << endl;
        rlutil::msleep(2000);
    }
}


void Manager::m_eliminarSala() {
    Pantallas sala;
    ServicioSala servisala;

    int auxId = sala.pEliminarSala();

    if (auxId >= 0) {
        servisala.eliminarSala(auxId);
        rlutil::locate(25, 26);
        cout << "Eliminacion exitosa" << endl;
        rlutil::msleep(1500);
    } else {
        rlutil::locate(25, 26);
        cout << "Eliminacion cancelada" << endl;
        rlutil::msleep(1500);
    }
}







///funcion

  void Manager::m_agregarFuncion(){
        Pantallas panta;
        Funcion fun = panta.pAgregarFuncion();

        if (fun.GetIdSala() == 0 || fun.GetIdPelicula() == 0) {
        resultadoAccion(false);
        return;
    }


     ServicioFuncion serviFun;

    if (serviFun.crearFuncion(fun)) {
        resultadoAccion(true);
    } else {
        resultadoAccion(false);
    }


  }



 void Manager::m_listarFunciones() {

     limpiarBuffer();
    ServicioFuncion serviFun;

    rlutil::cls();
    serviFun.listarFunciones(1);

    rlutil::anykey();


 }



 /// ventas
void Manager::m_agregarVenta() {

    Pantallas panta;
    Venta ven = panta.pAgregarVenta() ;

    ///-*--------------------

   ///-------------------------------
    ServicioVenta serviVen;
    serviVen.crearVenta(ven);

    cout << "Venta guardada correctamente." << endl;
}


 void Manager::m_listarVentas(){

      ServicioVenta venta;
      venta.listarVentas();
      rlutil::anykey();

 }

 /*
  void Manager::m_asignarAsientos() {
    ServicioVenta serviVenta;
    Pantallas panta;

    if (panta.pAsignarAsientos()) {
        rlutil::locate(30, 26);
        cout << "Asientos asignados correctamente!!!" << endl;
        rlutil::msleep(2000);
    } else {
        rlutil::locate(30, 26);
        cout << "No se pudo completar la asignación de asientos" << endl;
        rlutil::msleep(2000);
    }
}

   */
