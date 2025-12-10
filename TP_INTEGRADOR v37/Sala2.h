#pragma once

class Sala {

public:
    Sala();
    Sala(int f, int c);
    ~Sala();

    int GetIdSala() const;
    const char* GetNombreSala() const;
    int GetCapacidadSala() const;
    int GetTipoSala() const;
    bool GetActivo() const;
    int GetCantidadAsientosLibres();
    int** GetAsientos() const;
    int GetFilas() const;
    int GetColumnas() const;



    void SetIdSala(int);
    void SetNombreSala(const char*);
    void SetCapacidadSala(int);
    void SetTipoSala(int);
    void SetActivo(bool);
    void SetCantidadAsientosLibres();
    void SetAsientos(int** nuevosAsientos);
    void SetFilas(int f);
    void SetColumnas(int c);



private:
    int _idSala;
    char _nombreSala[50];
    int** _asientos;               // matriz dinámica de asientos
    int _tipoSala;
    bool _activo;
    int _capacidadSala;           // cantidad total de asientos
    int _cantidadAsientosLibres;  // cantidad actual de asientos libres
    int filas;
    int columnas;
};
