#include "Queue.h"

Queue::Queue() {
  queue_size = 0;
  head = NULL;
  tail = NULL;
}

Queue::~Queue(){
  while(head){
    Node *temp = head;
    head = head->next;
    delete temp;
    temp = head;
  }
}

// `int size()` - returns the number of elements in the queue (0 if empty)
int Queue::size() const {
  //return 0;
  return queue_size;
}

// `bool isEmpty()` - returns if the list has no elements, else false
bool Queue::isEmpty() const {
  //return true;
  if(queue_size == 0){
    return true;
  }
  return false;
}

// `void enqueue(int val)` - enqueue an item to the queue in O(1) time
void Queue::enqueue(int value) {
  if(head == NULL){
    head = new Node();
    tail = head;
    head->elem = value;
    head->next = NULL;
    queue_size++;
    return;
  }
  Node *insert = new Node();
  insert->elem = value;
  insert->next = head;
  head = insert;
  queue_size++;
}

// `int dequeue()` - removes an item off the queue and returns the value in O(1) time
int Queue::dequeue() {
  //return -1;
  if(queue_size == 0){
    return -1;
  }
  if(queue_size == 1){
    Node *temp = tail;
    int return_value = temp->elem;
    delete temp;
    queue_size--;
    head = NULL;
    tail = NULL;
    return return_value;
  }
  Node *temp = tail;
  int return_value = temp->elem;
  Node *temp2 = head;
  while(temp2->next != tail){
    temp2 = temp2->next;
  }
  tail = temp2;
  delete temp;
  queue_size--;
  /*if(queue_size == 0){
    head = NULL;
    tail = NULL;
  }*/
  return return_value;
}
