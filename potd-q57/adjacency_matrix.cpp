#include <iostream>
#include <string>

#include "adjacency_matrix.h"

using namespace std;

/*
 Implement the functions below
 */

bool containsEdge(Graph const * const g, int src, int dest) {
    //return false;
    if(g->adjMatrix[src][dest] == 1){
      return true;
    }
    return false;
}

void addEdge(Graph* g, int src, int dest) {
    g->adjMatrix[src][dest] = 1;
}

int numOutgoingEdges(Graph const * const g, int v) {
    //return 0;
    int count = 0;
    for(int i = 0; i < g->n; i++){
      if(containsEdge(g, v, i)){
        count++;
      }
    }
    return count;
}


int numIncomingEdges(Graph const * const g, int v) {
    //return 0;
    int count = 0;
    for(int i = 0; i < g->n; i++){
      if(containsEdge(g, i, v)){ 
        count++;
      }
    }
    return count;
}

void printGraph(Graph const * const g) {
        cout << "Adjacency Matrix: " << endl;
        for (int i = 0; i < g->n; i += 1) {
                for (int j = 0; j < g->n; j += 1) {
                        bool neighbor = g->adjMatrix[i][j];
                        cout << neighbor << " ";
                }
                cout << "\n\n";
        }
}

Graph* createVertices(int numV) {
    // No need to modify this function
    Graph* g = new Graph();
    g->n = numV;
    g->adjMatrix = new bool*[numV];
    for (int i = 0; i < numV; i += 1) {
        g->adjMatrix[i] = new bool[numV];
        for (int j = 0; j < numV; j += 1) {
            g->adjMatrix[i][j] = 0;
        }
    }
    return g;
}
