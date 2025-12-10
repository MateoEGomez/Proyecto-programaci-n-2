#include <iostream>
#include <cstring>
#include "Sala.h"
using namespace std;
// constructor por defecto
Sala::Sala() {
    _idSala = 0;
    strcpy(_nombreSala, "");
    _tipoSala = 0;
    _activo = false;
    filas = 0;
    columnas = 0;
    _capacidadSala = 0;
    _cantidadAsientosLibres = 0;
    _asientos = nullptr;
}
// constructor con parametros
Sala::Sala(int f, int c) {
    _idSala = 0;
    strcpy(_nombreSala, "");
    _tipoSala = 0;
    _activo = false;
    filas = f;
    columnas = c;
    _capacidadSala = filas * columnas;
    _cantidadAsientosLibres = _capacidadSala;

    _asientos = new int*[filas];
    for (int i = 0; i < filas; i++) {
        _asientos[i] = new int[columnas];
        for (int j = 0; j < columnas; j++) {
            _asientos[i][j] = 0;
        }
    }
}
// destructor
Sala::~Sala() {
    if (_asientos != nullptr) {
        for (int i = 0; i < filas; i++) {
            delete[] _asientos[i];
        }
        delete[] _asientos;
        _asientos = nullptr;
    }
}

int Sala::GetIdSala() const {
    return _idSala;
}

void Sala::SetIdSala(int idSala) {
    _idSala = idSala;
}

const char* Sala::GetNombreSala() const {
    return _nombreSala;
}

void Sala::SetNombreSala(const char*  nombreSala) {
    strcpy(_nombreSala, nombreSala);
}

int Sala::GetCapacidadSala() const {
    return _capacidadSala;
}

void Sala::SetCapacidadSala(int capacidadSala) {
    _capacidadSala = capacidadSala;
}

int Sala::GetTipoSala() const {
    return _tipoSala;
}

void Sala::SetTipoSala(int tipoSala) {
    _tipoSala = tipoSala;
}

bool Sala::GetActivo() const {
    return _activo;
}

void Sala::SetActivo(bool activo) {
    _activo = activo;
}
int Sala::GetCantidadAsientosLibres(){
    int libres = 0;
    for (int i=0;i<filas;i++){
        for (int j=0;j<columnas;j++){
        if(_asientos [i][j]==0){
            libres++;
        }

        }
    }
    return libres;
}

void Sala::SetCantidadAsientosLibres() {
    int libres = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (_asientos[i][j] == 0) {
                libres++;
            }
        }
    }
    _cantidadAsientosLibres = libres;
}

//asientos

int** Sala::GetAsientos() const {
    return _asientos;
}

void Sala::SetAsientos(int** nuevosAsientos) {
    // Liberar matriz actual si existe
    if (_asientos != nullptr) {
        for (int i = 0; i < filas; i++) {
            delete[] _asientos[i];
        }
        delete[] _asientos;
    }

    // Crear nueva matriz
    _asientos = new int*[filas];
    for (int i = 0; i < filas; i++) {
        _asientos[i] = new int[columnas];
        for (int j = 0; j < columnas; j++) {
            _asientos[i][j] = nuevosAsientos[i][j]; // Copia profunda
        }
    }
}
// filas
int Sala::GetFilas() const {
    return filas;
}

void Sala::SetFilas(int f) {
    filas = f;
}
//columnas

int Sala::GetColumnas() const {
    return columnas;
}
void Sala::SetColumnas(int c) {
    columnas = c;
}
