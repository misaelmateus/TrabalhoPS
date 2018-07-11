#ifndef _CREDENCIAL_HH_
#define _CREDENCIAL_HH_

#include <string>

// Classe responsável por gerenciar credênciais.
// Único objeto capaz de criar, devidamente, uma Credencial é
// o CredencialDAO. As únicas rotinas disponíveis são de verificação.

class Credencial {
private:
  std::string _usuario;
  std::string _senha;
  bool _vazia;

// CredencialDAO gerência leitura e escrita de credenciais em disco.
  friend class CredencialDAO;

// Atualiza senha da credêncial.
  void setSenha(std::string senha);

  void setVazia();

public:

// Toda credêncial é criada apenas com id do usuário. Para obter a senha
// deve-se utilizar o CredencialDAO.
  Credencial(std::string usuario);

// Verifica se a senha disponibilizada pelo usuário e a senha salva em disco
// são iguais. Se usuário não existir no sistema verificar retorna falso.
  bool verificar(std::string senha) const;

  std::string usuario() const;
};

#endif
