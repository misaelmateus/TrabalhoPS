#include <iostream>
#include <string>

using namespace std;

#include "Noticia.hh"

Noticia::Noticia(string id) { _id = id; }

void Noticia::setResumo(string resumo) { _resumo = resumo; }
void Noticia::setTitulo(string titulo) { _titulo = titulo; }
void Noticia::setTexto(string texto)   { _texto  = texto;  }
void Noticia::setAutor(string autor)   { _autor  = autor;  }

string Noticia::resumo() const { return _resumo; }
string Noticia::titulo() const { return _titulo; }
string Noticia::texto() const  { return _texto;  }
string Noticia::id() const     { return _id;     }
string Noticia::autor() const  { return _autor;  }

void Noticia::completa() const {
  cout << "Autor: " << _autor << endl;
  cout << "Titulo: " << _titulo << endl;
  cout << "Resumo: " << _resumo << endl;
  cout << "Texto: " << _texto << endl;
}