#pragma once

class Persona
{

protected:
    int _idPersona;
    int _dni;
    char _nombre[50];
    char _apellido[50];
    bool _esEmpleado;
    bool _activo;

public:

    Persona();

    void cargarPersona();
    void mostrarPersona();

    void setidPersona(int);
    int getidPersona();

    void setdniPersona(int);
    int getdniPersona();

    void setnombre(const char *);
    const char* getnombre();

    void setapellido(const char *);
    const char* getapellido();

    void setactivo(bool);
    bool getactivo();

    void setEsEmpleado(bool esEmple);
    bool getEsEmpleado();




};

