
#include <iostream>
#include <cstring>
#include "rlutil.h"
#include "Cliente.h"
#include "MisFunciones.h"

using namespace std;





void Cliente::set_email(const char* email)
{
    strcpy(_email, email);
    _email[49]='\0';

}

const char* Cliente::get_email()
{
    return _email;
}






