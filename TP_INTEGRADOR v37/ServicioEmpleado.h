#pragma once
#include "Empleado.h"

class ServicioEmpleado{

 public:

    ServicioEmpleado();

    bool guardarEmpleado(Empleado emp1);

    int contadorEmpleados();

    Empleado buscarPosicionEmpleado(int posicion);

    Empleado buscarEmpleadoPorId(int id);

    bool modificarEmpleado(Empleado emp1, int pos);

    bool bajaEmpleado(int id);

    bool listarEmpleados(int activ);

    bool reactivarEmpleado(int id);








};
