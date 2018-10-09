#ifndef _STACK_H
#define _STACK_H

#include <cstddef>

class Stack {
public:
  Stack();
  ~Stack();

  int size() const;
  bool isEmpty() const;
  void push(int value);
  int pop();
private:
  struct Node{
    int elem;
    Node *next;
  };
  int stack_size;
  Node *head;
};

#endif
