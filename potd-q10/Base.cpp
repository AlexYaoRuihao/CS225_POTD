#include "Base.h"
#include <string>
//#include "Derived.h"

//using namespace std;

std::string Base::foo(){
  return "Sam I Am";
}

std::string Base::bar(){
  return "Green Eggs";
}

Base::~Base(){}
