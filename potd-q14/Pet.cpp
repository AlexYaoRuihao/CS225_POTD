// Pet.cpp
#include <iostream>
#include <string>
#include "Pet.h"
#include "Animal.h"

using namespace std;

Pet::Pet() : Animal(){
  //type_ = "cat";
  //food_ = "fish";
  name_ = "Fluffy";
  owner_name_ = "Cinda";
}

Pet::Pet(string animal, string food, string name, string owner_name) : Animal(animal, food){
  //type_ = animal;
  //food_ = food;
  name_ = name;
  owner_name_ = owner_name;
}

string Pet::getFood(){
  return food_;
}

void Pet::setFood(string food){
  food_ = food;
}

string Pet::getName(){
  return name_;
}

void Pet::setName(string name){
  name_ = name;
}

string Pet::getOwnerName(){
  return owner_name_;
}

void Pet::setOwnerName(string owner_name){
  owner_name_ = owner_name;
}

string Pet::print(){
  return "My name is " + getName();
}
