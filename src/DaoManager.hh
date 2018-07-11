#ifndef _DAO_MANAGER_HH_
#define _DAO_MANAGER_HH_

#include "UsuarioDAO.hh"
// #include "CredencialDAO.hh"

class DaoManager {
private:
  std::string _db;
  UsuarioDAO *_uDAO;
  // CredencialDAO _cDAO;

public:
  DaoManager(std::string db);
  ~DaoManager();

  std::string caminho() const;
  UsuarioDAO getUsuarioDAO();
};

#endif
