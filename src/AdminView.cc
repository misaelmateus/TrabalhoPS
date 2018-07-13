#include "AdminView.hh"
#include <iostream>
using namespace std;
int AdminPresenter::ShowView(){
	system("clear");
	cout << "Escolha uma opcao: \n";
	cout << "1) Inserir noticia\n2)Remover Noticia\n";
	int opcao;
	cin >> opcao;
	return opcao;
}

