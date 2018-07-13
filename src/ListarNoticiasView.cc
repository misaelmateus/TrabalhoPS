#include<stdlib.h>
#include<string>
#include<iostream>
#include "ListarNoticiasView.hh"
ListarNoticiasView::ListarNoticiasView(){
	
}



std::string ListarNoticiasView::ShowView(std::vector<Noticia> noticias, int ini, int fim){
	system("clear");
	std::cout << "---------------------NEWS------------------------\n\n";

	std::cout << "|||| Ultimas noticias ||||| \n\n";
	std::cout << "Mostrando de noticia " << ini << " à " << fim << "\n\n";
	
	for(int i = 0; i < noticias.size(); i++){
		std::cout << "----- Noticia (" << i+1 << ")-----" << "\n";
		std::cout << noticias[i].titulo() << "\n";
		std::cout << noticias[i].dataConvertida() << "\n";

		std::cout << "\n" << noticias[i].resumo() << "\n\n\n";

	}

	std::string opcao;

	std::cout << "Digite:\n + para ver noticias mais antigas\n- para ver noticias mais recentes\n f para fechar programa\n v para voltar\n id da noticia para entrar nela\n";

	 std::cin >> opcao;
	 return opcao;
}	