// Animal.cpp
#include <iostream>
#include <string>
#include "Animal.h"

using namespace std;

Animal::Animal(){
  food_ = "fish";
  type_ = "cat";
}

Animal::Animal(string type, string food){
  food_ = food;
  type_ = type;
}

string Animal::getType(){
  return type_;
}

void Animal::setType(string type){
  type_ = type;
}

string Animal::getFood(){
  return food_;
}

void Animal::setFood(string food){
  food_ = food;
}

string Animal::print(){
  //cout<<"I am a "<<type_<<"."<<endl;
  return "I am a " + getType() + ".";
}
