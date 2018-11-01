#include <iostream>
#include "potd.cpp"

using namespace std;

int main() {
    unordered_map<string, int> mapA({
                                    {"common", 13},
                                    {"unique_a", 13}
                                    });
    unordered_map<string, int> mapB({
                                    {"common", 17},
                                    //{"common", 18},
                                    //{"common", 18},
                                    {"unique_b", 17}
                                    });

    unordered_map<string, int> common = common_elems(mapA, mapB);

    // check your outputs here
    for(auto &it : common){
      cout<<it.first<<" "<<it.second<<endl;
    }
}
// int main ()
// {
//   std::unordered_map<std::string,std::string> mymap;
//
//   // populating container:
//   mymap["U.S."] = "Washington";
//   mymap["U.S."] = "London";
//   mymap["France"] = "Paris";
//   mymap["France"] = "fuck";
//   mymap["Russia"] = "Moscow";
//   mymap["China"] = "Beijing";
//   mymap["Germany"] = "Berlin";
//   mymap["Japan"] = "Tokyo";
//
//   // erase examples:
//   mymap.erase ( mymap.begin() );      // erasing by iterator
//   //mymap.erase ("France");             // erasing by key
//   //mymap.erase ( mymap.find("China"), mymap.end() ); // erasing by range
//
//   // show content:
//   for ( auto& x: mymap )
//     std::cout << x.first << ": " << x.second << std::endl;
//
//   return 0;
// }
