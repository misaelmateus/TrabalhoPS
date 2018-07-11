#include <string>

#include "Credencial.hh"
#include "CredencialDAO.hh"
#include "DaoManager.hh"

int main(void) {

  // Inicia DaoManager para obter credencial do banco de dados.
  DaoManager manager("database");

  // Obtem DAO de credenciais
  CredencialDAO cD = manager.getCredencialDAO();

  // Obtem credencial salva no banco de dados do usuario id;
  Credencial db("id");

  // Leitura da senha do usuario
  string senha;
  if(db.verificar(senha))
    // Senha correta
  else
    // Senha incorreta

  return 0;
}
