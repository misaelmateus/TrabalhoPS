#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "FileManager.hh"
#include "NoticiaDAO.hh"

using namespace std;

// ESTRUTURA BANCO DE DADOS NOTICIA
static string RESUMO = "resumo",
  TITULO = "titulo",
  TEXTO = "texto",
  AUTOR = "autor";

NoticiaDAO::NoticiaDAO(string pasta) {
  _pasta_raiz = pasta;
}

string  NoticiaDAO::caminho() const { return _pasta_raiz; }

NoticiaDAO::STATUS NoticiaDAO::lerNoticia(Noticia *n) {
  // Verifica se a noticia existe
  string pasta_noticia = _pasta_raiz + n->id() + "/";
  if(!file_exist(pasta_noticia))
    return NoticiaDAO::N_NAO_EXISTE;

  ifstream fresumo(pasta_noticia + RESUMO), ftitulo(pasta_noticia + TITULO),
    fautor(pasta_noticia + AUTOR), ftexto(pasta_noticia + TEXTO);

  string resumo, titulo, texto, autor;
  getline(fresumo, resumo); getline(ftitulo, titulo);
  getline(ftexto, texto); getline(fautor, autor);

  n->setResumo(resumo); n->setTitulo(titulo);
  n->setAutor(autor); n->setTexto(texto);

  fresumo.close(); ftitulo.close(); fautor.close(); ftexto.close();

  return NoticiaDAO::OK;
}

vector<Noticia> NoticiaDAO::lerTodasNoticias() {
  vector<string> files = get_dir(_pasta_raiz);

  vector<Noticia> ns;
  for(auto const f : files) {
    Noticia n(f);
    lerNoticia(&n); ns.push_back(n);
  }

  return ns;
}

void NoticiaDAO::escreverNoticia(Noticia n) {
  string pasta_noticia = _pasta_raiz + n.id() + "/";

  // Se notícioa não existir criar uma nova pasta
  if(!file_exist(pasta_noticia)) { create_dir(pasta_noticia); }

  // Escrever notícia.
  ofstream fresumo(pasta_noticia + RESUMO), ftitulo(pasta_noticia + TITULO),
    ftexto(pasta_noticia + TEXTO), fautor(pasta_noticia + AUTOR);
  fresumo << n.resumo(); ftitulo << n.titulo();
  ftexto << n.texto(); fautor << n.autor();

  fresumo.close(); ftitulo.close(); ftexto.close(); fautor.close();
}
