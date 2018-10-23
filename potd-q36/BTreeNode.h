#ifndef BTREENODE_H
#define BTREENODE_H

#include <string>
#include <algorithm>
#include <vector>

struct BTreeNode {
    bool is_leaf_=true;
    std::vector<int> elements_;
    std::vector<BTreeNode*> children_;
    BTreeNode() {}
    BTreeNode (std::vector<int> v) {
      this->elements_ = v;
    }
};

std::vector<int> traverse(BTreeNode* root);
//std::vector<int> pushback(int j, std::vector<int> v);
//std::vector<int> v1;
std::vector<int> traverse_helper_function(BTreeNode*& root, std::vector<int> &v);
#endif
