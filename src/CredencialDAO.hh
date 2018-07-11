#ifndef _CREDENCIAL_DAO_HH_
#define _CREDENCIAL_DAO_HH_

#include <string>

#include "Credencial.hh"

class CredencialDAO {
private:
  std::string _pasta_raiz;

public:
  CredencialDAO(std::string pasta);
  std::string caminho() const;
  void lerCredencial(Credencial *c);
};

#endif
