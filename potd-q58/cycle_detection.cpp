#include <iostream>
#include <string>
#include <stack>
#include <vector>

#include "graph.cpp"

using namespace std;
bool hasCycles_helper(int v, vector<bool> &visited, vector<Node*> &recursion, Node *node);
//the below method could pass 4/5 test cases
// // TODO: Implement this function
// bool hasCycles(Graph & g) {
//
//     int V = g.nodes.size();
//
//     for(int i = 0; i < V - 1; i++) {
//         //Node* node = g.nodes[i];
//
//         // Do something
//         if(!g.containsEdge(i, i+1)){
//           return false;
//         }
//     }
//     if(g.containsEdge(V - 1, 0))
//       return true;
//
//     return false;
// }



// TODO: Implement this function
//this method passes all tests, probably called iterative DFS
bool hasCycles(Graph const & g) {

    int V = g.nodes.size();

    vector<bool> visited;
    vector<Node*> recursion;

    for(int i = 0; i < V; i++){
      visited.push_back(false);
      recursion.push_back(NULL);
    }



    for(int i = 0; i < V; i++) {
        Node* node = g.nodes[i];
        // cout<<node->value<<" ";
        // cout<<endl;
        // Do something
        if(hasCycles_helper(i, visited, recursion, node)){
            return true;
        }
    }

    return false;
}

bool hasCycles_helper(int v, vector<bool> &visited, vector<Node*> &recursion, Node *node){
    if(!visited[v]){
        visited[v] = true;
        recursion[v] = node;
        //for(auto i = (node->outgoingNeighbors).begin(); i != (node->outgoingNeighbors).end(); i++){
        for(int i = 0; i < node->outgoingNeighbors.size(); i++){
            if(!visited[node->outgoingNeighbors[i]->value] && hasCycles_helper(node->outgoingNeighbors[i]->value, visited, recursion, node->outgoingNeighbors[i])){
                return true;
            }
            else if(recursion[node->outgoingNeighbors[i]->value]){
                return true;
            }
        }
    }
    recursion[v] = NULL;
    return false;
}












//
