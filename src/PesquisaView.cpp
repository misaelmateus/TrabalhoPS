
#include <stdlib.h>
#include <iostream> 
#include "PesquisaView.hh"

PesquisaView::PesquisaView(){
}

int PesquisaView::ShowView(){
	system("clear");
	std::cout << "-------------------------- NEWS -----------------------------\n\n";
	std::cout << "-------Opções--------\n";
	std::cout << "1) Pesquisa exata\n";
	std::cout << "2) Pesquisar noticias contendo todas as palavras\n";
	std::cout << "3) Pesquisar noticias contendo qualquer uma das palavras\n";
	std::cout << "4) Voltar\n";
	std::cout << "5) Sair do programa\n";
	std::cout << "\nDigite sua opção: ";
	int opcao;
	std::cin >> opcao;
	return opcao;
}
