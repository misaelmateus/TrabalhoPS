#include <string>

#include "Usuario.hh"

using std::string;

Usuario::Usuario(string id) {
  _id = id;
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

string Usuario::id() const {
  return _id;
}

string Usuario::nomeCompleto() const {
  return _nome + " " + _sobrenome;
}
