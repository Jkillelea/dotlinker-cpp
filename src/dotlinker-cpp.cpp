// This code is part of dotlinker-cpp
// Copyright Jacob Killelea <jkillelea@protonmail.ch>
#include <cstdlib>   // exit
#include <unistd.h>  // symlink
#include <iostream>  // cout, cerr
#include <fstream>   // check file existence
#include "dotfile.h" // class DotFile, type string = std::string
using namespace std;

void err(string text, int code = 1); // prototype

int main(int argc, const char* argv[]) {

  if (argc < 2) { // didn't supply any options
    err("[ERROR] need to give a filename");
  }

  for (int i = 1; i < argc; i++) { // each supplied arg
    string path = argv[i];
    if (path.substr(0, 1) == "-") continue; // skip configuration options

    DotFile dotfile(path); // create object

    if (ifstream(dotfile.dotfile_path.c_str()))
      err("[ERROR] File already exists in linking location");

    if (dotfile.exists) { // good file given
      symlink(dotfile.absolute_path.c_str(), dotfile.dotfile_path.c_str());
      cout << "linked " << dotfile.absolute_path << " to " << dotfile.dotfile_path << endl;
      return 0;
    } else {
      err("Need to be given a real filepath");
    }
  }
  return 0;
}

inline void err(string text, int code) {
  cerr << text << endl;
  exit(code);
}
