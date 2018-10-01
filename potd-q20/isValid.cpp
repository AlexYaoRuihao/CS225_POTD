#include <string>
#include <stack>

using namespace std;

bool isValid(string input) {
  if(input.empty()){
    return true;
  }

  char temp = input.front();

  if(temp == ')' || temp == ']' || temp == '}'){
    return false;
  }

  //stack<char> s;
  //stack<char> s;
  //stack<char> s;
  stack<char> s;

  while(!input.empty()){
    if(input.front() == '('){
      s.push(input.front());
    }
    else if(input.front() == '['){
      s.push(input.front());
    }
    else if(input.front() == '{'){
      s.push(input.front());
    }
    //input.pop();
    input.replace(0,1,"");


  if(input.front() == ')'){
    if(s.empty()){
      return false;
    }
    if(s.top() != '('){
      return false;
    }
    s.pop();
  }

  else if(input.front() == ']'){
    if(s.empty()){
      return false;
    }
    if(s.top() != '['){
      return false;
    }
    s.pop();
  }

  else if(input.front() == '}'){
    if(s.empty()){
      return false;
    }
    if(s.top() != '{'){
      return false;
    }
    s.pop();
  }
}

if(!s.empty()){
  return false;
}
  return true;
}
