#pragma once
#include <string>
//#include "Derived.h"

//using namespace std;

class Base{
  public:
  std::string foo();
  virtual std::string bar();
  virtual ~Base();
};
