#include <iostream>
#include <cstring>


using namespace std;

//functions
void printBoard(int x[3][3]);
bool checkWin(int x[3][3]);



int main(){
  //boards is the 2d array while the other variables are to keep track of things
  int boards[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
  int xwins = 0;
  int ywins = 0;
  char input[80];
  bool whosturn = true;
  bool justkeepGoing = true;
  int row;
  int numofmoves = 0;

  //first printing of the board
  printBoard(boards);
  

  
  //while justkeepGoing is true
  while(justkeepGoing == true){


    //whos turn keeps track of whos turn it is
    whosturn = true; // if it's true, its X's turn
    while(checkWin(boards) == false && numofmoves != 9){
      //while there isnt a win and there are not nine moves done, basically if there is no wins and no ties
      cin >> input;
      //input and if its q, then set justkeepGoing to false and the numofmoves to 9. Basically fake a tie to not affect the number of wins.
      if(input[0] == 'q'){
	justkeepGoing = false;
	numofmoves = 9;
      }
      //if the input starts with a, b, or c, and the second character is 1, 2, or 3:
      if(input[0] == 'A' || input[0] == 'B' || input[0] == 'C'){
	if(input[1] == '1' || input[1] == '2' || input[1] == '3'){
	  //row is the character subtracted by 65, to make it the correct integer
	  row = input[0] - 65;
	  //if the selected place on the board already equals 0 (unmarked so far), then set it to either 1 or 2, depending on whos turn it is. We know that from whosturn
	  if(boards[row][input[1]-49] == 0){
	    
	    if(whosturn == true){
	      boards[row][input[1]-49] = 1;
	    } else {
	      boards[row][input[1]-49] = 2;
	    }//after marking the board, add 1 to the numofmoves and switch the whosturn
	    numofmoves += 1;
	    whosturn = !whosturn;
	  } else if(numofmoves!= 9){
	    //if the board spot is already marked (and the numofmoves isn't equal to 9 to make the quitting less messy) then output its an invalid input. 
	    cout << "invalid input, please try again" << endl;
	  }
	} else if(numofmoves!=9){ //if the second letter isn't 1, 2, or 3, (and numofmoves isnt equal to 9 to make the quitting less messy) then output its an invalid input 
	  cout << "invalid input, please try again" << endl;
	}

      } else if(numofmoves != 9){ //if the first letter isn't A, B, or C, (and numofmoves isnt equal to 9 to make the quitting less messy) then output its an invalid input
	cout << "invalid input, please try again" << endl;
      }
      //after moving, if the numofmoves isnt 9 (if they haven't decided to quit), then print the board
      if(numofmoves != 9){
	printBoard(boards);
      }

    }//if it's X's turn and someone on the board has won, add 1 to xwins and reset numofmoves to 0
    if(whosturn == true && checkWin(boards) == true){
      xwins += 1;
      numofmoves = 0;
    } else if (checkWin(boards) == true){//if its not X's turn and someone on the board has won, add1 to ywins and reset numofmoves
      ywins += 1;
      numofmoves = 0;
    } else {//otherwise, if it's a tie, reset numofmoves to 0 and don't change the wins
      numofmoves = 0;
    }
    //reset the board by going through it and changing the values to 0
    for(int i = 0;i<3;i++){
      for(int j = 0;j<3;j++){
	boards[i][j] = 0;
      }
    }
    //output the number of times X has won and O has won. The names are a bit off (oops)
    cout << "number of times x has won: " << ywins << endl;
    cout << "number of times o has won: " << xwins << endl;
    //iff we're still going, print the new empty board. 
    if(justkeepGoing == true){
      printBoard(boards);
    }
    
    
  }
  
  
}
//to check wether or not there is a win, go through each row, column, and diagonal and check if the desired sqaures are all equal to eachother and not equal to 0. Basically check if there is a win method that has all the desired boxes have the same value, or the same user's mark, and that they aren't empty. If no win exists, return false. 
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

//to print the board, create a new list that has A, B, and C to make the printing easier, the output the top row. Then go through each of the rows of the 2d array and print accordingly. 
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
