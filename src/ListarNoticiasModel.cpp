#include<stdlib.h>
#include<string>

#include "ListarNoticiasModel.hh"

ListarNoticiasModel::ListarNoticiasModel(std::vector<Noticia> &_noticias){
	updateNoticiasModel(_noticias);
}

void ListarNoticiasModel::updateNoticiasModel(std::vector<Noticia> &_noticias){
	noticias = _noticias;
}
std::vector<Noticia> ListarNoticiasModel::getNoticias(int ini, int fim){
	std::vector<Noticia> _noticias;
	for(int i = std::max(0, ini-1); i < std::min((int)noticias.size(), fim-1); i++)
		_noticias.push_back(noticias[i]);
	return _noticias;
}

int ListarNoticiasModel::noticiasSize(){
	return noticias.size();
}
