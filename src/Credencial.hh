#ifndef _CREDENCIAL_HH_
#define _CREDENCIAL_HH_

#include <string>

class Credencial {
private:
  std::string _usuario;
  std::string _senha;
  bool _vazia;

  friend class CredencialDAO;
  void setSenha(std::string senha);
  void setVazia();

public:
  Credencial(std::string usuario);
  bool verificar(std::string senha) const;
  std::string usuario() const;
};

#endif
