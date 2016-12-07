// This code is part of dotlinker-cpp
// Copyright Jacob Killelea <jkillelea@protonmail.ch>
#ifndef DOTFILE_H
#define DOTFILE_H

#include <string>
using std::string;

#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

class DotFile {
private:
  string homedir;
  void _init(fs::path);
public:
  bool exists;
  string basename, absolute_path, dotfile_path;

  DotFile(string      strpath);
  DotFile(fs::path    fspath);
  DotFile(const char* charpath);
  // virtual ~DotFile();
  bool   is_dotted();
  string undot();
  string dot();
};

#endif /* end of include guard: DOTFILE_H */
