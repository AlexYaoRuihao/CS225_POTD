#pragma once
#include <string>
#include "Base.h"

//using namespace std;

class Derived : public Base{
  public:
  std::string foo();
  std::string bar();
  ~Derived();
};
