
#pragma once

class Fecha {


    public:

        Fecha();

        void fechaActual();

        void mostrarFecha();
        void mostrarHora();

        void SetAnio(int);
        void SetMes(int);
        void SetDia(int);
        void SetHora(int);
        void SetMinuto(int);


        int GetAnio();
        int GetMes();
        int GetDia();
        int GetHora();
        int GetMinuto();


    private:
        int _hora,_minuto;
        int _dia, _mes;
        int _anio;




};
