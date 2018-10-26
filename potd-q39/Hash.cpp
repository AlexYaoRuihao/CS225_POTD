#include <vector>
#include <string>
#include "Hash.h"
#include <iostream>
#include <map>

using namespace std;

int hashFunction(string s, int M) {
   // Your Code Here
   //hash function to sum up the ASCII characters of the letters of the string
   int sum = 0;
   for(unsigned i = 0; i < s.length(); i++){
     sum += s[i];
   }
   return (sum % M);
 }

int countCollisions (int M, vector<string> inputs) {
	int collisions = 0;
	// Your Code Here
  vector<int> index_record;
  map<int, int> good_map;
  for(unsigned i = 0; i < inputs.size(); i++){
    index_record.push_back(hashFunction(inputs[i], M));
  }

  for(unsigned i = 0; i < index_record.size(); i++){
    good_map[index_record[i]]++;
  }

  for(auto &it : good_map){
    if(it.second != 1){
      collisions += (it.second - 1);
    }
    //cout<<it.first<<" : "<<it.second<<endl;
  }

	return collisions;
}
