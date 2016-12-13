// This code is part of dotlinker-cpp
// Copyright Jacob Killelea <jkillelea@protonmail.ch>
// this script is just random testing crap, not to be used with the expectation of fucntionality
#include <iostream> // cout, cerr
#include "dotfile.h" // classdef, filesystem
using namespace std;

int main(int argc, char const *argv[]) {
  try {
    // fs::path p(argv[1]); // different methods of instantiating a dotfile
    // DotFile dotfile(p);
    DotFile dotfile(argv[1]);

    fs::path home(getenv("HOME"));

    cout << "Exists       : "      << (dotfile.exists? "true":"false") << endl;
    cout << "Absolute     : "      << dotfile.absolute_path            << endl;
    cout << "Basename     : "      << dotfile.basename                 << endl;
    cout << "Dotted       : "      << dotfile.dot()                    << endl;
    cout << "Undotted     : "      << dotfile.undot()                  << endl;
    cout << "Home         : "      << fs::absolute(home).c_str() << endl;
    cout << "Dotfile path : "      << dotfile.dotfile_path             << endl;
  }
  catch (exception&) {
    cerr << "I dont know what went wrong but you did it." << endl;
  }
  return 0;
}
