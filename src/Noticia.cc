#include <iostream>
#include <string>

using namespace std;

#include "Noticia.hh"

Noticia::Noticia(string id) { _id = id; }

void Noticia::setResumo(string resumo) { _resumo = resumo; }
void Noticia::setTitulo(string titulo) { _titulo = titulo; }
void Noticia::setTexto(string texto)   { _texto  = texto;  }
void Noticia::setAutor(string autor)   { _autor  = autor;  }
void Noticia::setData(string data)     { _data   = data;   }

string Noticia::resumo() const { return _resumo; }
string Noticia::titulo() const { return _titulo; }
string Noticia::texto() const  { return _texto;  }
string Noticia::id() const     { return _id;     }
string Noticia::autor() const  { return _autor;  }
string Noticia::data() const   { return _data;   }
string Noticia::dataConvertida(){
	std::string ans = "";
	ans.append(_data.begin()+8, _data.begin()+10);
	ans += "/";
	ans.append(_data.begin()+5, _data.begin()+8);
	ans.append(_data.begin(), _data.begin()+4);
	ans.append(_data.begin()+10, _data.end());

	return ans;
}