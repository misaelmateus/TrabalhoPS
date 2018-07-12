
#include <stdlib.h>
#include <iostream> 
#include "MenuView.hh"

MenuView::MenuView(){
}

int MenuView::ShowView(){
	system("clear");
	std::cout << "-------------------------- NEWS -----------------------------\n\n";
	std::cout << "-------Opções--------\n";
	std::cout << "1) Ver últimas noticias\n";
	std::cout << "2) Pesquisar noticia\n";
	std::cout << "3) Entrar como administrador\n";
	std::cout << "4) Sair\n";
	std::cout << "\nDigite sua opção: ";
	int opcao;
	std::cin >> opcao;
	return opcao;
}