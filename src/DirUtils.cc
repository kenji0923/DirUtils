#include "DirUtils.hh"

#include <string>
#include <iostream>

#ifdef _WIN32
#include <direct.h>
#include <windows.h>
#else
#include <dirent.h>
#endif

DirUtils::DirUtils()
{
}

DirUtils::~DirUtils()
{
}


void DirUtils::mkdir(const char* s) {
  std::string str = "mkdir ";
  str = str + std::string(s);
#ifdef _WIN32
  _mkdir(s);
#else
  system(str.c_str());
#endif
}

std::vector<std::string> DirUtils::getFileList(const char* dir) {
  std::vector<std::string> files;
#ifdef _WIN32
  HANDLE hFind;
  WIN32_FIND_DATA win32fd;

  std::string file = dir;
  file = file + "\\*";
  hFind = FindFirstFile(file.c_str(), &win32fd);

  if (hFind == INVALID_HANDLE_VALUE) {
	  return files;
  }

  do {
	  if (win32fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
		  // printf("%s (DIR)\n", win32fd.cFileName);
	  } else {
		  // printf("%s\n", win32fd.cFileName);
      files.push_back(win32fd.cFileName);
	  }
  } while (FindNextFile(hFind, &win32fd));

  FindClose(hFind);
#else
  DIR *dp = opendir(dir);
  if (dp == NULL) {
  }
  dirent* entry = readdir(dp);
  while (entry != NULL){
    if (entry != NULL) {
      files.push_back(entry->d_name);
    }
    entry = readdir(dp);
  }
#endif

  return files;
}

const char* DirUtils::getPathDelim() {
#ifdef _WIN32
  return "\\";
#else
  return "/";
#endif
}
