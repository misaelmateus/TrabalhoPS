#include<iostream>
#include<utility>
#include<string>
#include "LoginView.hh"
using namespace std;

LoginView::LoginView(){

}

pair<string, string> LoginView::ShowView(){
	system("clear");
	cout << "--------------- NEWS -----------------\n";
	cout << "Digite login: ";
	string login, senha;
	cin >> login;
	cout << "Digite senha : ";
	cin >> senha;
	return {login, senha};
}

int LoginView::FalhaLogin(){
	cout << "Login ou Senha errado\nDigite:\n   1 para tentar novamente\n   2 para voltar\n   3 para sair do programa\n";

	int opcao;
	cin >> opcao;
	return opcao;
}