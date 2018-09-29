// your code here
#include "Bar.h"
#include "Bar.h"
#include <string>

using namespace potd;
using namespace std;


Bar::Bar(string s){
  Foo *foo = new Foo(s);
  f_ = foo;
}

Bar::Bar(const Bar &that){
  Foo *foo = new Foo(*(that.f_));
  f_ = foo;
}

Bar & Bar::operator=(const Bar &that){
  this->f_->~Foo();
  this->f_ = new Foo(*(that.f_));
  //f__ -> get_name() = that.f_ -> get_name();
  return *this;
}

string Bar::get_name(){
  return f_ -> get_name();
}

Bar::~Bar(){
  this->f_->~Foo();
}
