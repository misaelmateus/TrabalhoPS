
#include<iostream>
#include "NoticiaView.hh"


NoticiaView::NoticiaView(Noticia &_noticia){
	noticia = &_noticia;
}

void NoticiaView::ShowView(){
	system("clear");
	std::cout << "---------------------NEWS------------------------\n\n";
	std::cout << noticia->titulo() << "\n";
	std::cout << noticia->dataConvertida() << "\n";

	std::cout << "\n" << noticia->resumo() << "\n\n\n";
	std::cout << noticia->texto() << "\n\n" << "Autor : " << noticia->autor() << "\n";
		std::cout << "----------------------------------------------------\n\n\n";


	std::cout << "Aperte enter para sair\n";
	std::string a;
	std::cin.ignore();
	std::getline(std::cin, a);
}