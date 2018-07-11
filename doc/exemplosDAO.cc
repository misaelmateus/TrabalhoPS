// Exemplos de uso DAO.

#include "DaoManager.hh"

int main(void) {

  // DaoManager gerência acessos a disco. database é a raiz do banco de dados.
  DaoManager manager("database");

  // Obtem DAO especifico para cada objeto que deseja interação com disco.
  UsuarioDAO uD = manager.getUsuarioDAO();
  CredencialDAO cD = manager.getCredencialDAO();
  NoticiaDAO nD = manager.getNoticiaDAO();

  // Ler usuario com id em disco.
  Usuario u("id");
  if(uD.lerUsuario(&u) != UsuarioDAO::OK) {
    // usuario não existe
  }

  // Alteração de dado
  u.setNome("TESTE");

  // Persistência em disco
  uD.escreverUsuario(u);

  return 0;
}
