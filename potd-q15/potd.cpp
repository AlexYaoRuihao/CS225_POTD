#include "potd.h"
#include <iostream>

using namespace std;

string stringList(Node *head) {
  if(head == NULL){
    return "Empty list";
  }
  Node *temp = head;
  int c = 0;
  string d;
  while(temp != NULL){
    if(temp->next_ != NULL){
    d.append("Node " + to_string(c) + ": " + to_string(temp->data_) + " -> ");
    c++;
    temp = temp->next_;
  }
  else{
    d.append("Node " + to_string(c) + ": " + to_string(temp->data_));
    c++;
    temp = temp->next_;
  }
}

  return d;
}
