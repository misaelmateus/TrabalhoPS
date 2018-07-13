#ifndef _LOGINVIEW_HH_
#define _LOGINVIEW_HH_
#include<utility>
#include<string>
using namespace std;
class LoginView{
  public:
  	LoginView();
  	pair<string, string> ShowView();
  	int FalhaLogin();
};

#endif
