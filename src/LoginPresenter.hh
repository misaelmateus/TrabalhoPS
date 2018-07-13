#ifndef _LOGINPRESENTER_HH_
#define _LOGINPRESENTER_HH_
#include "DaoManager.hh"
#include "LoginView.hh"
class LoginPresenter{
  private:
  	Credencial *credencial;
  	LoginView *view;
  	DaoManager *daoManager;
  public:
  	LoginPresenter();
  	int run();
};

#endif
