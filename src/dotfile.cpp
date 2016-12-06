// This code is part of dotlinker-cpp
// Copyright Jacob Killelea <jkillelea@protonmail.ch>
#include <stdlib.h>  // realpath
#include <limits.h>  // PATH_MAX
#include <fstream>   // file exists
#include "dotfile.h" // classdef

string base_name(const string& path); // prototypes

DotFile::DotFile(string relative_filepath){
  /* find absolute path, basename, dotfile path
   * check file exists
   */
  char path[PATH_MAX];
  string homedir = getenv("HOME"); // unreliable

  const char* relpath = relative_filepath.c_str();
  realpath(relpath, path); // fills buffer path

  absolute_path = (string) path;
  basename      = base_name(absolute_path);
  dotfile_path  = homedir + "/" + dot();

  std::ifstream file(absolute_path.c_str());
  exists = file.good();
};

DotFile::~DotFile() {
  /* Look up how to actually do destructors in C++
   */
};

bool DotFile::is_dotted() {
  return basename[0] == '.' ? true : false;
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

string base_name(const string& path)
{
  return path.substr(path.find_last_of("/\\") + 1);
}
