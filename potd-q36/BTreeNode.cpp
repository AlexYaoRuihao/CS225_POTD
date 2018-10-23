#include <vector>
#include "BTreeNode.h"
#include <iostream>

using namespace std;

//vector<int> v1;
std::vector<int> traverse(BTreeNode* root) {
    // your code here
    vector<int> v;
    //return v;
    // unsigned i;
    // for(i = 0; i < root->elements_.size(); i++){
    //   if(!root->is_leaf_){
    //     traverse(root->children_[i]);
    //   }
    //   int j = root->elements_[i];
    //   //v1 = pushback(j, v);
    //   v.push_back(j);
    //
    //   //cout<<root->elements_[i]<<" ";
    // }
    // if(!root->is_leaf_){
    //   traverse(root->children_[i]);
    //   //return v;
    // }
    traverse_helper_function(root, v);
    return v;
}

vector<int> traverse_helper_function(BTreeNode*& root, vector<int> &v){
  unsigned i;
  for(i = 0; i < root->elements_.size(); i++){
    if(!root->is_leaf_){
      traverse_helper_function(root->children_[i], v);
    }
    int j = root->elements_[i];
    //v1 = pushback(j, v);
    v.push_back(j);

    //cout<<root->elements_[i]<<" ";
  }
  if(!root->is_leaf_){
    traverse_helper_function(root->children_[i], v);
    //return v;
  }
  return v;
}
