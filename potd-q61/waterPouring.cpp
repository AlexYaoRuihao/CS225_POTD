#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

#define EMPTY 0

class Node {
    public:
        int a;
        int b;
        vector<Node *> neighbors;
        Node () : a(EMPTY), b(EMPTY), neighbors() {}
        Node (const int &a_, const int &b_) : a(a_), b(b_), neighbors() {}
        Node (const int &a_, const int &b_, const vector<Node *> &neighbors_) : a(a_), b(b_), neighbors(neighbors_) {}
        Node (const Node &tmpNode) : a(tmpNode.a), b(tmpNode.b), neighbors() {}
        bool operator==(const Node & b_node)
        {
            return a == b_node.a && b == b_node.b;
        }
        Node &operator=(const Node & b_node) {
            // WARNING: This operator does not copy the vector
            a = b_node.a;
            b = b_node.b;
            return *this;
        }
};

struct Graph {
    vector<Node *> nodes;
};


Graph createGraph(int capacityy_a, int capacity_b) {
    // TODO
    Graph g;
    return g;
}

int findSolution(Graph g, int target) {
    // TODO: returns minimum number of steps to reach target liters of water (or -1)
    return -1;
}

int waterPouring(int a, int b, int target) {
    // Call createGraph
    // Call findSolution
    Graph stateMachineGraph = createGraph(a, b);
    int steps = findSolution(stateMachineGraph, target);
    for (Node *graphNode : stateMachineGraph.nodes)
        {
            delete graphNode;
        }
    return steps;
}
