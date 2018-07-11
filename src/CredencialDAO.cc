#include <string>
#include <fstream>

#include "FileManager.hh"
#include "Credencial.hh"
#include "CredencialDAO.hh"

using namespace std;

// Estrutura do arquivo de credenciais
// Nome do arquivo: username do usuario
// Conteudo: senha do usuario

CredencialDAO::CredencialDAO(string pasta) {
  _pasta_raiz = pasta;
}

string CredencialDAO::caminho() const {
  return _pasta_raiz;
}

void CredencialDAO::lerCredencial(Credencial *c) {
  // Verificar se credencial existe
  string arquivo_credencial = _pasta_raiz + c->usuario();

  // Se credencial não existe negar validação
  if(!file_exist(arquivo_credencial)) {
    c->setVazia(); return;
  }

  // Se não ler senha
  ifstream fcredencial(arquivo_credencial);
  string senha; getline(fcredencial, senha);
  c->setSenha(senha);
}

void CredencialDAO::escreverCredencial(string usuario, string senha) {
  string arquivo_credencial = _pasta_raiz + usuario;

  ofstream fcredencial(arquivo_credencial);
  fcredencial << senha;

  fcredencial.close();
}
