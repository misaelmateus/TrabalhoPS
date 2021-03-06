#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "FileManager.hh"
#include "Usuario.hh"
#include "UsuarioDAO.hh"

using namespace std;

// ESTRUTURA DO DADO USUARIO
static string NOME = "nome", SOBRENOME = "sobrenome";

UsuarioDAO::UsuarioDAO(string pasta) {
  _pasta_raiz = pasta;
}

string UsuarioDAO::caminho() const { return _pasta_raiz; }

UsuarioDAO::STATUS UsuarioDAO::lerUsuario(Usuario *u) {

  // Verifica se usuario existe no sistema
  string pasta_usuario = _pasta_raiz + u->id() + "/";
  if(!file_exist(pasta_usuario))
    return UsuarioDAO::U_NAO_EXISTE;

  // Aqui assumimos que o usuario foi configurado corretamente,
  // possuindo nome e sobrenome
  ifstream fnome(pasta_usuario + NOME), fsobrenome(pasta_usuario + SOBRENOME);

  // Ler dados do usuario
  string nome, sobrenome;
  getline(fnome, nome);
  getline(fsobrenome, sobrenome);

  u->setNome(nome);
  u->setSobrenome(sobrenome);

  fnome.close(); fsobrenome.close();

  return UsuarioDAO::OK;
}

vector<Usuario> UsuarioDAO::lerTodosUsuarios() {
  // Obter lista de usuarios

  // Já foi verificado na criação do DAO que a pasta relativa a usuarios existe.
  vector<string> files = get_dir(_pasta_raiz);

  // Obter usuarios
  vector<Usuario> us;
  for(auto const f : files) {
    Usuario u(f);
    // Não é necessário verificar se usuario existe, a lista acima
    // retorna apenas usuarios existentes.
    lerUsuario(&u); us.push_back(u);
  }

  return us;
}

void UsuarioDAO::escreverUsuario(Usuario u) {
  string pasta_usuario = _pasta_raiz + u.id() + "/";

  // Se usuario não existir crie novo, senão sobreescreve.
  if(!file_exist(pasta_usuario)) { create_dir(pasta_usuario); }

  // Escreve em disco
  ofstream fnome(pasta_usuario + NOME), fsobrenome(pasta_usuario + SOBRENOME);
  fnome << u.nome(); fsobrenome << u.sobrenome();
  fnome.close(); fsobrenome.close();
}
