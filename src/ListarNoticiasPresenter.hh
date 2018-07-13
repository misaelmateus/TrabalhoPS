#ifndef _LISTARNOTICIASPRESENTER_HH_
#define _LISTARNOTICIASPRESENTER_HH_
#include "ListarNoticiasView.hh"


class PesquisaView {
	private:
		ListarNoticiasView* listarNoticiasView;
		vector<Noticias> &noticias;
	public:
		ListarNoticiasPresenter();
		int run();

};

#endif 
