//Brandon Aubrey
//Templated Sudoku puzzle implementation
//2/23/2015


#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "Puzzle.h"
using namespace std;

template<typename B>
Puzzle<B>::Puzzle(string in)
{
  ifstream infile;
  infile.open(in.c_str());
  for(int i = 0; i < 9; i++)
  {
    for(int j = 0; j < 9; j++)
    {
      infile >> value;
      board[i][j] = value;
    }
  }
}

template<typename B>
void Puzzle<B>::display()
{
  typename vector< vector<B> >::iterator i;
  typename vector<B>::iterator j;

  for(i = board.begin(); i != board.end(); i++)
  {
    for(j = (*i).begin(); j != (*i).begin(); j++)
    {
      cout << (*j); 
    }
    cout << endl;
  }
}
