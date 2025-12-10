
#pragma once
#include <string>
#include "Cliente.h"


class ServicioCliente{

   public:

    ServicioCliente();

    bool guardarCliente(Cliente cli);

    int contadorClientes();

    Cliente buscarPosicionCliente(int posicion);

    Cliente buscarClientePorId(int id);

    bool modificarCliente(Cliente cli, int pos);

    bool bajaCliente(int id);

    bool reactivarCliente(int id);

    bool listarClientes(int activ);




};
