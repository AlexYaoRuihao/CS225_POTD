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

  stack<char> small_bracket;
  stack<char> middle_bracket;
  stack<char> large_bracket;

  
}
