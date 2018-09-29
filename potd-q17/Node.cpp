#include "Node.h"

using namespace std;

void sortList(Node **head) {
  // your code here!
  if(*head == NULL){
    return;
  }
  else{
    Node *NewHead = NULL;
    Node *OldHead = *head;
    Node *insert = NULL;
    while(OldHead != NULL){
      insert = OldHead;
      OldHead = OldHead -> next_;
      //insert -> next_ = NULL;
      //insertSorted(&NewHead, insert);
//////////////////////////////////////////////////////
    while(1){
      if(NewHead == NULL){
        NewHead = insert;
        insert->next_ = NULL;
        //return;
        break;
      }

      Node *temp = NewHead;
      if(temp->data_ >= insert->data_){
        insert->next_ = temp;
        NewHead = insert;
        //return;
        break;
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
        break;
      }
  //////////////////////////////////////////////////////
      //*head = NewHead;
    }
    *head = NewHead;
  }
    //*head = NewHead;
  }
}

/*void insertSorted(Node **head, Node *insert) {
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
}*/

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
