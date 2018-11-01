#include <iostream>
#include "OfficeHour.h"

/*
Given the current Office Hour queue and the currently on-duty staffers, return
how long the nth student will need to wait before a Staffer can reach them
Return -1 if there are no staff available to help the nth student

@param queue A queue containing the students currently waiting for help
@param onDutyStaff  A vector of Staffers currently on duty
@param nthStudent   The student for whom we are calculating a wait time
@return             How many minutes the nth student will have to wait before getting help
*/
int waitTime(queue<Student> queue, vector<Staffer> onDutyStaff, int nthStudent) {
    // Your code here!
    //return -1;
    // int wait_time = 0;
    // //int i = 0;
    // for(int i = 0; i < queue.size(); i++){
    //   for(int j = 0; j < onDutyStaff.size(); j++){
    //     if(onDutyStaff[j].getEnergyLevel() <= 0){
    //       onDutyStaff.erase(onDutyStaff.begin() + j);
    //     }
    //   }//done remove staff member
    queue<Student> queue1 = queue;
    vector<Staffer> vector1 = onDutyStaff;
    int nthStudent1 = nthStudent;
    return -1;



    }
}
