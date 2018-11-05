#include <vector>
#include "Hash.h"
#include <cstdlib>

void doubleHashInput(std::vector<int> &v, int elem){
	//your code here
  //v[elem] = -1; //remove this
  unsigned idx1 = firstHash(elem, v.size());
  if(v[idx1] == -1){
    v[idx1] = elem;
  }
  else{
    unsigned idx1_copy = idx1;
    unsigned step_size = secondHash(elem);
    unsigned i = 0;
    while(v[idx1] != -1){
      idx1 = idx1_copy + i * step_size;
      while(idx1 >= v.size()){
        idx1 -= v.size();
      }
      ++i;
    }
    v[idx1] = elem;
  }
}



//make a hash function called firstHash
int firstHash(int elem, int length){
  return (elem * 4) % length;
}



//make a second function called secondHash
int secondHash(int elem){
  return 3 - (elem % 3);
}