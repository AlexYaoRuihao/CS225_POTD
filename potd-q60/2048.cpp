using namespace std;

void swap(int &num1, int &num2){
  int temp;
  temp = num1;
  num1 = num2;
  num2 = temp;
}


void run2048(int puzzle[4][4], int dir) {

    // your code here

    //0-left
    //1-up
    //2-right
    //3-down

    // cout<<"test: "<<endl;
    // cout<<puzzle[1][3]<<endl;

    //going left
    if(dir == 0){
      //begin sliding
      for(int i = 0; i <= 3; i++){
        for(int j = 0; j <= 3; j++){

          if(puzzle[i][j] != 0){
            continue;
          }

          else{
            int temp_j = j;
            temp_j++;

            while(temp_j < 4){
              if(puzzle[i][temp_j] != 0){
                swap(puzzle[i][j], puzzle[i][temp_j]);
                break;
              }
              temp_j++;
            }

          }

        }
      }
      //begin merging
      for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
          
        }
      }
    }

    else if(dir == 1){//going up
      //begin sliding
      for(int j = 0; j <= 3; j++){
        for(int i = 0; i <= 3; i++){

          if(puzzle[i][j] != 0){
            continue;
          }

          else{
            int temp_i = i;
            temp_i++;

            while(temp_i < 4){
              if(puzzle[temp_i][j] != 0){
                swap(puzzle[i][j], puzzle[temp_i][j]);
                break;
              }
              temp_i++;
            }
          }

        }
      }
      //begin merging


    }

    else if(dir == 2){//going right
      //begin sliding
      for(int i = 0; i <= 3; i++){
        for(int j = 3; j >= 0; j--){

          if(puzzle[i][j] != 0){
            continue;
          }

          else{
            int temp_j = j;
            temp_j--;

            while(temp_j >= 0){
              if(puzzle[i][temp_j] != 0){
                swap(puzzle[i][j], puzzle[i][temp_j]);
                break;
              }
              temp_j--;
            }
          }

        }
      }
      //begin merging

    }

    else{//dir == 3, going down
      //begin sliding
      for(int j = 0; j <= 3; j++){
        for(int i = 3; i >= 0; i--){

          if(puzzle[i][j] != 0){
            continue;
          }

          else{
            int temp_i = i;
            temp_i--;

            while(temp_i >= 0){
              if(puzzle[temp_i][j] != 0){
                swap(puzzle[i][j], puzzle[temp_i][j]);
                break;
              }
              temp_i--;
            }
          }

        }
      }
      //begin merging


    }

}







//
