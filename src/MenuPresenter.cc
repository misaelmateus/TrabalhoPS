#include<stdlib.h>
#include<vector>
#include "MenuPresenter.hh"
#include "PesquisaPresenter.hh"
#include "ListarNoticiasPresenter.hh"
#include "DaoManager.hh"
MenuPresenter::MenuPresenter(){
	menuView = new MenuView();

}

int MenuPresenter::run(){
	std::vector<Noticia> noticias;
	DaoManager daoManager("database");
		
	while(true){
		int opcao = menuView->ShowView();
		switch(opcao){
			case 1:{
				ListarNoticiasPresenter *listarNoticias = new ListarNoticiasPresenter(noticias);
				if(listarNoticias->run() == 0) return 0;
				break;
			}
			case 2:
			{
				PesquisaPresenter *pesquisa = new PesquisaPresenter();
				if(pesquisa->run() == 0) return 0;
				break;
			}
			case 3:
			
				 break;
			
			case 4:
			{
				return 1;
			}
			default:
				continue;

		}
		}
}	