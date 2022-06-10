#include <iostream>
#include "Menu.h"
#include "Operacion.h"

using namespace std;

#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3

int main(int, char **)
{

    int opc;
    Menu menu;
    Operacion op;

   op.iniciarSesion();


    do
    {
        /* code */
        opc = menu.menuPrincipal();

        switch (opc)
        {
        case 1:
            //"Registrar Vehiculo";

            op.registrarVehiculo();
            break;

        case 2:
            //"Mostrar Vehiculos";

            op.mostrarVehiculos();
            break;
        case 3:
            //"Buscar Vehiculo";

            op.buscarVehiculo();
            break;
        case 4:
            //"Agregar datos de mantenimiento de mi vehiculo";

            op.agregarMantenimiento();
            // op.obtenerDatosMantenimiento();
            // op.generarPDF();
            break;
        case 5:
            //"Salir";
            // op.mostrarVehiculos();
            op.generarReporte();
            break;
        
        case 10:
            op.cargarAyuda();
            
            break;

        default:
            break;
        }
        cout << "\n";
        system("pause");
    } while (opc != 6);
    
    
}
