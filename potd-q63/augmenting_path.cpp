#include "network_flow.cpp"
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>

using namespace std;

bool hasAugmentingPath_helper(ResidualNetwork r, int src, int dest, set<int> &visited){
  if(visited.count(src) != 0){
    return false;
  }
  visited.insert(src);
  if(src == dest){
    return true;
  }

  vector<int> adjs = r.outgoingNeighbors(src);
  for(auto &it : adjs){
    if(visited.count(it) == 0 && r.edgeCapacity(src, it) != 0){
      if(hasAugmentingPath_helper(r, it, dest, visited)){
        return true;
      }
    }
  }
  return false;
}

// TODO: Implement this function. Try using BFS/DFS
bool hasAugmentingPath(ResidualNetwork r) {
  // cout<<"source: "<<r.source<<endl;
  // cout<<"sink: "<<r.sink<<endl;
  // cout<<"numNodes: "<<r.numNodes<<endl;
  // stack<int> good_stack;
  // map<int, bool> good_map;
  //
  // for(int i = 0; i < r.numNodes; i++){
  //   good_map.insert(pair<int, bool>(i, false));
  // }
  //
  // good_stack.push(r.source);
  // while(!good_stack.empty()){
  //   int top_stack = good_stack.top();
  //   good_stack.pop();
  //   for(auto &it : g.outgoingNeighbors(top_stack)){
  //     if(good_map[it] == false && edgeCapacity(top_stack, it) != 0){
  //       good_map[it] = true;
  //
  //     }
  //   }
  // }
  set<int> visited;
  return hasAugmentingPath_helper(r, r.source, r.sink, visited);
  //return false;
}
