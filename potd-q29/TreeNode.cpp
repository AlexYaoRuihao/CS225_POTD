#include "TreeNode.h"
#include <iostream>

TreeNode *findMaximum(TreeNode *croot){
  if(croot == NULL){
    return NULL;
  }
  while(croot -> right_ != NULL){
    croot = croot -> right_;
  }
  return croot;
}

TreeNode * deleteNode(TreeNode* root, int key) {
  // your code here
  //return root;
  if(root == NULL){
    return root;
  }

  if(root -> val_ > key){
    root -> left_ = deleteNode(root -> left_, key);
  }
  else if(root -> val_ < key){
    root -> right_ = deleteNode(root -> right_, key);
  }
  else{
    //no child case
    if(root -> left_ == NULL && root -> right_ == NULL){
      delete root;
      root = NULL;
    }
    //one child case
    else if(root -> left_ == NULL){
      TreeNode *temp = root;
      root = root -> right_;
      delete temp;
    }
    else if(root -> right_ == NULL){
      TreeNode *temp = root;
      root = root -> left_;
      delete temp;
    }
    //two children case
    else{
      TreeNode *temp = findMaximum(root -> left_);//IOS
      root -> val_ = temp -> val_;
      root ->left_ = deleteNode(root -> left_, temp -> val_);
    }

  }
  return root;



}

void inorderPrint(TreeNode* node)
{
    if (!node)  return;
    inorderPrint(node->left_);
    std::cout << node->val_ << " ";
    inorderPrint(node->right_);
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
