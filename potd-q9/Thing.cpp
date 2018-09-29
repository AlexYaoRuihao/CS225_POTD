// Your code here!
#include "Thing.h"
#include <iostream>

#include <string>
using namespace std;

namespace potd{
  Thing::Thing(int size){
    props_max_ = size;
    properties_ = new string[size];
    values_ = new string[size];
    props_ct_ = 0;
  }

  Thing::Thing(const Thing &other){
    _copy(other);
  }

  void Thing::_copy(const Thing &other){
    props_ct_ = other.props_ct_;
    props_max_ = other.props_max_;
    //properties_ = new string(*(other.properties_));
    properties_ = new string[props_max_];
    //values_ = new string(*(other.values_));
    values_ = new string[props_max_];
    for(int i = 0; i < props_max_; i++){
      properties_[i] = other.properties_[i];
      values_[i] = other.values_[i];
    }

  }

  void Thing::_destroy(){
    if(properties_ != NULL){
      delete[] properties_;
      properties_ = nullptr;
    }
    if(values_ != NULL){
      delete[] values_;
      values_ = nullptr;
    }
  }

  Thing & Thing::operator=(const Thing &other){
    if(this != &other){
      _destroy();
      _copy(other);
    }
    return *this;
  }

  Thing::~Thing(){
    _destroy();
  }

  int Thing::set_property(string name, string value){
    for(int i = 0; i < props_max_; i++){

      if(properties_[i] == name){
          values_[i] = value;
          return i;
      }
    }
    //cout<<"work"<<endl;
    if(props_ct_>=props_max_){
      return -1;
    }
    int n = props_ct_;
    properties_[props_ct_] = name;
    values_[props_ct_] = value;
    props_ct_++;
    return n;

  }

  string Thing::get_property(string name){
    for(int i = 0; i < props_max_; i++){
      if(properties_[i] == name){
        return values_[i];
      }
    }
    return "";
  }
  //return "";
}
