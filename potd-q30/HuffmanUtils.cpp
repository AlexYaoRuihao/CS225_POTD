#include "HuffmanNode.h"
#include "HuffmanUtils.h"
#include <string>
#include <map>


using std::string;
using namespace std;

map<char, string> codes;

//map<char, string> codes;

/**
 * binaryToString
 *
 * Write a function that takes in the root to a huffman tree
 * and a binary string.
 *
 * Remember 0s in the string mean left and 1s mean right.
 */

string binaryToString(string binaryString, HuffmanNode* huffmanTree) {
    /* TODO: Your code here */
    //return "";
    string answer = "";
    HuffmanNode *current = huffmanTree;
    for(size_t i = 0; i < binaryString.length(); i++){
      if(binaryString[i] == '0'){
        current = current -> left_;
      }
      else{
        current = current ->right_;
      }
      if(current -> left_ == NULL && current -> right_ == NULL){
        answer+=(current -> char_);
        current = huffmanTree;
      }
    }
    return answer;
}


void store(HuffmanNode *root, string str){
  if(root == NULL){
    return;
  }
  if(root -> char_ != '@'){
    codes[root->char_] = str;
  }
  store(root->left_, str+"0");
  store(root->right_, str+"1");
  return;
}

/**
 * stringToBinary
 *
 * Write a function that takes in the root to a huffman tree
 * and a character string. Return the binary representation of the string
 * using the huffman tree.
 *
 * Remember 0s in the binary string mean left and 1s mean right
 */

string stringToBinary(string charString, HuffmanNode* huffmanTree) {
    /* TODO: Your code here */
    string answer = "";
    store(huffmanTree, answer);
    for(string::iterator it = charString.begin(); it != charString.end(); it++){
      answer+=codes[*it];
    }
    return answer;
}










///////////////////
