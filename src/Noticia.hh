#ifndef _NOTICIA_HH_
#define _NOTICIA_HH_

#include <string>

// Classe para representar notícias.
// Ao requisitor autor da notícia, função retorna id do usuario.

class Noticia {
private:
  unsigned int _data;
  std::string _resumo;
  std::string _titulo;
  std::string _texto;
  std::string _id;
  std::string _autor;           // id do autor.

public:
  Noticia(std::string id);

  void setResumo(std::string resumo);
  void setTitulo(std::string titulo);
  void setTexto(std::string texto);
  void setAutor(std::string autor);
  void setData(unsigned int data);

  std::string resumo() const;
  std::string titulo() const;
  std::string texto() const;
  std::string id() const;
  std::string autor() const;
  unsigned int data() const;
};

#endif
