#ifndef _LISTARNOTICIASPRESENTER_HH_
#define _LISTARNOTICIASPRESENTER_HH_
#include "Noticia.hh"
#include "ListarNoticiasView.hh"
#include "ListarNoticiasModel.hh"
class ListarNoticiasPresenter {
	private:
		ListarNoticiasView listarNoticiasView;
		ListarNoticiasModel *model;
	public:
		ListarNoticiasPresenter(std::vector<Noticia> &);
		int run();

};

#endif 
