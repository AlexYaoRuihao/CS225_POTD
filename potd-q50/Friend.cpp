#include "Friend.h"
#include <vector>

using namespace std;

int find(int x, std::vector<int>& parents) {
   // your code
   //if(parents[i] < )
   return 0;
}

int findCircleNum(std::vector<std::vector<int>>& M) {
    // your code
    int M_size = M.size();
    for(unsigned i = 0; i < M.size(); i++){
      for(unsigned j = 0; j < M[i].size(); j++){
        if(M[i][j] == 1 && i > j){
          M_size--;
        }
      }
    }
    return M_size;
}
