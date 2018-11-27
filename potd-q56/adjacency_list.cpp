#include <iostream>
#include <string>
#include "adjacency_list.h"

using namespace std;

bool containsEdge(Graph const * const g, int src, int dest) {
    // Your code here
    LinkedListNode *linkedlistnode = g->adjLists[src].edges;
    while(linkedlistnode){
      if(linkedlistnode->v == dest){
        return true;
      }
      linkedlistnode = linkedlistnode->next;
    }
    return false;
}

void addEdge(Graph* g, int src, int dest) {
    // Your code here
    AdjacencyList *adjacencylist = g->adjLists;
    LinkedListNode *new_edge = new LinkedListNode();
    new_edge->next = adjacencylist[src].edges;
    new_edge->v = dest;
    adjacencylist[src].edges = new_edge;
}

int numOutgoingEdges(Graph const * const g, int v) {
    // Your code here
    int num = g->n;
    int count = 0;
    for(int i = 0; i < num; i++){
      if(containsEdge(g, v, i)){
        count++;
      }
    }
    return count;
}


int numIncomingEdges(Graph const * const g, int v) {
    // Your code here
    int num = g->n;
    int count = 0;
    for(int i = 0; i < num; i++){
      if(containsEdge(g, i, v)){
        count++;
      }
    }
    return count;
}

// No need to modify the functions below

Graph* createVertices(int numV) {
        Graph* g = new Graph();
        g->adjLists = new AdjacencyList[numV];
        g->n = numV;

        // Initialize the vertices
        for (int i = 0; i < numV; i += 1) {
                g->adjLists[i].vertex = i;
                g->adjLists[i].edges = NULL;
        }

        return g;
}

void printGraph(Graph const * const g) {
    for (int i = 0; i < g->n; i += 1) {
        AdjacencyList adjList = g->adjLists[i];

        int v = adjList.vertex;
        // Vertex
        cout << "Vertex: " << v << endl;

        // Print number of incoming and outgoing edges
        int inc = numIncomingEdges(g, v);
        int out = numOutgoingEdges(g, v);
        cout << "Number of incoming edges: " << inc << endl;
        cout << "Number of outgoing edges: " << out << endl;

        cout << "\n" << endl;
    }
}
