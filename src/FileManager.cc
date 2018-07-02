// Bibliotecas c
#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

// Bibliotecas C++
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "FileManager.hh"

using std::string; using std::vector;
using std::ifstream; using std::ofstream;

/////////////////////////// Funções locais
// Verifica se arquivo existe
static bool file_exist(const string file) {
  struct stat buf;
  return (stat(file.c_str(), &buf) == 0);
}

// Verifica se file é um diretório.
static bool file_is_dir(const string file) {
  struct stat buf; stat(file.c_str(), &buf);
  return (S_ISDIR(buf.st_mode) != 0);
}

FileManager::FileManager(const string absolute_path) {
  // Antes de inicializar verificar se local realmente existe
  if(!file_exist(absolute_path))
    throw FileManager::F_NOT_FOUND;
  else if(!file_is_dir(absolute_path))
    throw FileManager::F_NOT_DIR;
  else
    _prefix_path = absolute_path;
}

vector<string> FileManager::listDir(const string path) const {
  string dir(_prefix_path + path);
  vector<string> files;

  //std::cout << "listdir: " << dir << std::endl;

  // (talvez lançar exceção) (verificar se é diretório)
  // Não é necessário verificar se arquivo existe
  DIR *d = opendir(dir.c_str());
  struct dirent *dp = NULL;

  // Varrer todos os arquivos no diretório
  while((dp = readdir(d)) != NULL) {
    string file(dp->d_name), file_abs(dir + "/" + file);
    if(file_is_dir(file_abs) && (file != "." && file != "..") )
      files.push_back(file_abs);
  }

  closedir(d);
  return files;
}

FileManager FileManager::getDir(const string path) const {
  string file(_prefix_path + "/" + path);
  try {
    FileManager fm(file);
    return fm;
  } catch (const FileManager::STATUS &s) {
    throw;
  }
}

///// Leitura e escrita de arquivos
void FileManager::readFile(const string file, ifstream &f) const {
  string file_abs(_prefix_path + "/" + file);

  if(!file_exist(file_abs))
    throw FileManager::F_NOT_FOUND;
  else
    f.open(file_abs);
}

void FileManager::writeFile(const string file, ofstream &f) const {
  string file_abs(_prefix_path + "/" + file);

  if(!file_exist(file_abs))
    throw FileManager::F_NOT_FOUND;
  else
    f.open(file_abs);
}

///// Métodos extras
string FileManager::getPath() const {
  return _prefix_path;
}


string FileManager::errMsg(const FileManager::STATUS s) {
  if(s == FileManager::F_NOT_FOUND)
    return "Arquivo não encontrado";
  else if(s == FileManager::F_NOT_DIR)
    return "Arquiv não é um diretório";
  else
    return "Não tem erro";
}
