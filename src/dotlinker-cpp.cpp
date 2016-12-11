// This code is part of dotlinker-cpp
// Copyright Jacob Killelea <jkillelea@protonmail.ch>
#include <cstdlib>   // exit
#include <unistd.h>  // symlink
#include <iostream>  // cerr
#include <fstream>   // ifstream - check file existence
#include "dotfile.h" // class DotFile, string
using namespace std;

void err(string text, int code = 1); // prototype

int main(int argc, const char* argv[]) {
  string path;

  if (argc < 2) { // didn't supply any options
    err("[ERROR] need to give a filename");
  }

  for (int i = 1; i < argc; i++) {

    try {
      path = argv[i];
    } catch (std::logic_error& e) { // failed to assign (no opts given)
      std::cerr << "[ERROR] Error incountered parsing command line options" << std::endl;
      std::cerr << e.what() << std::endl;
      return 1;
    }

    if (path.substr(0, 1) == "-") continue; // skip configuration options
    DotFile dotfile(path); // create object

    if (ifstream(dotfile.dotfile_path.c_str()))
      err("[ERROR] File already exists in linking location");

    if (dotfile.exists) { // good file given
        symlink(dotfile.absolute_path.c_str(), dotfile.dotfile_path.c_str());
        std::cerr << ("linked " + dotfile.absolute_path + " to " + dotfile.dotfile_path) << std::endl;
      }
    else
      err(("Need to be given a real filepath instead of " + dotfile.absolute_path));
  }
  return 0;
}

inline void err(string text, int code) {
  cerr << text << endl;
  exit(code);
}
