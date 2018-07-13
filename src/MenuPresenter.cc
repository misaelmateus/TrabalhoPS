#include "DaoManager.hh"
#include<stdlib.h>
#include<vector>
#include "MenuPresenter.hh"
#include "PesquisaPresenter.hh"
#include "ListarNoticiasPresenter.hh"
#include "LoginPresenter.hh"
MenuPresenter::MenuPresenter(){
	menuView = new MenuView();

}

int MenuPresenter::run(){
	std::vector<Noticia> noticias;
	DaoManager daoManager("database");
	noticias = daoManager.getNoticiaDAO().lerTodasNoticiasOrdenado();
		
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
			{
				 LoginPresenter *loginPresenter = new LoginPresenter();
				 if(opcao = loginPresenter->run() == 0) return 0;
			     continue;
				 break;
			}
			case 4:
			{
				return 0;
			}
			default:
				continue;

		}
		}
}	