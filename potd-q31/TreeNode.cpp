#include "TreeNode.h"
#include <cstdlib>
#include <algorithm>

using namespace std;

int computingHeight(TreeNode *croot){
  if(croot == NULL){
    return -1;
  }
  int leftHeight = computingHeight(croot -> left_);
  int rightHeight = computingHeight(croot -> right_);

  return max(leftHeight, rightHeight) + 1;
}


bool isHeightBalanced(TreeNode* root) {
  // your code here
  //return false;
  if(root == NULL){
    return true;
  }
  if(abs(computingHeight(root->right_) - computingHeight(root->left_)) > 1){
    return false;
  }
  return isHeightBalanced(root->right_) && isHeightBalanced(root->left_);
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
