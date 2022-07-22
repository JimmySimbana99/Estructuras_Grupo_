#pragma once
#include "Archivo.h"
#include "Usuario.h"
#include "Arbol.h"
#include "Imagen.h"
#include <conio.h>
#include <Windows.h>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <string>
#include <chrono>
#include <direct.h>
#include "Validar.h"


#define ENTER 13
#define BACKSPACE 8

class Operacion
{
public:
	Operacion() = default;
	void iniciarSesion();
	vector<Usuario> obtenerDatosUsuario();
    //Operacoones de nuevo arbol
    string crearArbol();
    void eliminarArbol();
    bool buscarArbol(string nombre);
    void generarCopia(string nombre);
    void restaurarCopia(string nombre);

    //Operaciones de arbol
    void insertarEnArbol(string nombre);
    void buscarEnArbol();
    void eliminarDeArbol(string nombre);
    void graficarArbol();
    void MostrarRecorridos();

    //Operaciones de Imagen
    void mostrarImagen(string nombre);

    //Operaciones Backup
    void generarBackup(string nombre);
    void generarPuntoRestauracion();
    void generarPDF(string BCK, string nombre, vector<string> dts);


	

private:
    Archivo archivo;
    Arbol arbol;
    Imagen imagen;
    int numero;
    string ruta = "D:\\ProyectoTerminado2PEstruturas\\Proyecto\\Proyecto";
};

vector<Usuario> Operacion::obtenerDatosUsuario()
{

    vector<string> datos = archivo.leer(ruta, "DatosUsuario");
    vector<Usuario> usuarios;
    string usuario, password;

    for (int i = 0; i < datos.size(); i = i + 2)
    {
        usuario = datos[i];
        password = datos[i + 1];

        Usuario user(usuario, password);
        usuarios.push_back(user);
    }
    return usuarios;
}

string Operacion::crearArbol() {
    
    string nombre;
    cout << "\n Nombre del arbol: ";
    cin >> nombre;
    bool encontrado = false;
    vector<string> arbs = archivo.leer(ruta,"ListaArboles");


    if (arbs.size() > 0) {
        for (int i = 0; i < arbs.size() && encontrado == false; i++)
        {   
            //cout << arbs[i] << "\t";
            if (arbs[i] == nombre)
            {
                encontrado = true;
            }
        }

        if (!encontrado)
        {
            arbol.borrarArbol();
            system((string("mkdir") + " " + nombre).c_str());
            archivo.agregar(ruta, "ListaArboles", nombre);
            archivo.agregar(ruta, "BCkList", nombre);
            generarCopia(nombre);
        }
        else {
            nombre = "Nombre de arbol ya creado";
        }
    }else{
        arbol.borrarArbol();
        system((string("mkdir") + " " + nombre).c_str());
        archivo.agregar(ruta, "ListaArboles", nombre);
        archivo.agregar(ruta, "BCkList", nombre);
        generarCopia(nombre);
    }



    return nombre;

}

void Operacion::eliminarArbol() {
    string nombre;
    cout << "\n Nombre del arbol a eliminar: ";
    cin >> nombre;
    bool encontrado = false;
    vector<string> arbs = archivo.leer(ruta, "ListaArboles");

    if (arbs.size() > 0) {
        for (int i = 0; i < arbs.size() && encontrado == false; i++)
        {
            //cout << arbs[i] << "\t";
            if (arbs[i] == nombre)
            {
                encontrado = true;
            }
        }

        if (encontrado)
        {
            string eliminar = "rmdir " + ruta + "\\" + nombre + " /s /q";
            archivo.eliminar(ruta, "ListaArboles", nombre);
            system(eliminar.c_str());

        }
        else {
            cout << "\nArbol no existent" << endl;
        }
    }
    else {
        cout << "\nNo existen registros" <<endl;
    }


}

