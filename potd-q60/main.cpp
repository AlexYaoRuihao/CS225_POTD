#include <iostream>

using namespace std;

#include "2048.cpp"

int main() {

    int arr[4][4];
    int dir;

    for(int i=0; i<4; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }

    cin >> dir;

    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"input matrix: "<<endl;

    for(int i=0; i<4; i++) {
      cout << arr[i][0] << " " << arr[i][1] << " " << arr[i][2] << " " << arr[i][3] << endl;
    }


    run2048(arr,dir);

    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"output matrix: "<<endl;

    for(int i=0; i<4; i++) {
      cout << arr[i][0] << " " << arr[i][1] << " " << arr[i][2] << " " << arr[i][3] << endl;
    }

    // int i = 2;
    // int j = 3;
    // swap(i, j);
    // cout<<i<<" "<<j<<endl;
}
