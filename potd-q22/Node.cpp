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
  }
  else{
    //Node *temp = result;
    newNode->next_ = result;
    result = newNode;
  }
}



Node *listIntersection(Node *first, Node *second) {
  // your code here
  Node *result = NULL;
  Node *temp_first = first;

  while(temp_first != NULL){
    if(isPresent(second, temp_first->data_)){
      createNew_and_insertFront(result, *temp_first);
    }
    temp_first = temp_first->next_;
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