bool Operacion::buscarArbol(string nombre) {
    
    bool encontrado = false;


   
    if (archivo.buscarArchivo(nombre,ruta))
    {
        //cout << "\n Archivo encontrado \n";
        encontrado = true;
        vector<string> datos = archivo.leer(ruta + "\\" + nombre, nombre);
        arbol.borrarArbol();
        for (int i = 0; i < datos.size(); i++)
        {
            cout << "\t" << datos[i];
            int n = stoi(datos[i]);
            arbol.insertar(n);
        }
        arbol.generarGrafico(nombre);
        system("pause");
    }


    return encontrado;
}

void Operacion::generarCopia(string nombre) {

    string rutaDir = ruta + "\\" + nombre;
    string destino = ruta + "\\" + "restore";
    destino = destino + "\\" + nombre;
   
    string eliminar = "rmdir " + ruta + "\\" + "restore" + "\\" + nombre + " /s /q";
    string existe = "if test -d " + ruta + "\\" + "restore" + "\\" + nombre;
    _mkdir(destino.c_str());
    system(eliminar.c_str());
    _mkdir(destino.c_str());


    string cm;
    cm = "xcopy " + rutaDir + " " + destino + " /H /S";
    system(cm.c_str());

}

void Operacion::restaurarCopia(string nombre) {
    string rutaDir =  ruta + "\\" + "restore" + "\\" + nombre;
    string destino = ruta;
    destino = destino + "\\" + nombre;
    string eliminar = "rmdir " + ruta + "\\" + nombre + " /s /q";
    _mkdir(destino.c_str());
    system(eliminar.c_str());
    _mkdir(destino.c_str());


    string cm;
    cm = "xcopy " + rutaDir + " " + destino + " /H /S";
    system(cm.c_str());
    archivo.agregar(ruta, "ListaArboles", nombre);
}


void Operacion::iniciarSesion()
{
    vector<Usuario> us = obtenerDatosUsuario();
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
        caracter = _getch();

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

            caracter = _getch();
        }

        for(Usuario u: us)
        {
            if (u.getUsuario() == usuario && u.getPassword() == password) {
                ingresa = true;

            }
        }
        if (!ingresa)
        {
            cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
            cin.get();
        }

    } while (ingresa == false);
}


void Operacion::insertarEnArbol(string nombre) {
    
    
    string numeroS = validarNumeros("\n\nIngrese el valor a insertar: ");
    numero = stoi(numeroS);
    fflush(stdin);
    archivo.agregar(ruta + "\\" + nombre, nombre, to_string(numero)),
    arbol.insertar(numero);
    arbol.generarGrafico(nombre);
    generarCopia(nombre);
}

void Operacion::buscarEnArbol() {
   
    
    string numeroS = validarNumeros("\n\nIngrese el valor a insertar: ");
    numero = stoi(numeroS);
    if (!arbol.buscar(arbol.getRaiz(), numero))
    {
        cout << "\nEl valor fue econtrado: " << numero << endl;
    }
    else {
        cout << "\nEl no valor fue econtrado: " << endl;
    }
   
}

void Operacion::eliminarDeArbol(string nombre){
 
    string numeroS = validarNumeros("\n\nIngrese el valor a insertar: ");
    numero = stoi(numeroS);

    if (!arbol.buscar(arbol.getRaiz(), numero))
    {
        cout << "\nEl valor fue econtrado y eliminado: " << numero << endl;
        arbol.eliminar(numero);
        archivo.eliminar(ruta + "\\" + nombre, nombre,to_string(numero));
        arbol.generarGrafico(nombre);
        generarCopia(nombre);

    }
    else {
        cout << "\nEl no valor fue econtrado: " << endl;
    }

}

void Operacion::graficarArbol(){
    
    cout << "\n\n";
    arbol.mostrarArbol(arbol.getRaiz(),"",true);
   

}

void Operacion::MostrarRecorridos() {

    
    cout << "\nRecorrido en pre-Orden: ";
    arbol.preOrden(arbol.getRaiz());
    cout << "\nRecorrido en in-Orden: ";
    arbol.inOrden(arbol.getRaiz());
    cout << "\nRecorrido en post-Orden: ";
    arbol.postOrden(arbol.getRaiz());
    cout << endl;
   

}

