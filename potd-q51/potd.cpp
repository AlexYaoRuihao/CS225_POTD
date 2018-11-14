#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <limits.h>

using namespace std;


vector<string> topThree(string filename) {
    string line;
    ifstream infile (filename);
    vector<string> ret;

    vector<string> input;
    if (infile.is_open()) {
        while (getline(infile, line)) {
            // do things
            input.push_back(line);
        }
    }
    // for(unsigned i = 0; i < input.size(); i++){
    //   cout<<input[i]<<endl;
    // }
    map<string, int> good_map;
    for(unsigned i = 0; i < input.size(); i++){
      good_map[input[i]]++;
    }

    pair<int, string> x, y, z;
    x.first = y.first = z.first = INT_MIN;

    for(auto &it : good_map){
      if(it.second > x.first){
        z = y;
        y = x;

        x.first = it.second;
        x.second = it.first;
      }
      else if(it.second > y.first){
        z = y;

        y.first = it.second;
        y.second = it.first;
      }
      else if(it.second > z.first){
        z.first = it.second;
        z.second = it.first;
      }
    }

    ret.push_back(x.second);
    ret.push_back(y.second);
    ret.push_back(z.second);

    infile.close();
    return ret;
}
