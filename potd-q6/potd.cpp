// your code here!
#include <iostream>
#include "potd.h"
#include <cmath>

using namespace std;
//using namespace potd;
namespace potd{
//using namespace std;

int *raise(int *arr){
  //int size = sizeof(arr)/sizeof(*arr);
  int size = 0;
  while(arr[size] > 0){
    size++;
  }
  size++;

  int *array_heap = new int[size];
  for(int i = 0; i < size - 2; i++){
    array_heap[i] = pow(arr[i], arr[i + 1]);
  }
  array_heap[size - 2] = arr[size - 2];
  array_heap[size - 1] = arr[size - 1];
  //cout<<size<<endl;
  return array_heap;
  //cout<<size<<endl;
  //return;
}
}
