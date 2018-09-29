// your code here
#pragma once
#include "Foo.h"
#include <string>

//using namespace potd;
using namespace std;

namespace potd{
  class Bar{
    public:
      Bar(string);
      Bar(const Bar &);
      Bar & operator=(const Bar &);
      string get_name();
      ~Bar();

    private:
      Foo *f_;
  };
}
