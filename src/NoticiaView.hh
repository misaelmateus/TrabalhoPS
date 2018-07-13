#ifndef _NOTICIAVIEW_HH_
#define _NOTICIAVIEW_HH_

#include <string>
#include "Noticia.hh"

// Classe para representar notícias.
// Ao requisitor autor da notícia, função retorna id do usuario.

class NoticiaView {
private:
  Noticia *noticia;
public:
  NoticiaView(Noticia &);
  void ShowView();
};

#endif
