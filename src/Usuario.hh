#ifndef _USUARIO_HH_
#define _USUARIO_HH_

#include <string>

class Usuario {
private:
  std::string _id;
  std::string _nome;
  std::string _sobrenome;

  friend class UsuarioDAO;

  void setID(std::string id);
  void setNome(std::string nome);
  void setSobrenome(std::string sobrenome);

public:
  Usuario() = default;
  std::string nomeCompleto() const;
};

#endif
