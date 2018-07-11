#include <string>

#include "DaoManager.hh"
#include "UsuarioDAO.hh"

using namespace std;

DaoManager::DaoManager(string db) {
  _uDAO = NULL;
  _db = db + "/";
}

DaoManager::~DaoManager() {
  if(_uDAO != NULL) { delete _uDAO; _uDAO = NULL; }
}

string DaoManager::caminho() const {
  return _db;
}

UsuarioDAO DaoManager::getUsuarioDAO() {
  if(_uDAO == NULL)
    _uDAO = new UsuarioDAO(_db + "usuario/");
  return *_uDAO;
}
