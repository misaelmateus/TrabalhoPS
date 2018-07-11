#ifndef _FILE_MANAGER_HH_
#define _FILE_MANAGER_HH_

#include <string>
#include <vector>

// Verifica se arquivo existe
bool file_exist(const std::string file);

// Verifica se file é um diretório.
bool file_is_dir(const std::string file);

// Obtem diretórios dentro de outro diretório.
std::vector<std::string> get_dir(const std::string dir);

void create_dir(const std::string path);

#endif  // _FILE_MANAGER_HH_
