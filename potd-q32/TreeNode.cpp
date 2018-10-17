#include "TreeNode.h"
#include <algorithm>
#include <cstdlib>
#include <map>

using namespace std;

//map declaration
map<TreeNode*, int> good_map;

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

int find_balance_factor(TreeNode *croot){
  return computingHeight(croot->right_) - computingHeight(croot->left_);
}

TreeNode* findLastUnbalanced(TreeNode* root) {
  // your code here
  //return NULL;
  if(root == NULL){
    return root;
  }
  TreeNode *left = findLastUnbalanced(root->left_);
  TreeNode *right = findLastUnbalanced(root->right_);
  if(isHeightBalanced(left) && isHeightBalanced(right)){
    return NULL;
  }
  else{
    if(computingHeight(left) > computingHeight(right)){
      return left;
    }
    else{
      return right;
    }
  }

}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
