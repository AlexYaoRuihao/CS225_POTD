#include<vector>
#include<string>


vector<string> NoProblem(int start, vector<int> created, vector<int> needed) {
    // your code here
    int month = created.size();
    int total_problem = start;
    vector<string> good_vector;

    string no_problemY = "No problem! :D";
    string no_problemN = "No problem. :(";

    for(int i = 0; i < month; i++){
      //total_problem += created[i];
      if(total_problem >= needed[i]){
        good_vector.push_back(no_problemY);
        total_problem-=needed[i];
      }
      else{
        good_vector.push_back(no_problemN);
      }
      total_problem += created[i];
    }
    return good_vector;
}
