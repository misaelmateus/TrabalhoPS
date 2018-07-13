#include<stdlib.h>
#include "MenuPresenter.hh"
#include "PesquisaPresenter.hh"

MenuPresenter::MenuPresenter(){
	menuView = new MenuView();

}

int MenuPresenter::run(){
	while(true){
		int opcao = menuView->ShowView();
		switch(opcao){
			case 1:

				break;
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