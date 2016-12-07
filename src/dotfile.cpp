// This code is part of dotlinker-cpp
// Copyright Jacob Killelea <jkillelea@protonmail.ch>
#include "dotfile.h" // classdef, string, <experimental/filesystem>

DotFile::DotFile(string strpath) { // string version
  fs::path relpath(strpath);
  _init(relpath);
}

DotFile::DotFile(fs::path fspath) { // fs::path version. Cant' chain constructors so
_init(fspath);                    // they both call a different function
}

DotFile::DotFile(const char* charpath) { // char* path version
  fs::path relpath(charpath);
  _init(relpath);
}

void DotFile::_init(fs::path relpath) { // LOOK AT HOW MUCH EASY IT IS
  /* find absolute path, basename, dotfile path
  * check file exists
  */
  homedir       = getenv("HOME"); // unreliable
  absolute_path = fs::absolute(relpath);
  basename      = relpath.filename();
  exists        = fs::exists(absolute_path);
  dotfile_path  = homedir + "/" + dot();
}

// DotFile::~DotFile() {
//   /* Look up how to actually do destructors in C++
//    */
// };

bool DotFile::is_dotted() {
  return basename[0] == '.';
};

string DotFile::undot() {
  if (is_dotted())
    return basename.substr(1, basename.length());
  else
    return basename;
};

string DotFile::dot() {
  return is_dotted() ? (basename) : ("." + basename);
};
