#include "TreeNode.h"
#include <algorithm>
#include <cstdlib>
#include <map>
#include <stack>
#include <queue>

using namespace std;

queue<TreeNode*> good_queue;
stack<TreeNode*> good_stack;

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
  if(root == NULL){
    return root;
  }
  good_queue.push(root);
  if(!isHeightBalanced(root)){
    good_stack.push(root);
  }
  while(!good_queue.empty()){
    TreeNode *node = good_queue.front();
    good_queue.pop();

    if(node->left_ != NULL){
      good_queue.push(node->left_);
      if(!isHeightBalanced(node->left_)){
        good_stack.push(node->left_);
      }
    }
    if(node->right_ != NULL){
      good_queue.push(node->right_);
      if(!isHeightBalanced(node->right_)){
        good_stack.push(node->right_);
      }
    }
  }
  if(good_stack.empty()){
    return NULL;
  }
  else{
    return good_stack.top();
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
