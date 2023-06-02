// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>
class Tree {
 private:
  struct Node {
    char symbol;
    std::vector<Node*> descen;
    explicit Node(char symbol_ = '\0') :symbol(symbol_) {}
  };
  Node* root;
  std::vector<std::vector> permutations;
  void addNode(Node* newroot, std::vector<char> row) {
    if (!newroot) {
        root = newroot = new Node;
    }
    for (char symbol : row) {
      Node* temp = new Node(symbol);
      newroot->descen.push_back(temp);
      std::vector<char> newRow(row);
      newRow.erase(std::find(newRow.begin(), newRow.end(), symbol));
      addNode(temp, newRow);
    }
  }
  void evadeTree(Node* newroot, std::vector<char> row) {
    if (newroot != nullptr && newroot->symbol != '\0')
      row.push_back(newroot->symbol);
    if (newroot->descen.empty())
      permutations.push_back(row);
    for (Node* descen : newroot->descen) {
      evadeTree(descen, row);
    }
  }
  void createPermutations(std::vector<char> row) {
    addNode(root, row);
    evadeTree(root, {});
  }

 public:
  explicit Tree(std::vector init) :root(nullptr) {
    createPermutations(init);
  }
  std::vector<std::vector> getPerm() const {
    return permutations;
  }
};
#endif  // INCLUDE_TREE_H_
