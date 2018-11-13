#include "Pattern.h"
#include <string>
#include <iostream>
#include <map>

using namespace std;

bool wordPattern(std::string pattern, std::string str) {
    //write your code here
    map<char, string> good_map;
    string temp = "";
    int i = 0;
    for(string::iterator it = str.begin(); it != str.end(); it++){
      // if(*it != ' '){
      //   temp.append(*it);
      // }
      cout<<*it<<" "<<endl;
      while(*it != ' '){
        temp+=(*it);
        it++;
      }
      //cout<<temp<<endl;
      if(good_map.find(pattern[i]) != good_map.end()){//found
        if(good_map[pattern[i]] != temp){
          return false;
        }
      }
      else{//not found
        good_map[pattern[i]] = temp;
      }
      i++;
      temp.clear();
    }
    return true;
}
