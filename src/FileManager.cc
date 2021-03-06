// Bibliotecas c
#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <ftw.h>

#include <string>
using std::string;
#include <vector>
using std::vector;

// Verifica se arquivo existe
bool file_exist(const string file) {
  struct stat buf;
  return (stat(file.c_str(), &buf) == 0);
}

// Verifica se file é um diretório.
bool file_is_dir(const string file) {
  struct stat buf; stat(file.c_str(), &buf);
  return (S_ISDIR(buf.st_mode) != 0);
}

vector<string> get_dir(const string dir) {

  // Assume-se que a pasta realmente existe.
  DIR *d = opendir(dir.c_str());
  struct dirent *dp = NULL;

  vector<string> files;

  // Varrer arquivos dentro do diretório
  while((dp = readdir(d)) != NULL) {
    string file(dp->d_name), file_abs(dir + file);

    if(file_is_dir(file_abs) && (file != "." && file != ".."))
      files.push_back(file);
  }

  closedir(d);
  return files;
}

void create_dir(const string path) {
  mkdir(path.c_str(), S_IFDIR | S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
}

int unlink_cb(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf) {
  (void)sb; (void)typeflag; (void)ftwbuf;
  return remove(fpath);
}


void remove_dir(const string path) {
  nftw(path.c_str(), unlink_cb, 64, FTW_DEPTH);
}
