#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

unordered_map<string, int> common_elems(unordered_map<string, int>& mapA,
                                        unordered_map<string, int>& mapB) {

    // your code here
    //return unordered_map<string, int>();
   unordered_map<string, int> good_unordered_map;
   vector<string> good_vector;
  //   //////////////////////////////////////////////////////////////////////
  //   for(unordered_map<string, int>::iterator it = mapA.begin(); it != mapA.end(); it++){
  //     cout<<it->first<<" "<<it->second<<endl;
  //   }
  //   //////////////////////////////////////////////////////////////////////
  //   for(unordered_map<string, int>::iterator itA = mapA.begin(); itA != mapA.end(); itA++){
  //     for(unordered_map<string, int>::iterator itB = mapB.begin(); itB != mapB.end(); itB++){
  //       if(itA->first == itB->first){
  //         good_unordered_map[itA->first]+=itB->second;
  //         //mapB.erase(itB);
  //       }
  //       //cout<<itB->first<<" "<<itB->second<<endl;
  //     }
  //     //////////////////////////////////////////////////////////////////////
  //     // for(unordered_map<string, int>::iterator it = good_unordered_map.begin(); it != good_unordered_map.end(); it++){
  //     //   cout<<it->first<<" "<<it->second<<endl;
  //     // }
  //     //////////////////////////////////////////////////////////////////////
  //     for(unordered_map<string, int>::iterator it = good_unordered_map.begin(); it != good_unordered_map.end(); it++){
  //       mapB.erase(it->first);
  //     }
  //     // if(mapA.count(itA->first) > 1){
  //     //   for(unordered_map<string, int>::iterator itA1 = mapA.begin(); itA1 != mapA.end(); ++itA1){
  //     //     if(itA->first == itA1->first){
  //     //       good_unordered_map[itA->first]+=itA1->second;
  //     //     }
  //     //   }
  //     //   mapA.erase(itA->first);
  //     // }
  //
  //     if(good_unordered_map.count(itA->first) > 0 || mapA.count(itA->first) > 1){
  //       for(unordered_map<string, int>::iterator itA1 = itA; itA1 != mapA.end(); itA1++){
  //         if(itA->first == itA1->first){
  //           good_unordered_map[itA->first]+=itA1->second;
  //         }
  //       }
  //       //mapA.erase(itA->first);
  //     }
  //     for(unordered_map<string, int>::iterator it = good_unordered_map.begin(); it != good_unordered_map.end(); it++){
  //       mapA.erase(it->first);
  //     }
  //     // if(good_unordered_map.count(itA->first) > 0){
  //     //   good_unordered_map[itA->first]+=itA->second;
  //     //   mapA.erase(itA);
  //     // }
  // }
    for(unordered_map<string, int>::iterator itA = mapA.begin(); itA != mapA.end(); itA++){
      for(unordered_map<string, int>::iterator itB = mapB.begin(); itB != mapB.end(); itB++){
        if(itA->first == itB->first){
          good_unordered_map[itA->first]+=itA->second;
          good_unordered_map[itA->first]+=itB->second;
          good_vector.push_back(itA->first);
          break;
        }
      }
    }

    for(unordered_map<string, int>::iterator it = good_unordered_map.begin(); it != good_unordered_map.end(); it++){
      mapA.erase(it->first);
      mapB.erase(it->first);
    }
    return good_unordered_map;
}













//////////
