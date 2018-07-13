#include "LoginPresenter.hh"
using namespace std;
LoginPresenter::LoginPresenter(){
  view = new LoginView();
  daoManager = new DaoManager("database");

}

int LoginPresenter::run(){
  while(true){
    std::pair<string, string> values = view->ShowView();

    credencial = new Credencial(values.first);
    
    daoManager->getCredencialDAO().lerCredencial(credencial);

    if(credencial->verificar(values.second)){
    	/*
    	AdminPresenter adminPresenter();
    	adminPresenter->run(); */
    }
    else{
    	int opcao = view->FalhaLogin();
    	if(opcao == 1)
    		continue;
    	else if(opcao == 2)
    		return 1;
    	else if(opcao == 3){
    		return 0;
    	}

    }
  }

}