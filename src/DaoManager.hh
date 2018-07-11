#ifndef _DAO_MANAGER_HH_
#define _DAO_MANAGER_HH_

#include "UsuarioDAO.hh"
#include "CredencialDAO.hh"
#include "NoticiaDAO.hh"

class DaoManager {
private:
  std::string _db;
  UsuarioDAO *_uDAO;
  CredencialDAO *_cDAO;
  NoticiaDAO *_nDAO;

public:
  DaoManager(std::string db);
  ~DaoManager();

  std::string caminho() const;
  UsuarioDAO getUsuarioDAO();
  CredencialDAO getCredencialDAO();
  NoticiaDAO getNoticiaDAO();
};

#endif
