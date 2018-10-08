#ifndef _QUEUE_H
#define _QUEUE_H

#include <cstddef>

class Queue {
    public:
        Queue();
        ~Queue();

        int size() const;
        bool isEmpty() const;
        void enqueue(int value);
        int dequeue();

    private:
        struct Node{
          int elem;
          Node *next;
        };
        int queue_size;
        Node *head;
        Node *tail;
};

#endif
