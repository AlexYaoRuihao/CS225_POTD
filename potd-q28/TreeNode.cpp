#include "TreeNode.h"

#include <cstddef>
#include <iostream>
using namespace std;
//int TreeNode::GetHeight(TreeNode *croot);

TreeNode::TreeNode() : left_(NULL), right_(NULL) { }

int GetHeight(TreeNode *croot){
  if(croot == NULL){
    return -1;
  }
  int left_height = GetHeight(croot->left_);
  int right_height = GetHeight(croot->right_);
  return max(left_height, right_height) + 1;
}

int TreeNode::getHeight() {
  //return -1;
  /*if(this == NULL){
    return 0;
  }*/
  return GetHeight(this);
}
