// your code here
#include "Food.h"

void increase_quantity(Food *f){
  int new_quantity = f->get_quantity();
  f->set_quantity(new_quantity + 1);
}
