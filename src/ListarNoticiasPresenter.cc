#include<stdlib.h>
#include<ctype.h>
#include<string>
#include<algorithm>
#include "ListarNoticiasPresenter.hh"
ListarNoticiasPresenter::ListarNoticiasPresenter(vector<Noticias> &_noticias){
	noticias = _noticias;
}

int ListarNoticiasPresenter::run(){
	int ini = 1, fim = 10;
	while(true){
		std::string opcao = ListarNoticiasView->ShowView(noticias, ini, fim);
		if(opcao[0] == "f") // fechar programa
			return 0;
		else if(opcao[0] == "v") // voltar
			return 1;
		else if(opcao[0] == "+"){
			if(fim < noticias.fim())
				ini += 10, fim += 10;
			continue;
		}
		else if(opcao[0] == "-"){
			if(ini > 1)
				fim -= min(ini-1, 10), ini -= min(ini-1, 10);
			continue;
		}
		else {
			for(auto &u : opcao) if(!isdigit(u)) continue;
			int num = std::stoi(opcao);
			if(num > 0 && num <= noticias.size()){
				// abrir noticia noticias[(num-1)]
			}
		}
	}

}	