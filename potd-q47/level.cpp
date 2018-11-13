#include "MinHeap.h"
#include <cmath>
#include <iostream>

using namespace std;

vector<int> lastLevel(MinHeap & heap)
{
    // Your code here
    vector<int> good_vector;
    size_t heap_size = heap.elements.size();
    // int test = log2(7);
    // cout<<test<<endl;
    size_t logm = log2(heap_size);

    size_t temp = 1;
    size_t index = 1;
    while(logm){
      index += temp;
      temp = temp * 2;
      logm--;
    }
    if(index == (heap_size)){
      //index -= log2(heap_size);
      index -= pow(2, log2(heap_size) - 1);
      //if(log2(heap_size) != 1 && log2(heap_size) != 2)
        //index--;
    }

    for(size_t i = index; i < heap_size; i++){
      good_vector.push_back(heap.elements[i]);
    }

    return good_vector;
}
