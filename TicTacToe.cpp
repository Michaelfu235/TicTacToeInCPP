#include <iostream>
#include <cstring>


using namespace std;


void printBoard(int x[3][3]);
bool checkWin(int x[3][3]);



int main(){
  int boards[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
  int xwins = 0;
  int ywins = 0;
  char input[80];
  bool whosturn = true;
  bool justkeepGoing = true;
  int row;
  int numofmoves = 0;
  
  printBoard(boards);
  cout << checkWin(boards) << endl;

  
  
  while(justkeepGoing == true){


    
    whosturn = true; // if it's true, its X's turn
    while(checkWin(boards) == false && numofmoves != 9){
      
      cin >> input;
      if(input[0] == 'q'){
	justkeepGoing = false;
	numofmoves = 9;
      }
      if(input[0] == 'A' || input[0] == 'B' || input[0] == 'C'){
	if(input[1] == '1' || input[1] == '2' || input[1] == '3'){
	  row = input[0] - 65;
	  
	  if(boards[row][input[1]-49] == 0){
	    
	    if(whosturn == true){
	      boards[row][input[1]-49] = 1;
	    } else {
	      boards[row][input[1]-49] = 2;
	    }
	    numofmoves += 1;
	    whosturn = !whosturn;
	  } else {
	    cout << "invalid input, please try again" << endl;
	  }
	} else {
	  cout << "invalid input, please try again" << endl;
	}

      } else {
	cout << "invalid input, please try again" << endl;
      }

      
      printBoard(boards);
      

    }
    if(whosturn == true && checkWin(boards) == true){
      xwins += 1;
      numofmoves = 0;
    } else if (checkWin(boards) == true){
      ywins += 1;
      numofmoves = 0;
    } else {
      numofmoves = 0;
    }
    for(int i = 0;i<3;i++){
      for(int j = 0;j<3;j++){
	boards[i][j] = 0;
      }
    }
    cout << "number of times x has won: " << ywins << endl;
    cout << "number of times o has won: " << xwins << endl;
    printBoard(boards);

    
    
  }
  
  
}

bool checkWin(int x[3][3]){
  if(x[0][0] == x[0][1] && x[0][1] == x[0][2] && x[0][0] != 0){
    return true;
  } else if (x[1][0] == x[1][1] && x[1][1] == x[1][2] && x[1][0] != 0){
    return true;
  } else if (x[2][0] == x[2][1] && x[2][1] == x[2][2] && x[2][0] != 0){
    return true;
  } else if (x[0][0] == x[1][0] && x[1][0] == x[2][0] && x[0][0] != 0){
    return true;
  } else if (x[0][1] == x[1][1] && x[1][1] == x[2][1] && x[0][1] != 0){
    return true;
  } else if (x[0][2] == x[1][2] && x[1][2] == x[2][2] && x[0][2] != 0){
    return true;
  } else if (x[0][0] == x[1][1] && x[1][1] == x[2][2] && x[0][0] != 0){
    return true;
  } else if (x[0][2] == x[1][1] && x[1][1] == x[2][0] && x[0][2] != 0){
    return true;
  }
  return false;
}


void printBoard(int x[3][3] ){
  char rows[3] = {'A','B','C'};
 
  cout << "  1  2  3" << endl;
  for(int i = 0;i<3;i++){
    cout << rows[i];
    for(int j = 0;j<3;j++){
      if(x[i][j] == 1){
	cout << " X ";
      } else if (x[i][j] == 2){
	cout << " O ";
      } else {
	cout << "   ";
      }
    }
    cout << endl;
  }
}
