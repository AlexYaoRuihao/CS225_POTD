#include "Hash.h"
#include <string>
#include <algorithm>

using namespace std;

unsigned long bernstein(std::string str, int M)
{
	unsigned long b_hash = 5381;
	//Your code here
	// for(auto it : str){
	// 	b_hash *= 33;
	// 	b_hash += (int)*it;
	// }
	for(unsigned i = 0; i < str.length(); i++){
		b_hash *= 33;
		b_hash += str[i];
	}
	return b_hash % M;
}

std::string reverse(std::string str)
{
    std::string output = "";
	//Your code here
	for(unsigned i = 0; i < str.length() / 2; i++){
		swap(str[i], str[str.length() - i - 1]);
	}
	return str;
}
