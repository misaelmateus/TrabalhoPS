#ifndef _PESQUISAPRESENTER_HH_
#define _PESQUISAPRESENTER_HH_
#include "PesquisaView.hh"

class PesquisaPresenter {
	private:
		PesquisaView *pesquisaView;
	public:
		PesquisaPresenter();
		int run();
};

#endif 
