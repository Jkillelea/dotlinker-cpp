// This code is part of dotlinker-cpp
// Copyright Jacob Killelea <jkillelea@protonmail.ch>
#include <cstdlib>   // exit
#include <unistd.h>  // symlink
#include <iostream>  // cerr
#include "dotfile.h" // class DotFile, string
using namespace std;

void err(string text, int code = 1); // prototype

int main(int argc, const char* argv[]) {
  string path;

  if (argc < 2) { // didn't supply any options
    err("[ERROR] need to give a filename");
  }

  // each arg
  for (int i = 1; i < argc; i++) {

    try {
      path = argv[i];
    } catch (logic_error& e) { // failed to assign (no opts given)
      err( ("[ERROR] Error incountered parsing command line options" + string(e.what())), 1);
    }

    if (path[0] == '-') continue; // skip configuration options (lol currently there are none)
    DotFile dotfile(path); // create object

    if (fs::exists(dotfile.dotfile_path))
      err("[ERROR] File already exists in linking location");

    if (dotfile.exists) { // good file given
        symlink(dotfile.absolute_path.c_str(), dotfile.dotfile_path.c_str());
        cerr << ("linked " + dotfile.absolute_path + " to " + dotfile.dotfile_path) << endl;
      }
    else {
      err(("Need to be given a real filepath instead of " + dotfile.absolute_path));
    }
  } // end for-loop
  
  return 0; // done
}

inline void err(string text, int code) {
  cerr << text << endl;
  exit(code);
}
