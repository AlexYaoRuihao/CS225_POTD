#include <iostream>
#include <vector>
#include "Primes.h"

using namespace std;

int main() {
    std::vector<int> * primes = genPrimes(1000);
    for(auto &it : *primes){
      cout<<it<<" ";
    }

    std::cout << "2 has " << numSequences(primes,2) << " sequence(s)." << std::endl;
    std::cout << "3 has " << numSequences(primes,3) << " sequence(s)." << std::endl;
    std::cout << "20 has " << numSequences(primes,20) << " sequence(s)." << std::endl;
    std::cout << "41 has " << numSequences(primes,41) << " sequence(s)." << std::endl;

    return 0;
}
