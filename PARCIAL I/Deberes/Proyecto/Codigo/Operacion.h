#include <iostream>
#include <functional>
#include <string>
#include <limits>
#include "Lista.h"
#include "Vehiculo.h"
#include "Mantenimiento.h"
#include "Archivo.h"
#include "Validar.h"
// #include "Fecha.h"
#include <sstream>
#include "OperacionesFecha.cpp"

#include <cstdlib>
#include <time.h>
#include <sstream>
#include <regex>
#include <fstream>
#include "Usuario.h"

using namespace std;

#define ENTER 13
#define BACKSPACE 8

class Operacion
{
private:
    Archivo archivo;
    Lista<Vehiculo> vehiculos;
    Lista<Mantenimiento> mantenimientos;
    Lista<Usuario> usuarios;
    Validar vl;

    string convertirMayusculas(string texto);

public:
    Operacion() = default;

    void iniciarSesion();
    void obtenerDatosUsuario();
    void cargarAyuda();

    void registrarVehiculo();
    void obtenerDatosVehiculo();
    void obtenerDatosMantenimiento(string placa);
    void mostrarVehiculos();

    bool buscarVehiculo();
    Vehiculo obtenerVehiculo(string placa);
    void agregarMantenimiento();
    bool verificarVehiculo(string placa);

    void generarPDF(string nombreAr, Vehiculo actual);
    void generarReporte();
};

void Operacion::cargarAyuda(){
    system("cls");
    cout<<"\n \n \tEste es el manual de usuario";
    cout<<"Registrar Vehiculo: El sistema permitira registrar la marca, el modelo, el anio y placa\n\n";
    cout<<"Mostrar Vehiculo: El sistema mostrara el vehiculo resgistrado en un txt.\n\n";
    cout<<"Buscar el vehiculo: El sistema buscara al vehiculo mediante la placa, si la placa es eronia";
    cout<<"saldra un mensaje de error y intente de nuevo \n\n";
    cout<<"Agregar datos de mantenimiento: Para agregar un mantenimiento ingresar la placa del auto ya";
    cout<<"existente, luego saldra opciones de generar fecha(dia,mes,anio); servicio y costo\n\n";
    cout<<"Generar reporte de mantenimiento; El sistema imprimira el mantenimiento del vehiculo en un archivo pdf\n\n";
}

void Operacion::obtenerDatosUsuario()
{

    usuarios.vaciarLista();
    vector<string> datos = archivo.leer("DatosUsuario");

    string usuario, password;

    for (int i = 0; i < datos.size(); i = i + 2)
    {
        usuario = datos[i];
        password = datos[i + 1];

        Usuario user(usuario, password);
        usuarios.insertar(user);
    }
}

void Operacion::iniciarSesion()
{
    obtenerDatosUsuario();
    string usuario, password;
    int contador = 0;
    bool ingresa = false;
    do
    {
        system("cls");
        cout << "\t\t\tLOGIN DE USUARIO" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\tUsuario: ";
        getline(cin, usuario);

        char caracter;

        cout << "\tPassword: ";
        caracter = getch();

        password = "";

        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                password.push_back(caracter);
                cout << "*";
            }
            else
            {
                if (password.length() > 0)
                {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }

            caracter = getch();
        }

        usuarios.recorrer([&](Usuario us)
                          {
                           if (us.getUsuario() == usuario && us.getPassword() == password){
                                ingresa = true;
                                
                            } 
        });
        if (!ingresa)
        {
            cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
            cin.get();
        }

    } while (ingresa == false);
}

void Operacion::registrarVehiculo()
{
    obtenerDatosVehiculo();
    bool existente = false;
    string marca, modelo, placa;
    int anio;
    cout << "\n \n \tDatos del vehiculo \n";
    cout << "\n Inserte los siguientes datos del vehiculo\n";
    cout << "\n";
    marca = vl.validarLetras("Marca: ", 30, true);
    cout << "\n";
    fflush(stdin);

    modelo = vl.ingreso("Modelo:", 30, true);
    cout << "\n";
    fflush(stdin);

    bool verificador;
    do
    {
        verificador = true;
        anio = stoi(vl.validarNumeros("Anio: ", 4));
        cout << "\n";
        fflush(stdin);

        if (!(anio >= 2000 && anio <= 2022))
        {
            cout << "\n Anio fuera de rango limite \n";
            system("pause");
            verificador = false;
        }

    } while (!verificador);

    do
    {
        placa = vl.ingreso("Placa:", 10, false);
        fflush(stdin);

        if (verificarVehiculo(convertirMayusculas(placa)))
        {
            cout << "\n Placa de vehiculo ya existente\n";
            system("pause");
            // cout<<endl;
            // cout << "\e[A\r\e[0K";
        }

    } while (verificarVehiculo(convertirMayusculas(placa)));

    Vehiculo vh(marca, modelo, anio, convertirMayusculas(placa));

    archivo.agregar("DatosVehiculos", vh.to_string());
}

