#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

class Node {
    public:
        int data_;
        Node *next_;
        Node();
        Node(Node &other);
        ~Node();
        static int getNumNodes() {
            return numNodes;
        }
        //void insertSorted(Node **head, Node *item);
    private:
        static int numNodes;
};

//void insertSorted(Node **head, Node *item);
void sortList(Node **head);

#endif
