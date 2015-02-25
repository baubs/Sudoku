//Brandon Aubrey
//Driver for templated sudoku
//2/23/2015


#include <iostream>
#include <string>
#include "Puzzle.h"
//using namespace std;

int main()
{
  //int sudoku puzzle
  Puzzle<int> iSudoku("sudoku.txt");
  iSudoku.display();
  //char sudoku
  Puzzle<char> cSudoku("wordoku.txt");

  cout << endl;
  cSudoku.display();
  return 0;
}
