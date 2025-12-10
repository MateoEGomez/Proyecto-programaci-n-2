#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "MisFunciones.h"
#include "rlutil.h"
#include "Manager.h"
#include "Pantallas.h"
#include "Pelicula.h"
using namespace std;
int main()
{
    Manager man1;
    Pantallas pantalla;
    Pelicula peli;



    int eleccion, eleccion2, eleccion3;

    do
    {
        eleccion = pantalla.menuPrincipal();

        switch (eleccion)
        {
        /// ventas
        case 1:


            do
            {
                eleccion2 = pantalla.menuVentas();

                switch (eleccion2)
                {

                case 1 :
                     man1.m_agregarVenta();
                    break;
                case 2:
                     man1.m_listarVentas();

                    break;
                case 3 :


                    break;
                case 4:

                    break;
                case 5:

                    break;
                case 0:


                    break;

                }
            }while(eleccion2!=0);



            break;

        /// administracion
        case 2:

            do
            {
                eleccion2 = pantalla.menuAdmin();
                /// 1er submenu
                switch (eleccion2)
                {

                /// administrar cliente
                case 1 :

                    do
                    {
                        eleccion3 = pantalla.menuAdministrarCliente() ;

                        switch (eleccion3)
                        {

                        ///agregar cliente
                        case 1:
                            man1.m_crearCliente();

                            break;
                        /// listar clientes
                        case 2:
                            man1.m_listarClientes();

                            break;
                        /// modificar cliente
                        case 3:
                            man1.m_modificarCliente();
                            break;
                        /// buscar cliente
                        case 4:
                            man1.m_buscarClienteId();

                            break;
                        /// eliminar cliente
                        case 5:
                            man1.m_eliminarCliente();
                            break;
                        /// reactiacion
                        case 6:
                            man1.m_reactivarCliente();
                            break;

                        /// salir

                        case 0:


                            break;
                        default:

                            break;

                        }
                    }
                    while(eleccion3 !=0);


                    break;

                /// administrar empleados
                case 2:

                    do
                    {

                        eleccion3 = pantalla.menuAdministrarEmpleado();

                        switch (eleccion3)
                        {

                        ///agregar empleado
                        case 1:
                            man1.m_crearEmpleado();
                            break;
                        /// listar empleado
                        case 2:
                            man1.m_listarEmpleados() ;

                            break;
                        /// eliminar empleado
                        case 5:
                            man1.m_eliminarEmpleado();

                            break;
                        /// buscar empleado
                        case 4:
                            man1.m_buscarEmpleadoId();

                            break;
                        /// modificar empleado
                        case 3:
                            man1.m_modificarEmpleado();

                            break;

                        case 6:
                            man1.m_reactivarEmpleado();
                        /// salir
                        case 0:

                            break;
                        default:

                            break;

                        }
                    }
                    while(eleccion3 !=0);

                    break;

                ///administrar peliculas
                case 3 :
                    do
                    {

                        eleccion3 = pantalla.menuAdminPeliculas();

                        switch (eleccion3)
                        {
                        case 1: ///AGREGAR PELICULA NUEVA

                            man1.m_crearPelicula();

                            break;

                        case 2: ///LISTAR PELICULAS

                            man1.m_listarPelicula();
                            break;

                        case 3: ///MODIFICAR PELICULA

                            man1.m_modificarPelicula();

                            break;

                        case 4:///BUSCAR PELICULA

                           man1.m_buscarPeliculaId();

                        break;

                        case 5:///ELIMINAR PELICULA

                          man1.m_eliminarPelicula();

                        break;

                        case 6:
                           man1.m_reactivarPelicula();

                             break;
                        case 0: ///SALIR
                            eleccion3=0;

                        break;
                        }

                    }while(eleccion3!=0);

                    break;
                /// Adminstrador Salas
                case 4:

                        eleccion3=0;
                     do
                    {

                        eleccion3 = pantalla.menuAdministrarSala();

                        switch (eleccion3)
                        {
                        case 1: ///agregar sala

                             man1.m_crearsala();

                            break;

                        case 2: ///listar salar

                             man1.m_listarSalas();

                            break;

                        case 3: ///modificar sala

                                man1.m_modificarSala();

                            break;

                        case 4:///buscar sala
                           man1.m_buscarSalaPorId();


                        break;

                        case 5:///eliminar sala

                             man1.m_eliminarSala();

                        break;

                        case 6:/// reactivar sala


                             break;
                        case 0: ///SALIR
                            eleccion3=0;

                        break;
                        }

                    }while(eleccion3!=0);

                    break;

                case 5:

                            eleccion3=0;
                         do
                        {

                            eleccion3 = pantalla.menuAdministrarFuncion();

                            switch (eleccion3)  {

                        case 1:  /// agregar funcion
                            man1.m_agregarFuncion();

                            break;
                        case 2: ///listar Funcion
                            man1.m_listarFunciones();

                            break;
                        case 3:  /// buscar Funcion
                            break;
                        case 4: ///eliminar Funcion
                            break;
                            }
                        }while(eleccion3!=0);
                    break;


                case 0:

                    eleccion2=0;
                    break;

                }
            }while(eleccion2!=0);



            break;
        /// informes
        case 3:
            eleccion2 = pantalla.menuInformes();


            break;
        default:
            break;


        }


    }
    while (eleccion !=0);




    return 0;
}
