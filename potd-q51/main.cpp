#include "potd.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {
	// test your code here!
	vector<string> good_vector = topThree("in1.txt");
	for(auto &it : good_vector){
		cout<<it<<endl;
	}
	return 0;
}
