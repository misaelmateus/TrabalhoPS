#include<stdlib.h>
#include<ctype.h>
#include<string>
#include<algorithm>
#include "ListarNoticiasPresenter.hh"
#include "NoticiaView.hh"
ListarNoticiasPresenter::ListarNoticiasPresenter(std::vector<Noticia> &_noticias){
	model = new ListarNoticiasModel(_noticias);
	listarNoticiasView = ListarNoticiasView();
}

int ListarNoticiasPresenter::run(){
	int ini = 1, fim = 10;
	while(true){
		std::vector<Noticia> noticias = model->getNoticias(ini, fim);
		std::string opcao = listarNoticiasView.ShowView(noticias, ini, fim);
		if(opcao[0] == 'f') // fechar programa
			return 0;
		else if(opcao[0] == 'v') // voltar
			return 1;
		else if(opcao[0] == '+'){
			if(fim < model->noticiasSize())
				ini += 10, fim += 10;
			continue;
		}
		else if(opcao[0] == '-'){
			if(ini > 1)
				fim -= std::min(ini-1, 10), ini -= std::min(ini-1, 10);
			continue;
		}
		else {
			for(auto &u : opcao) if(!isdigit(u)) continue;
			int num = std::stoi(opcao);
			if(num > 0 && num <= model->noticiasSize()){
				NoticiaView noticiaView(noticias[num-1]);
				noticiaView.ShowView();
			}
		}
	}

}	