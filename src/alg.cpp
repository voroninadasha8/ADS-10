// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  const std::vector<std::vector>& permutations = tree.getPerm();
  if (n > permutations.size()) {
    return {};
  }
  return permutations[n - 1];
}

