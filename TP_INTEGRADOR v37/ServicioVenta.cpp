#include <iostream>
#include <cstring>
#include "rlutil.h"
#include "Sala.h"
#include "ServicioVenta.h"
#include <cstdio>

using namespace std;


bool ServicioVenta::crearVenta(Venta v) {
    FILE* archivo = fopen("Ventas.dat", "ab");
    if (archivo == nullptr) return false;

    // --- Parte fija (sin puntero dinámico) ---
    int idVenta          = v.GetIdVenta();
    int idCliente        = v.GetIdCliente();
    int idFuncion        = v.GetIdFuncion();
    int cantidadEntradas = v.GetCantidadEntradas();
    int idEmpleado       = v.GetIdEmpleado();
    float precio         = v.GetPrecio();
    Fecha fecha          = v.Getfecha();

    fwrite(&idVenta,          sizeof(int),   1, archivo);
    fwrite(&idCliente,        sizeof(int),   1, archivo);
    fwrite(&idFuncion,        sizeof(int),   1, archivo);
    fwrite(&cantidadEntradas, sizeof(int),   1, archivo);
    fwrite(&idEmpleado,       sizeof(int),   1, archivo);
    fwrite(&precio,           sizeof(float), 1, archivo);
    fwrite(&fecha,            sizeof(Fecha), 1, archivo);

    // --- Parte dinámica: vector de asientos ---
    int cant = v.GetCantidadEntradas();
    if (cant > 0 && v.GetNumeroAsiento() != nullptr) {
        fwrite(v.GetNumeroAsiento(), sizeof(int), cant, archivo);
    }

    fclose(archivo);
    return true;
}



int ServicioVenta::contadorVentas()
{
    FILE* archivo = fopen("Ventas.dat", "rb");
    if (archivo == nullptr) return 0;


    Venta ven;
    int cont=0;

    while( fread(&ven, sizeof(Venta) - sizeof(int*), 1,archivo) ==1 )
    {

        cont++;
        int cant = ven.GetCantidadEntradas() ;

        if (cant>0)
        {
            if (fseek(archivo, sizeof(int)* cant, SEEK_CUR)!=0)break;
        }
    }
    fclose(archivo);
    return cont;


}



Venta ServicioVenta::buscarPosicionVenta(int pos) {
    Venta ven;

    FILE* archivo = fopen("Ventas.dat", "rb");
    if (archivo == nullptr) return ven;

    int actual = 0;

    // leer parte fija de la clase (sin el puntero dinámico)
    while (fread(&ven, sizeof(Venta) - sizeof(int*), 1, archivo) == 1) {
        int cant = ven.GetCantidadEntradas();

        // si tiene asientos dinámicos, leerlos
        if (cant > 0) {
            ven.SetNumeroAsiento(cant);
            fread(ven.GetNumeroAsiento(), sizeof(int), cant, archivo);
        } else {
            ven.SetNumeroAsiento(0);
        }

        // si es la posición buscada, devolver la venta
        if (actual == pos) {
            fclose(archivo);
            return ven;
        }

        // liberar antes de pasar al siguiente registro
        if (ven.GetNumeroAsiento() != nullptr)
            ven.SetNumeroAsiento(0);

        actual++;
    }

    fclose(archivo);
    return ven;  // si no se encontró, devuelve un objeto vacío
}




 bool ServicioVenta::listarVentas() {
    FILE* archivo = fopen("Ventas.dat", "rb");
    if (archivo == nullptr) return false;

    Venta v;
    int index = 0;

    while (true) {
        int idVenta, idCliente, idFuncion, cantidadEntradas, idEmpleado;
        float precio;
        Fecha fecha;

        // --- Leer parte fija ---
        if (fread(&idVenta, sizeof(int), 1, archivo) != 1) break;
        fread(&idCliente, sizeof(int), 1, archivo);
        fread(&idFuncion, sizeof(int), 1, archivo);
        fread(&cantidadEntradas, sizeof(int), 1, archivo);
        fread(&idEmpleado, sizeof(int), 1, archivo);
        fread(&precio, sizeof(float), 1, archivo);
        fread(&fecha, sizeof(Fecha), 1, archivo);

        // --- Cargar los datos leídos en el objeto Venta ---
        v.SetIdVenta(idVenta);
        v.SetIdCliente(idCliente);
        v.SetIdFuncion(idFuncion);
        v.SetCantidadEntradas(cantidadEntradas);
        v.SetIdEmpleado(idEmpleado);
        v.SetPrecio(precio);
        v.Setfecha(fecha);

        // parte dinámica
        if (cantidadEntradas > 0) {
            v.SetNumeroAsiento(cantidadEntradas);
            fread(v.GetNumeroAsiento(), sizeof(int), cantidadEntradas, archivo);
        } else {
            v.SetNumeroAsiento(0);
        }

        // --- Mostrar datos ---
        cout << "-------------------------------\n";
        cout << "Venta N: " << v.GetIdVenta() << endl;
        cout << "Cliente ID: " << v.GetIdCliente() << endl;
        cout << "Empleado ID: " << v.GetIdEmpleado() << endl;
        cout << "Funcion ID: " << v.GetIdFuncion() << endl;

        cout << "Fecha: ";
        v.Getfecha().mostrarFecha();
        cout << " ";
        v.Getfecha().mostrarHora();
        cout << endl;

        cout << "Entradas: " << v.GetCantidadEntradas() << endl;
        cout << "Precio unitario: $" << v.GetPrecio() << endl;
        cout << "Total: $" << (v.GetPrecio() * v.GetCantidadEntradas()) << endl;

        if (v.GetCantidadEntradas() > 0) {
            cout << "Asientos: ";
            for (int i = 0; i < v.GetCantidadEntradas(); i++) {
                cout << "[" << v.GetNumeroAsiento()[i] << "] ";
            }
            cout << endl;
        }

        // --- Liberar vector antes de pasar a la siguiente venta ---
        v.SetNumeroAsiento(0);

        index++;
    }

    fclose(archivo);
    return (index > 0);
}




bool ServicioVenta::asignarAsientos(Funcion funcion, Venta venta) {
    int* disponibles = funcion.GetAsientosDisponibles();
    int capacidad = funcion.GetcantidadAsientos();

    if (disponibles == nullptr || capacidad == 0) {
        cout << "La función no tiene asientos disponibles.\n";
        return false;
    }

    int* asientosVenta = venta.GetNumeroAsiento();
    int cantEntradas = venta.GetCantidadEntradas();

    for (int i = 0; i < cantEntradas; i++) {
        int asiento = asientosVenta[i];

        // Validar rango
        if (asiento < 0 || asiento >= capacidad) {
            cout << "Asiento inválido: " << asiento << endl;
            return false;
        }

        // Verificar ocupación
        if (disponibles[asiento] == 1) {
            cout << "El asiento " << asiento << " ya está ocupado.\n";
            return false;
        }

        // Marcar como ocupado
        disponibles[asiento] = 1;
    }

    return true;
}














 /*
float ServicioVenta::CalcularPrecioTotal(const Sala& sala) const {
   float base = _venta.GetPrecio();

   switch (sala.GetTipoSala()) {
       case 1: base *= 1.0; break;   // estándar
       case 2: base *= 1.2; break;   // 3D
       case 3: base *= 1.5; break;   // 4D
   }

   return base * _venta.GetCantidadEntradas();

}



   */



