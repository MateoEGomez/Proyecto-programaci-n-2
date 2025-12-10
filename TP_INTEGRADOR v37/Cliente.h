
#pragma once
#include "Persona.h"

class Cliente: public Persona {

private:

   char _email[50];


public:


    void set_email(const char* email);
    const char* get_email();




};

