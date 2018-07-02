#ifndef _FILE_MANAGER_HH_
#define _FILE_MANAGER_HH_

#include <fstream>
#include <string>
#include <vector>

class FileManager {
private:
  std::string _prefix_path;

public:

  enum STATUS { OK, F_NOT_FOUND, F_NOT_DIR };

  // Construtor
  FileManager(const std::string absolute_path);

  // Mostra diretórios dentro do diretório.
  std::vector<std::string> listDir(const std::string path) const;

  // Retorna um Manager de um sub-diretório.
  FileManager getDir(const std::string path) const;

  // Retorna stream do arquivo para leitura.
  void readFile(const std::string file, std::ifstream &f) const;

  // Retorna stream de arquivo para escrita.
  void writeFile(const std::string file, std::ofstream &f) const;

  // Retorna caminho atual
  std::string getPath() const;

  static std::string errMsg(const STATUS s);
};

#endif  // _FILE_MANAGER_HH_
