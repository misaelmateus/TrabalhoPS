#include <string>

#include "Credencial.hh"

using std::string;

Credencial::Credencial(string usuario) {
  _usuario = usuario;
  _vazia = true;
}

void Credencial::setSenha(string senha) {
  _senha = senha;
  _vazia = false;
}

void Credencial::setVazia() {
  _vazia = true;
}

bool Credencial::verificar(string senha) const {
  // Se a credencial não estiver vazia e as senhas checarem
  return !_vazia && (senha == _senha);
}

string Credencial::usuario() const {
  return _usuario;
}