void Operacion::obtenerDatosVehiculo()
{

    vehiculos.vaciarLista();
    vector<string> datos = archivo.leer("DatosVehiculos");
    string marca, modelo, placa;
    int anio;

    for (int i = 0; i < datos.size(); i = i + 4)
    {
        marca = datos[i];
        modelo = datos[i + 1];
        anio = stoi(datos[i + 2]);
        placa = datos[i + 3];

        Vehiculo carro(marca, modelo, anio, placa);
        vehiculos.insertar(carro);

        // cout<<marca<<"  "<<modelo<<"  "<<anio<<"  "<<placa<<endl;
    }
}

void Operacion::obtenerDatosMantenimiento(string placa)
{
    mantenimientos.vaciarLista();
    vector<string> datos = archivo.leer("DatosMantenimiento");
    string fecha;
    string servicio;
    float costo;
    string placaAuto;

    for (int i = 0; i < datos.size(); i = i + 4)
    {
        fecha = datos[i];
        servicio = datos[i + 1];
        costo = stof(datos[i + 2]);
        placaAuto = datos[i + 3];

        if (placaAuto == placa)
        {
            Mantenimiento mt(fecha, servicio, costo, placaAuto);
            mantenimientos.insertar(mt);
        }

        // Vehiculo carro(marca, modelo, anio, placa);
        // vehiculos.insertar(carro);
    }
}

void Operacion::mostrarVehiculos()
{
    obtenerDatosVehiculo();
    cout << "\n \n \t Datos de los vehiculos \n";
    vehiculos.recorrer([](Vehiculo v1)
                       {
                           cout << "Marca: " << v1.getMarca()<<endl;
                           cout << "Modelo: " << v1.getModelo()<<endl;
                           cout << "Anio: " << v1.getAnio()<<endl;
                           cout << "Placa: " << v1.getPlaca() << "\n\n"; });
}
bool Operacion::buscarVehiculo()
{
    obtenerDatosVehiculo();
    string placa;
    bool encontrado = false;
    cout << "\n \n Ingrese la placa del vehiculo a buscar: ";
    getline(cin, placa);
    vehiculos.recorrer([&](Vehiculo v1)
                       {
                           if (v1.getPlaca() == convertirMayusculas(placa))
                           {
                                cout << "Marca: " << v1.getMarca()<<endl;
                                cout << "Modelo: " << v1.getModelo()<<endl;
                                cout << "Anio: " << v1.getAnio()<<endl;
                                cout << "Placa: " << v1.getPlaca() << "\n\n";
                                encontrado = true;
                           } });

    return encontrado;
}

Vehiculo Operacion::obtenerVehiculo(string placa)
{
    obtenerDatosVehiculo();
    Vehiculo encontrado;
    vehiculos.recorrer([&](Vehiculo v1)
                       {
                           if (v1.getPlaca() == convertirMayusculas(placa))
                           {
                                // cout << "Marca: " << v1.getMarca()<<endl;
                                // cout << "Modelo: " << v1.getModelo()<<endl;
                                // cout << "Anio: " << v1.getAnio()<<endl;
                                // cout << "Placa: " << v1.getPlaca() << "\n\n";
                                // encontrado = true;
                                encontrado = v1;
                           } });

    // if (!encontrado)
    // {
    //     cout << "\n Vehiculo no encontrado \n";
    // }
    return encontrado;
}

