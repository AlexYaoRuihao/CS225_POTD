#include "potd.h"
#include <string>
#include <vector>
// Your code here!
using namespace std;

double sum(vector<double>::iterator start, vector<double>::iterator end){
  double sum = 0;
  vector<double>::iterator traverse = start;
  while(traverse != end){
    sum += *traverse;
    traverse++;
  }
  return sum;
}

vector<double>::iterator max_iter(vector<double>::iterator start, vector<double>::iterator end){
  vector<double>::iterator traverse = start;

  vector<double>::iterator Biggest = start;

  while(traverse != end){
    if(*traverse >= *Biggest){
      Biggest = traverse;
    }
    traverse++;
  }
  return Biggest;
}

void sort_vector(vector<double>::iterator start, vector<double>::iterator end){
  for(vector<double>::iterator i = start; i != end; i++){
    double temp = *max_iter(i, end);
    *max_iter(i, end) = *i;
    *i = temp;
  }
}
