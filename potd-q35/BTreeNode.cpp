#include <vector>
#include "BTreeNode.h"


BTreeNode* find(BTreeNode* root, int key) {
  // Your Code Here
  //return NULL;
  unsigned i;
  for(i = 0; i < root->elements_.size() && key > root->elements_[i]; i++){}

  if(i < root->elements_.size() && key == root->elements_[i]){
    return root;
  }

  if(root->is_leaf_){
    return NULL;
  }
  else{
    BTreeNode *nextChild = root->children_[i];
    return find(nextChild, key);
  }
}
