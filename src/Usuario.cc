#include <string>

#include "Usuario.hh"

using std::string;

void Usuario::setID(string id) {
  _id = id;
}

void Usuario::setNome(string nome) {
  _nome = nome;
}

void Usuario::setSobrenome(string sobrenome) {
  _sobrenome = sobrenome;
}

string Usuario::nomeCompleto() const {
  return _nome + " " + _sobrenome;
}
