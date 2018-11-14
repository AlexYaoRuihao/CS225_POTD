#include "Pattern.h"
#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool wordPattern(std::string pattern, std::string str) {
    //write your code here
    map<char, string> good_map;
    string temp = "";
    str += ' ';
    //int i = 0;

    vector<string> good_vector;
    for(string::iterator it = str.begin(); it != str.end(); ++it){
      if((*it) != ' '){
        temp += (*it);
      }
      // if(it == str.rbegin()){
      //   good_vector.push_back(temp);
      // }
      else{
        good_vector.push_back(temp);
        temp.clear();
      }
    }

    for(unsigned j = 0; j < good_vector.size(); j++){
      cout<<good_vector[j]<<endl;
    }

    //for(string::iterator it = str.begin(); it != str.end(); it++){
    for(unsigned i = 0; i < good_vector.size(); i++){
      // if(*it != ' '){
      //   temp.append(*it);
      // }
      //cout<<*it<<" "<<endl;
      // while(*it != ' '){
      //   temp+=(*it);
      //   it++;
      // }
      //cout<<temp<<endl;


      //test case requires fucking bijection!!!!!!!!

      if(good_map.find(pattern[i]) != good_map.end()){//found
        if(good_map[pattern[i]] != good_vector[i]){
          return false;
        }
      }
      else{//not found
        good_map[pattern[i]] = good_vector[i];
      }

      for(auto &it1 : good_map){
        for(auto &it2 : good_map){
          if(it2.first != it1.first){
            if(it2.second == it1.second){
              return false;
            }
          }
        }
      }
      //i++;
      //temp.clear();
    }
    return true;
}
