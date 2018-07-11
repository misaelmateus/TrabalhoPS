#ifndef _USUARIO_HH_
#define _USUARIO_HH_

#include <string>

class Usuario {
private:
  std::string _id;
  std::string _nome;
  std::string _sobrenome;

public:
  Usuario() = default;
  Usuario(std::string id);
  Usuario(std::string id, std::string nome, std::string sobrenome);

  std::string id() const;
  std::string nome() const;
  std::string sobrenome() const;

  void setNome(std::string nome);
  void setSobrenome(std::string sobrenome);
};

#endif
