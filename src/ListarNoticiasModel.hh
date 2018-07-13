#ifndef _LISTARNOTICIASMODEL_HH_
#define _NOTICIA_DAO_HH_
#include<vector>
#include "Noticia.hh"
class ListarNoticiasModel {
private:
  std::vector<Noticia> noticias;

public:
  ListarNoticiasModel(std::vector<Noticia> & );
  void updateNoticiasModel(std::vector<Noticia> & );
  std::vector<Noticia> getNoticias(int , int );
  int noticiasSize();
};

#endif
