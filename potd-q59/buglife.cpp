#include<iostream>
#include<vector>

using namespace std;
// returns true if a counterexample is found
bool bugLife(int numBugs, vector<int> &b1, vector<int> &b2) {
    // code to make ignore the warning
    // delete and replace with your own.
    // int i = numBugs + b1[0] + b2[0];
    // if (i>0) return false; else return false;
    cout<<"Number of bugs: "<<numBugs<<endl;
    for(auto &it1: b1){
      cout<<it1<<" ";
    }
    cout<<endl;
    for(auto &it2: b2){
      cout<<it2<<" ";
    }
    cout<<endl;





    return true;
}
