#include "Swiftcipher.h"
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/* Swift Cipher: Frequency of words in a file corresponds to its location in the decrypted sentence */
string decipherer(string filename) {
	//return "";
	string line;
	ifstream infile (filename);

	vector<string> good_vector;

	if (infile.is_open()) {
			while (getline(infile, line)) {
					// do things
					good_vector.push_back(line);
			}
	}
	// for(unsigned i = 0; i < good_vector.size(); i++){
	//   cout<<good_vector[i]<<endl;
	// }
	map<string, int> good_map;
	for(unsigned i = 0; i < good_vector.size(); i++){
		good_map[good_vector[i]]++;
	}

	map<int, string> good_map_reverse;
	for(auto &it : good_map){
		good_map_reverse[it.second] = it.first;
	}

	// for(auto &it1 : good_map_reverse){
	// 	cout<<it1.first<<": "<<it1.second<<endl;
	// }
	string ret = "";
	for(auto &it2 : good_map_reverse){
		ret += it2.second;
		ret += ' ';
	}
	ret.pop_back();

	infile.close();
	return ret;
}
