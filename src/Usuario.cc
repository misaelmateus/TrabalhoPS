#include <string>

#include "Usuario.hh"

using std::string;

Usuario::Usuario(string id) {
  _id = id;
}

Usuario::Usuario(string id, string nome, string sobrenome) {
  _id = id; _nome = nome; _sobrenome = sobrenome;
}

void Usuario::setID(string id) {
  _id = id;
}

void Usuario::setNome(string nome) {
  _nome = nome;
}

void Usuario::setSobrenome(string sobrenome) {
  _sobrenome = sobrenome;
}

string Usuario::id() const { return _id; }
string Usuario::nome() const { return _nome; }
string Usuario::sobrenome() const { return _sobrenome; }
