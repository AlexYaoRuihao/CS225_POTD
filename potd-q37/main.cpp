#include <iostream>
#include "functions.h"
#include <limits.h>
using namespace std;

int main() {
  cout << samesies(4, 4) << endl;;
  cout<<"absolute test: "<<absolutely(-INT_MAX-1)<<endl;
  cout<<"factorial test: "<<factorial(INT_MAX + 1)<<endl;
  cout<<"samesies test: "<<samesies((INT_MAX)/2, (INT_MAX)/2 - 1)<<endl;
  cout<<"magnaCalca test: "<<magnaCalca(INT_MAX + 1,INT_MAX + 1)<<endl;
  return 0;
  //cout<<"absolute test 1: "<<absolutely(34)<<endl;
}
