#include <string>

#include "DaoManager.hh"
#include "UsuarioDAO.hh"

using namespace std;

DaoManager::DaoManager(string db) {
  _uDAO = NULL; _cDAO = NULL; _nDAO = NULL;
  _db = db + "/";
}

DaoManager::~DaoManager() {
  if(_uDAO != NULL) { delete _uDAO; _uDAO = NULL; }
  if(_cDAO != NULL) { delete _cDAO; _cDAO = NULL; }
  if(_nDAO != NULL) { delete _nDAO; _nDAO = NULL; }
}

string DaoManager::caminho() const {
  return _db;
}

UsuarioDAO DaoManager::getUsuarioDAO() {
  if(_uDAO == NULL)
    _uDAO = new UsuarioDAO(_db + "usuario/");
  return *_uDAO;
}

CredencialDAO DaoManager::getCredencialDAO() {
  if(_cDAO == NULL)
    _cDAO = new CredencialDAO(_db + "credencial/");
  return *_cDAO;
}

NoticiaDAO DaoManager::getNoticiaDAO() {
  if(_nDAO == NULL)
    _nDAO = new NoticiaDAO(_db + "noticia/");
  return *_nDAO;
}
