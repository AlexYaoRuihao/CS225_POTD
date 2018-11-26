#include <vector>
#include "Primes.h"

using namespace std;

std::vector<int> *genPrimes(int M) {
    std::vector<int> *v = new std::vector<int>();
    std::vector<int> *t = new std::vector<int>(M);
    int i=0;
    int nextPrime = 2;

    for(i=0; i<M; i++)
        (*t)[i] = 1;

    (*t)[0]=0;
    (*t)[1]=0;

    v->push_back(2);

    while (nextPrime < M) {
        for(i=nextPrime*nextPrime;
                i < M;
                i+=nextPrime)
            (*t)[i] = 0;
        for(++nextPrime; nextPrime<M; nextPrime++)
            if ((*t)[nextPrime] == 1) {
                v->push_back(nextPrime);
                break;
            }
    }

    delete t;
    return v;
}


int numSequences(std::vector<int> *primes, int num) {

    // your code here

    // code to quell compiler complaints.  Delete it.
    //return num + (*primes)[1];
    int num_of_representations = 0;

    for(unsigned i = 0; i < (*primes).size(); i++){
      int temp = 0;
      for(unsigned j = i; j < (*primes).size(); j++){
        temp+=(*primes)[j];
        if(temp == num){
          num_of_representations++;
          break;
        }
        if(temp > num){
          break;
        }
      }
    }

    return num_of_representations;
}
