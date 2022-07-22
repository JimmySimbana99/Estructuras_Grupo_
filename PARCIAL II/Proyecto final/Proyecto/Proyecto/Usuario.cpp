#include "Usuario.h"

Usuario::Usuario(string _usuario, string _password) {
    this->usuario = _usuario;
    this->password = _password;
}


string Usuario::getUsuario() {
    return usuario;
}
void Usuario::setUsuario(string _usuario) {
    this->usuario = _usuario;
}

string Usuario::getPassword() {
    return password;
}
void Usuario::setPassword(string _password) {
    this->password = _password;
}