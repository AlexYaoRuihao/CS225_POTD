// Your code here
#include "potd.h"
#include <string>

using namespace std;


string getFortune(const string &s){
  int string_size = s.length();

  string a = "a";
  string b = "b";
  string c = "c";
  string d = "d";
  string e = "e";
  string f = "f";
  /*string g = "g";
  string h = "h";
  string i = "i";
  string j = "j";
  string k = "k";
  string l = "l";
  string m = "m";
  string n = "n";
  string o = "o";
  string p = "p";
  string q = "q";*///17

  int fortune_number = string_size % 6;
  switch (fortune_number) {
    case 0:
      return a;
    case 1:
      return b;
    case 2:
      return c;
    case 3:
      return d;
    case 4:
      return e;
    case 5:
      return f;
  }
}
