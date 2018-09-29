#include "Node.h"

using namespace std;

void mergeList(Node *first, Node *second) {
  // your code here!
  if(first == NULL){
    first = second;
  }
  if(second == NULL){
    return;
  }




  Node *first_copy = first;
  Node *second_copy = second;

  while((first_copy->next_ != NULL) && (second_copy->next_ != NULL)){
    Node *temp_first = first_copy;
    Node *temp_second = second_copy;

    first_copy = first_copy -> next_;
    second_copy = second_copy -> next_;

    temp_first -> next_ = temp_second;
    temp_second -> next_ = first_copy;
  }

  if(first_copy->next_ == NULL){
    first_copy->next_ = second_copy;
  }
  else{//second_copy->next_ == NULL
    Node *temp = first_copy;
    first_copy = first_copy -> next_;
    temp -> next_ = second_copy;
    second_copy -> next_ = first_copy;
  }
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
