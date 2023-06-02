// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
#include <algorithm>

class TreeNode {
 public:
  char ch;
  int tr = 0;
  std::vector<TreeNode*> vec;
};
class Tree {
 private:
  TreeNode* root;
  std::vector<std::vector<char>> allperms;
  void createallperms(TreeNode* root, std::vector<char> v) {
    if (!root->tr) {
      v.push_back(root->ch);
    }
    if (!root->vec.empty()) {
      for (TreeNode* next : root->vec) {
        createallperms(next, v);
      }
    } else {
      allperms.emplace_back(v);
    }
  }
  void create(TreeNode* root, const std::vector& in) {
    for (char ch : in) {
      auto* temp = new TreeNode;
      temp->ch = ch;
      root->vec.emplace_back(temp);
      std::vector<char> remains = in;
      remains.erase(std::find(remains.begin(), remains.end(), ch));
      create(temp, remains);
    }
  }

 public:
  explicit Tree(std::vector in) {
    root = new TreeNode;
    root->ch = ' ';
    root->tr = 1;
    create(root, in);
    std::vector<char> v;
    createallperms(root, v);
  }
  std::vector<std::vector<char>> getAllPerms() const {
    return allperms;
  }
};
#endif  // INCLUDE_TREE_H_
