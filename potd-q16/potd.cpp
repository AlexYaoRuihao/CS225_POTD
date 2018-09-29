#include "potd.h"
#include <iostream>

using namespace std;

void insertSorted(Node **head, Node *insert) {
  // your code here!
  if(*head == NULL){
    *head = insert;
    insert->next_ = NULL;
    return;
  }

  Node *temp = *head;
  if(temp->data_ >= insert->data_){
    insert->next_ = temp;
    *head = insert;
    return;
  }


  else{
    while(temp->next_ != NULL){
      if(temp->next_->data_ >= insert->data_){
        insert->next_ = temp->next_;
        temp->next_ = insert;
        return;
      }
      temp = temp->next_;
    }
    //end of linked list
    temp->next_ = insert;
    insert->next_ = NULL;
  }
}
