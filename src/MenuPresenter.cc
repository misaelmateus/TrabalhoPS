#include<stdlib.h>
#include "MenuPresenter.hh"


MenuPresenter::MenuPresenter(){
	menuView = new MenuView();

}

void MenuPresenter::run(){
		int opcao = menuView->ShowView();
		switch(opcao){
			case 1:

				break;
			case 2:

				break;
			case 3:
	
				 break;
			case 4:

				break;
			



		}
	}	