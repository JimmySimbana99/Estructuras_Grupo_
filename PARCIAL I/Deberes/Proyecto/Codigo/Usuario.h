#include <iostream>


using namespace std;

class Usuario
{
private:
    string usuario;
    string password;
public:
    Usuario() = default;
    Usuario(string _usuario, string _password);

    string getUsuario();
    void setUsuario(string _usuario);

    string getPassword();
    void setPassword(string _password);
};
