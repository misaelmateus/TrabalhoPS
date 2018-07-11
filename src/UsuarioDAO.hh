#ifndef _USUARIO_DAO_HH_
#define _USUARIO_DAO_HH_

#include <string>
#include <vector>

#include "Usuario.hh"

// Objeto responsável por interagir com a persistência de Usuarios.
// Para utilizar deve-se chamar o construtor com o caminho do diretório
// de usuários. Recomendado utilização com DaoManager.

// O DAO espera uma organização lógica dos subdiretórios. Da seguinte forma:
// usuario/ -- pasta raiz
//  L u1/ -- usuario1 (u1 id do usuário)
//  |  L nome -- arquivo que contem nome do usuário
//  |  L sobrenome -- arquivo contem sobrenome do usuário.
//  L u2/

class UsuarioDAO {
private:
  std::string _pasta_raiz;

public:
  enum STATUS { OK, U_NAO_EXISTE };

  // pasta indica localização do diretório de usuários.
  UsuarioDAO(std::string pasta);

  // Retorna caminho raiz de usuários.
  std::string caminho() const;

  // Le novo usuário. u deve conter no mínimo id do usuário
  // a ser lido. Caso usuario seja encontrado será salvo em u,
  // se não for encontrado retorna STATUS de erro.
  STATUS lerUsuario(Usuario *u);

  // Retorna todos os usuários no banco de dados.
  std::vector<Usuario> lerTodosUsuarios();

  // Escreve usuário u em disco.
  void escreverUsuario(Usuario u);
};

#endif
