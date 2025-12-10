#pragma once

class Sala {

public:

    static const char* listaTipoSala[3];

    int GetIdSala();
    const char* GetNombreSala();
    bool GetActivo();
    const char* GetTipoSala();
    int GetCapacidadSala();




    void SetIdSala(int);
    void SetNombreSala(const char*);
    void SetActivo(bool);
    void SetTipoSala(int);
    void SetCapacidadSala(int);





private:
    int _idSala;
    char _nombreSala[50];
    bool _activo;
    char _tipoSala[30];
    int _capacidadSala;


};
