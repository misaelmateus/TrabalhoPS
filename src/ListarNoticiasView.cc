#include<stdlib.h>
#include<string>
#include "ListarNoticiasView.hh"
ListarNoticiasView::ListarNoticiasView(){
	
}

std::string converterData(std::string d){ // de aaaa/mm/dd - hh/mm para dd/mm/aaaa - hh/mm
	string ans = "";
	ans.append(d.begin()+8, d.begin()+10);
	ans += "/";
	ans.append(d.begin()+5, d.begin()+8);
	ans.append(d.begin(), d.begin()+4);
	ans.append(d.begin()+10, d.end());

	return ans;
}

string ListarNoticiasView::ShowViews(vector<Noticias> &noticias, int ini, int fim){
	system("clear");
	std::cout << "---------------------NEWS------------------------\n\n";

	std::cout << "--------Ultimas noticias ---------\n\n"
	std::cout << "--------------------------------------------------\n"
	std::cout << "De noticia " << ini << " à " << fim << "\n\n";
	
	for(int i = max(0, ini-1); i < min(noticias.size(), fim-1); i++){
		std::cout << "----- Noticia " << i+1 << "\n";
		std::cout << noticias[i]._titulo << "\n";
		std::cout << converterData(noticias[i]._data) << "\n";

		std::cout << "\n" << noticias[i]._resumo << "\n";
	}
	std::cout << "----------------------------------------------------\n\n";

	string opcao;

	std::cout << "Digite + para ver noticias mais antigas,
	 - para ver noticias mais recentes, f para fechar programa, v para voltar ou o id da noticia para entrar nela\n";

	 std::cin >> opcao;
	 return opcao;
}	