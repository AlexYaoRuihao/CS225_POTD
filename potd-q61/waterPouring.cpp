#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>

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


Graph createGraph(int capacity_a, int capacity_b) {
    // TODO
    Graph g;




    return g;
}

int findSolution(Graph g, int target) {
    // TODO: returns minimum number of steps to reach target liters of water (or -1)
    return -1;
}

int gcd(int a, int b){
  if(b == 0){
    return a;
  }
  return gcd(b, a%b);
}



int waterPouring_helper(int fromCap, int toCap, int target) {
    // Call createGraph
    // Call findSolution
    // Graph stateMachineGraph = createGraph(a, b);
    // int steps = findSolution(stateMachineGraph, target);
    // for (Node *graphNode : stateMachineGraph.nodes)
    //     {
    //         delete graphNode;
    //     }
    // return steps;

          // Initialize current amount of water
          // in source and destination jugs
          int from = fromCap;
          int to = 0;

          // Initialize count of steps required
          int step = 1; // Needed to fill "from" Jug

          // Break the loop when either of the two
          // jugs has d litre water
          while (from != target && to != target)
          {
              // Find the maximum amount that can be
              // poured
              int temp = min(from, toCap - to);

              // Pour "temp" litres from "from" to "to"
              to   += temp;
              from -= temp;

              // Increment count of steps
              step++;

              if (from == target || to == target)
                  break;

              // If first jug becomes empty, fill it
              if (from == 0)
              {
                  from = fromCap;
                  step++;
              }

              // If second jug becomes full, empty it
              if (to == toCap)
              {
                  to = 0;
                  step++;
              }
          }
          return step;
}

int waterPouring(int m, int n, int d)
{
    // cout<<"m: "<<m<<endl;
    // cout<<"n: "<<n<<endl;
    // cout<<"d: "<<d<<endl;
    // To make sure that m is smaller than n
    if (m > n)
        swap(m, n);

    // For d > n we cant measure the water
    // using the jugs
    if (d > n)
        return -1;

    // If gcd of n and m does not divide d
    // then solution is not possible
    if ((d % gcd(n,m)) != 0)
        return -1;

    // Return minimum two cases:
    // a) Water of n litre jug is poured into
    //    m litre jug
    // b) Vice versa of "a"
    return min(waterPouring_helper(n,m,d),   // n to m
               waterPouring_helper(m,n,d));  // m to n
    //return 0;
}
