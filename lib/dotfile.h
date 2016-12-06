// This code is part of dotlinker-cpp
// Copyright Jacob Killelea <jkillelea@protonmail.ch>
#ifndef DOTFILE_H
#define DOTFILE_H

#include <string>
using std::string;

class DotFile {
public:
  DotFile (string relative_filepath);
  virtual ~DotFile ();
  bool is_dotted();
  string undot();
  string dot();
  bool exists;
  string basename, absolute_path, dotfile_path;
};

#endif /* end of include guard: DOTFILE_H */
