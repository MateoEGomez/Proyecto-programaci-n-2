#include "Fecha.h"
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

Fecha::Fecha() {
    _dia = 0;
    _mes = 0;
    _anio = 0;
    _hora = 0;
    _minuto = 0;
}

void Fecha::fechaActual(){
time_t timePtr = time( NULL);
  tm *tiempo = localtime( &timePtr );

  _dia = tiempo->tm_mday;
  _mes = tiempo->tm_mon + 1;
  _anio = tiempo->tm_year + 1900;
  _hora = tiempo->tm_hour;
  _minuto = tiempo->tm_min;


}


void Fecha::SetDia(int dia){
    _dia = dia;
}

void Fecha::SetMes(int mes){
    _mes = mes;
}

void Fecha::SetAnio(int anio){
    _anio  = anio ;
}

void Fecha::SetHora(int hora){
    _hora =hora;
}

void Fecha::SetMinuto(int minuto){
    _minuto = minuto;
}


int Fecha::GetDia(){
    return _dia;
}

int Fecha::GetMes(){
    return _mes;
}

int Fecha::GetAnio(){
    return _anio;

}

int Fecha::GetHora(){
return _hora;
}

int Fecha::GetMinuto(){
    return _minuto;
}


 void Fecha::mostrarFecha(){
    // muestra dd/mm/aaaa con ceros delante si hace falta
    cout << setw(2) << setfill('0') << _dia << "/"
         << setw(2) << setfill('0') << _mes << "/"
         << _anio;
}

void Fecha::mostrarHora(){
    // muestra hh:mm con dos dígitos
    cout << setw(2) << setfill('0') << _hora << ":"
         << setw(2) << setfill('0') << _minuto;
}




