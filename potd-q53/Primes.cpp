#include <vector>
#include "Primes.h"

using namespace std;

std::vector<int> *genPrimes(int M) {
    std::vector<int> *v = new std::vector<int>();
    // your code here
    //vector<bool> good_vector;
    for(int i = 2; i <= M; i++){
      v->push_back(i);
      for(int j = 2; j < i; j++){
        if(i % j == 0){
          v->pop_back();
          break;
        }
      }
    }
    return v;
}
