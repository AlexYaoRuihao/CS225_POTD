#include "Stack.h"
Stack::Stack(){
  head = NULL;
  stack_size = 0;
}

Stack::~Stack(){
  while(head != NULL){
    Node *temp = head;
    head = head->next;
    delete temp;
  }
}

// `int size()` - returns the number of elements in the stack (0 if empty)
int Stack::size() const {
  return stack_size;
}

// `bool isEmpty()` - returns if the list has no elements, else false
bool Stack::isEmpty() const {
  //return true;
  if(stack_size == 0){
    return true;
  }
  return false;
}

// `void push(int val)` - pushes an item to the stack in O(1) time
void Stack::push(int value) {
  Node *insert = new Node();
  insert->elem = value;
  insert->next = head;
  head = insert;
  stack_size++;
}

// `int pop()` - removes an item off the stack and returns the value in O(1) time
int Stack::pop() {
  //return -1;
  if(stack_size == 0){
    return -1;
  }
  Node *temp = head;
  head = head->next;
  int return_val = temp->elem;
  delete temp;
  stack_size--;
  return return_val;
}
