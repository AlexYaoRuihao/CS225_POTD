// Animal.h
#include <iostream>
#include <string>
#pragma once

using namespace std;

class Animal{
public:
  string food_;

  Animal();
  Animal(string food, string type);


  string getType();
  void setType(string type);
  string getFood();
  void setFood(string food);
  virtual string print();

private:
  string type_;
};
