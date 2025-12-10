#include <iostream>
#include <cstring>
#include "Sala.h"
using namespace std;

const char* Sala::listaTipoSala[3] = {"2D", "3D", "4D"};

int Sala::GetIdSala() {
    return _idSala;
}

void Sala::SetIdSala(int idSala) {
    _idSala = idSala;
}

const char* Sala::GetNombreSala() {
    return _nombreSala;
}

void Sala::SetNombreSala(const char* nombreSala) {
    strncpy(_nombreSala, nombreSala, sizeof(_nombreSala) - 1);
    _nombreSala[sizeof(_nombreSala) - 1] = '\0';
}

bool Sala::GetActivo() {
    return _activo;
}

void Sala::SetActivo(bool activo) {
    _activo = activo;
}


const char* Sala::GetTipoSala() {
    return _tipoSala;
}

void Sala::SetTipoSala(int tipoSala) {
    strncpy(_tipoSala, Sala::listaTipoSala[tipoSala], sizeof(_tipoSala) - 1);
    _tipoSala[sizeof(_tipoSala) - 1] = '\0';
}

int Sala::GetCapacidadSala() {
    return _capacidadSala;
}

void Sala::SetCapacidadSala(int capacidadSala) {
    _capacidadSala = capacidadSala;
}
