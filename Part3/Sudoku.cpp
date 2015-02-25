//Brandon Aubrey
//Driver for templated sudoku puzzle
//2/24/2015

#include <iostream>
#include <string>
#include "Puzzle.h"
using namespace std;

int main()
{
  Puzzle<int> sudoku("sudoku.txt");
  sudoku.display();
  cout << endl;
  int val = '1';
  int row, col;  
  
  while(val != '0' && !sudoku.finished())
  {
    cout << "Type number you wish to place (1-9) or 0 to quit: ";
    cin >> val;
    if(val == 0)
      break;
    else if(val > 0 && val <= 9)
    {
      cout << endl << "Enter (row col) both in range 0-8:";
      cin >> row >> col;
      if(row < 0 || col < 0 || row > 8 || col > 8)
      {
        cout << "Invlaid coord" << endl;
      }
      else
        sudoku.inputValue(val, row, col);
    }
    sudoku.display();
    cout << endl;
  }
  return 0;
}
