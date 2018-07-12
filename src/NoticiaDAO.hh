#ifndef _NOTICIA_DAO_HH_
#define _NOTICIA_DAO_HH_

#include <string>
#include <vector>

#include "Noticia.hh"

// Objeto responsável por interagir com a persistência de Notícia.
// Para utilizar deve-se chamar o construtor com o caminho do diretório
// de usuários. Recomendado utilização com DaoManager.

// O DAO espera uma organização lógica dos subdiretórios. Da seguinte forma:
// noticia/ -- pasta raiz
//  L n1/ -- noticia1 (n1 id da noticia)
//  |  L autor
//  |  L resumo
//  |  L texto
//  |  L titulo
//  L n2/

class NoticiaDAO {
private:
  std::string _pasta_raiz;

public:
  enum STATUS { OK, N_NAO_EXISTE };

  // Pasta indica localização do subdiretório de notícias. Recomanda-se utilizar o DaoManager
  // para instanciar uma NoticiaDAO.
  NoticiaDAO(std::string pasta);

  // Retorna caminho raiz de notícias.
  std::string caminho() const;

  // Le nova notícia. n deve conter no mínimo id da notícia
  // a ser lido. Caso notícia seja encontrado será salvo em n,
  // se não for encontrado retorna STATUS de erro.
  STATUS lerNoticia(Noticia *n);

  // Escreve notícia em disco.
  void escreverNoticia(Noticia n);

  // Apagar notícia de disco;
  void apagarNoticia(Noticia n);

  // Retorna todas as notícias em disco.
  std::vector<Noticia> lerTodasNoticias();
};

#endif