void  Operacion::mostrarImagen(string nombre) {
    system("cls");
    if (imagen.cargarImagen(ruta + "\\" + nombre + "\\" + nombre + ".png")) {

        imagen.obtenerPixeles();

    }
    else {
        cout << "\n \tImagen no cargada" << endl;
    }
}


void Operacion::generarBackup(string nombre) {
    string nombreBCK;
    struct tm newtime;
    time_t now = time(0);
    localtime_s(&newtime, &now);

    nombreBCK = to_string(newtime.tm_year + 1900) + "/" +
            to_string(newtime.tm_mon + 1) + "/" +
            to_string(newtime.tm_wday + 17) + "/" +
            to_string(newtime.tm_hour) + "/" +
            to_string(newtime.tm_min) + "/" +
            to_string(newtime.tm_sec);



    cout << "\n nombre: " << nombreBCK;

    vector<string> dts = archivo.leer(ruta + "\\" + nombre,nombre);
    cout << "\n";
    if (dts.size() > 0) {
        generarPDF(nombreBCK, nombre, dts);
        generarCopia(nombre);
    }
    else {
        cout << "\n No hay datos ingresados";
    }


}

void Operacion::generarPuntoRestauracion() {
    string nombre;
    cout << "\n Ingrese el nombre del arbol: ";
    cin >> nombre;
    bool encontrado = false;
    bool eliminado = true;
    vector<string> la = archivo.leer(ruta, "ListaArboles");
    vector<string> lbck = archivo.leer(ruta, "BCkList");

    int n = lbck.size();

    if (n > 0)
    {
        for (int i = 0; i < lbck.size(); i++)
        {
            if (nombre == lbck[i])
            {
                encontrado = true;
                for (int i = 0; i < la.size(); i++)
                {
                    if (nombre == la[i])
                    {
                        eliminado = false;
                    }
                }
            }
        }
        if (encontrado == true && eliminado == true)
        {
            cout<< "\n Inciara la restauracion " << endl;
            restaurarCopia(nombre);
        }
        else if (!encontrado)
        {
            cout << "\n No se encuentra registros existentes " << endl;
        }
        else {
            cout << "\n Registros existente No se necesita restaurar " << endl;
        }

    }
    else {
        cout << "\n No hay archivos existente " << endl;
    }

}

void Operacion::generarPDF(string BCK,string nombre, vector<string> dts)
{
    cout << "\n";
    ostringstream html;

    html << "<html>"
        "<head><title> TEST </title></head>"
        "<base href=""C:/Users/USUARIO/Desktop/ProgramasM/Proyecto/Proyecto/RojoNegro.png"">"
        "<body>"
        "<h1>Datos de arbol: " + nombre + "</h1>"
        "<p> Datos: "
        ;
        
    for (int i = 0; i < dts.size(); i++)
    {
        html << dts[i] << "  ";
    }
    String urlImg = ruta + "\\" + nombre + "\\" + nombre + ".png";
    html<<"<p>"
        "<img src=" + urlImg + ">"
        "</body></html>";

    std::ostringstream plain;
    std::string html_filename = BCK + ".html";
    std::string pdf_filename = BCK + ".pdf";
    std::ofstream out_html(html_filename, std::ios::trunc);
    std::ofstream out_txt(BCK + ".txt", std::ios::trunc);
    out_html << html.str();
    out_txt.close();
    out_html.close();

    if (std::ifstream(pdf_filename.c_str()).good())
    {
        std::remove(pdf_filename.c_str());
    }
    system((std::string("wkhtmltopdf --enable-local-file-access") + " " + html_filename + " " + pdf_filename).c_str());
    std::cout << std::endl
        << "archivo pdf generado!";

    rename((ruta + "\\" + BCK + ".pdf").c_str(), (ruta + "\\" + nombre + "\\" + BCK + ".pdf").c_str());
    remove((ruta + "\\" + BCK + ".txt").c_str());
    remove((ruta + "\\" + BCK + ".html").c_str());
}