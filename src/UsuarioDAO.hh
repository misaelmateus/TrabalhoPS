#ifndef _USUARIO_DAO_HH_
#define _USUARIO_DAO_HH_

#include <string>
#include <vector>

#include "Usuario.hh"

class UsuarioDAO {
private:
  std::string _pasta_raiz;

public:
  enum STATUS { OK, U_NAO_EXISTE };

  UsuarioDAO(std::string pasta);
  std::string caminho() const;
  STATUS lerUsuario(Usuario *u);
  std::vector<Usuario> lerTodosUsuarios();
  void escreverUsuario(Usuario u);
};

#endif
