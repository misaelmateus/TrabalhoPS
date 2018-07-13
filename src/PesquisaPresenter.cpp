
#include <stdlib.h>
#include <iostream> 
#include <vector>
#include "PesquisaPresenter.hh"
#include "Noticia.hh"
PesquisaPresenter::PesquisaPresenter(){
}

int PesquisaPresenter::run(){
	while(true){
		int opcao = pesquisaView->ShowView();
		std::vector<Noticia*> noticias;
		switch(opcao){
				case 1:

					break;
				case 2:

					break;
				case 3:
		
					break;
				case 4:
					return 1;
				case 5:
					return 0;
				default:
					continue;
			}
	}

	
}