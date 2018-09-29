// Pet.h
#include <string>
#include "Animal.h"

using namespace std;

class Pet : public Animal{
public:
  Pet();
  Pet(string animal, string food, string name, string owner_name);

  string getFood();
  void setFood(string food);

  string getName();
  void setName(string name);

  string getOwnerName();
  void setOwnerName(string owner_name);

  string print();

private:
  string name_;
  string owner_name_;
};
