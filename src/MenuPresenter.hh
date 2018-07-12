#ifndef _MENUPRESENTER_HH_
#define _MENUPRESENTER_HH_
#include "MenuView.hh"
class MenuView;

class MenuPresenter {
	private:
		MenuView *menuView;
	public:
		MenuPresenter();
		void run();
};

#endif 
