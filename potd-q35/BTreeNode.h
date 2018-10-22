#ifndef BTREENODE_H
#define BTREENODE_H

#include <string>
#include <algorithm>
#include <vector>

struct BTreeNode {
    bool is_leaf_=true;
    std::vector<int> elements_;//vector of keys of current node
    std::vector<BTreeNode*> children_;
    //vector of children of current node
    BTreeNode() {}
    BTreeNode (std::vector<int> v) {
      this->elements_ = v;
    }
};

BTreeNode* find(BTreeNode* root, int key);

#endif
