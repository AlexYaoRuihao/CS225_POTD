// your code here
#include <iostream>
#include "q5.h"
#include "Food.h"


using namespace std;

int main(){
  Food *food = new Food();
  cout<<food->get_quantity()<<endl;
  increase_quantity(food);
  cout<<food->get_quantity()<<endl;
  return 0;
}
