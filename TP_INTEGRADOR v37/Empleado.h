#pragma once
#include "Persona.h"

class Empleado : public Persona {

private :

    bool _admin;
    int _numeroLegajo;

public:

    Empleado();

   // void cargarEmpleado();
    //void mostrarEmpleado();


    void set_numeroLegajo(int );

    int get_numeroLegajo();

    void set_admin(bool);

    bool get_admin();




};

