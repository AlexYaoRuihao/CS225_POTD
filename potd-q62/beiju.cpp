#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;


string beiju(string input){
  //return input;
  string ret = "";
  stack<char> good_stack;
  string temp = "";
  vector<string> good_vector;

  unsigned i = 0;
  while(i != input.size()){
    if(input[i] == '['){
      good_stack.push('[');
      i++;
      continue;
    }

    if(input[i] == ']'){
      // if(good_stack.top() == '['){
      //   good_stack.pop();
      // }
      if(!good_stack.empty()){
        if(good_stack.top() == '['){
          good_stack.pop();
        }
      }
      good_vector.push_back(temp);
      temp.clear();
      i++;
      continue;
      // else{
      //   good_stack.push(']');
      // }
    }
    //cout<<"gg"<<endl;
    //if(good_stack.empty() )
    if(!good_stack.empty() && good_stack.top() == '['){
      temp+=input[i];
    }

    //cout<<"gg"<<endl;
    if(good_stack.empty() || good_stack.top() != '['){
      ret+=input[i];
    }


    i++;
  }
  // reverse(temp.begin(), temp.end());
  for(int i = good_vector.size() - 1; i >=0; i--){
    ret = good_vector[i] + ret;
  }
  ret = temp + ret;
  return ret;
}







//
