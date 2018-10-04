#include "Node.h"

using namespace std;

bool isPresent(Node *head, int data){
  Node *temp = head;
  while(temp != NULL){
    if(temp->data_ == data){
      return true;
    }
    temp = temp->next_;
  }
  return false;
}

void createNew_and_insertFront(Node *&result, Node &other){
  Node *newNode = new Node(other);

  if(result == NULL){
    result = newNode;
    newNode->next_ = NULL;
    return;
  }
  //else{
    //newNode->next_ = result;
    //result = newNode;
  Node *temp = result;
  while(temp != NULL){
    if(temp->data_ == other.data_){
      delete(newNode);
      return;
    }
    temp = temp->next_;
  }
  newNode->next_ = result;
  result = newNode;
  //}
}

Node *listSymmetricDifference(Node *first, Node *second) {
  // your code here
  //return NULL;
  Node *result = NULL;
  Node *temp_first = first;
  Node *temp_second = second;

  while(temp_first != NULL){
    if(!isPresent(second, temp_first->data_)){
      createNew_and_insertFront(result, *temp_first);
    }
    temp_first = temp_first->next_;
  }

  while(temp_second != NULL){
    if(!isPresent(first, temp_second->data_)){
      createNew_and_insertFront(result, *temp_second);
    }
    temp_second = temp_second->next_;
  }
  return result;
}

Node::Node() {
    numNodes++;
}

Node::Node(Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
