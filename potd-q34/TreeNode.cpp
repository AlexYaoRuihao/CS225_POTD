#include "TreeNode.h"
#include <algorithm>
#include <cstdlib>
#include <map>
#include <stack>
#include <queue>

using namespace std;

TreeNode* findLastUnbalanced(TreeNode*& root);
bool isHeightBalanced(TreeNode* root);

queue<TreeNode*> good_queue;
stack<TreeNode*> good_stack;
/////////////////////////////////////////////////////////
TreeNode* findLastUnbalanced(TreeNode*& root) {
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
/////////////////////////////////////////////////////////
bool isHeightBalanced(TreeNode* root) {
  // your code here
  //return false;
  if(root == NULL){
    return true;
  }
  if(abs(getHeight(root->right_) - getHeight(root->left_)) > 1){
    return false;
  }
  return isHeightBalanced(root->right_) && isHeightBalanced(root->left_);
}
/////////////////////////////////////////////////////////

TreeNode::RotationType balanceTree(TreeNode*& subroot) {
	// Your code here
  //return TreeNode::right;
  TreeNode *lastUnbalancedNode = findLastUnbalanced(subroot);

  int balance = getHeight(lastUnbalancedNode->right_) - getHeight(lastUnbalancedNode->left_);
  if(balance == -2){
    int l_balance = getHeight(lastUnbalancedNode->left_->right_) - getHeight(lastUnbalancedNode->left_->left_);
    if(l_balance == -1){
      return TreeNode::right;
    }
    else{
      return TreeNode::leftRight;
    }
  }
  else if(balance == 2){
    int r_balance = getHeight(lastUnbalancedNode->right_->right_) - getHeight(lastUnbalancedNode->right_->left_);
    if(r_balance == 1){
      return TreeNode::left;
    }
    else{
      return TreeNode::rightLeft;
    }
  }
}