void Operacion::agregarMantenimiento()
{
    string placa;
    cout << "\n Ingrese el numero de placa del vehiculo: ";
    cin >> placa;

    if (!verificarVehiculo(convertirMayusculas(placa)))
    {
        cout << "\nVehiculo no registrado\n";
        system("pause");
        return;
    }

    string fecha;
    string servicio;
    float costo;

    cout << "\n \n \tDatos de mantenimeinto del vehiculo \n";
    cout << "\n Inserte los siguientes datos sobre mantenimiento\n";
    fecha = ingresarFecha();
    cout << "\n Servicio:";
    fflush(stdin);
    getline(cin, servicio);
    cout << "\n Costo:";
    cin >> costo;
    fflush(stdin);

    Mantenimiento mantenimiento(fecha, servicio, costo, convertirMayusculas(placa));
    archivo.agregar("DatosMantenimiento", mantenimiento.to_string());
}

bool Operacion::verificarVehiculo(string placa)
{

    obtenerDatosVehiculo();
    bool encontrado = false;
    vehiculos.recorrer([&](Vehiculo v1)
                       {
                           if (v1.getPlaca() == placa)
                           {
                               encontrado = true;
                           } });

    return encontrado;
}

void Operacion::generarReporte()
{
    string placa;
    cout << "\n Ingrese el numero de placa del vehiculo: ";
    cin >> placa;

    if (!verificarVehiculo(convertirMayusculas(placa)))
    {
        cout << "\nVehiculo no registrado\n";
        system("pause");
        return;
    }

    Vehiculo actual = obtenerVehiculo(convertirMayusculas(placa));

    obtenerDatosMantenimiento(convertirMayusculas(placa));

    generarPDF(convertirMayusculas(placa), actual);
}

void Operacion::generarPDF(string nombreAr, Vehiculo actual)
{

    ostringstream html;

    html << "<html>"
            "<head><title>Tabla de Tiempos (SIMULACION)</title></head>"
            "<style>"
            "table, th, td{"
            "border: 1px solid black;"
            "border-collapse: collapse;}"

            "th, td{"
            "padding: 15px;"
            "text-align: center;}"

            "</style>"

            "<body>"
            "<h1>Reporte Datos de Mantenimiento</h1>"
            "<h2>Datos vehiculo</h2>"
            "<p>Marca: " +
                actual.getMarca() + "</p>"
                                    "<p>Modelo: " +
                actual.getModelo() + "</p>"
                                     "<p>Anio: " +
                to_string(actual.getAnio()) + "</p>"
                                              "<p>Placa vehiculo: " +
                actual.getPlaca() + "</p><br>"

                                    "<table width="
                                    "100%"
                                    ">"
                                    "<thead>"
                                    "<tr>"
                                    "<th>FECHA &nbsp; &nbsp;</th>"
                                    "<th>SERVICO &nbsp; &nbsp;</th>"
                                    "<th>COSTO $ &nbsp; &nbsp;</th>"
                                    "<th>PLACA ASOCIADA &nbsp; &nbsp;</th>"
                                    "</tr>"
                                    "</thead>"

                                    "<tbody>";
    mantenimientos.recorrer([&](Mantenimiento mt)
                            { html << "<tr>"
                                      "<td>" +
                                          mt.getFecha() + "</td>"
                                                          "<td>" +
                                          mt.getServicio() + "</td>"
                                                             "<td>" +
                                          to_string(mt.getCosto()) + "</td>"
                                                                     "<td>" +
                                          mt.getplacaAuto() + "</td>"
                                                              "</tr>"; });

    html << "</tbody>"
            "</table>";

    ;

    html << "</body></html>";

    std::ostringstream plain;
    std::string html_filename = nombreAr + ".html";
    std::string pdf_filename = nombreAr + "Reporte.pdf";
    std::ofstream out_html(html_filename, std::ios::trunc);
    std::ofstream out_txt(nombreAr + ".txt", std::ios::trunc);
    out_html << html.str();
    out_txt.close();
    out_html.close();

    if (std::ifstream(pdf_filename.c_str()).good())
    {
        std::remove(pdf_filename.c_str());
    }
    system((std::string("wkhtmltopdf") + " " + html_filename + " " + pdf_filename).c_str());
    std::cout << std::endl
              << "archivo pdf generado!";
}

string Operacion::convertirMayusculas(string texto)
{
    for (int letra = 0; letra < texto.size(); ++letra)
    {

        texto[letra] = toupper(texto[letra]);
    }

    return texto;
}
