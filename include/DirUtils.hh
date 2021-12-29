#ifndef DirUtils_h
#define DirUtils_h 1

#include <vector>
#include <string>

class DirUtils {
private:

public:
  DirUtils();
  ~DirUtils();

  static void mkdir(const char* s);
  static std::vector<std::string> getFileList(const char* dir);
  static const char* getPathDelim();
};

#endif
