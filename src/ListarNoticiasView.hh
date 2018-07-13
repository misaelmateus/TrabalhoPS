#ifndef _LISTARNOTICIASVIEW_HH_
#define _LISTARNOTICIASVIEW_HH_
#include "Noticia.hh"
#include "ListarNoticiasView.hh"
#include <vector>

class ListarNoticiasView {

	public:
		ListarNoticiasView();
		std::string ShowView(std::vector<Noticia> , int ini, int fim);

};

#endif 
