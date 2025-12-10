#include <iostream>
#include <cstring>
#include "Empleado.h"

using namespace std;


    Empleado:: Empleado(){

    }

    void Empleado::set_numeroLegajo(int legajo){

       _numeroLegajo= legajo;

    }
    int  Empleado::get_numeroLegajo(){
        return _numeroLegajo;
    }

    void Empleado::set_admin(bool admin){
       _admin = admin;
    }

    bool Empleado::get_admin() {
        return _admin;
    }




