// This code is part of dotlinker-cpp
// Copyright Jacob Killelea <jkillelea@protonmail.ch>
// this script is just random testing crap, not to be used with the expectation of fucntionality
#include <iostream>
#include <experimental/filesystem>
#include "dotfile.h"
using namespace std;
namespace fs = std::experimental::filesystem;

int main(int argc, char const *argv[]) {
  // if (argc < 2) { // didn't supply any options
  //   std::cerr << "[ERROR] need to give a filename" << std::endl;
  //   return 1;
  // }
  //
  // DotFile dotfile(argv[1]);
  // std::cout << "Exists   : "     << (dotfile.exists?"true":"false") << std::endl;
  // std::cout << "Dotted   : "     << dotfile.dot() << std::endl;
  // std::cout << "Undotted : "     << dotfile.undot() << std::endl;
  // std::cout << "Absolute : "     << dotfile.absolute_path << std::endl;
  // std::cout << "Dotfile path : " << dotfile.dotfile_path << std::endl;
  // return 0;

  // fs::path p = "test\0";
  fs::path p1 = argv[1];
  std::cout << fs::absolute(p1) << std::endl;
}
