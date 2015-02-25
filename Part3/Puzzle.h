//Brandon Aubrey
//Temlated sudoku game
//2/23/2015


#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

template <typename B>
class Puzzle
{
  public:
    Puzzle(string = "sudoku.txt");   //constuctor
    void display();                  //displays board to cout
    int checkBox(B, int);
    int checkRow(B, int);
    int checkCol(B, int);
    int getBox(int, int);
    int check(B, int, int);
    int finished();
    void inputValue(B, int, int);
  private:
    vector<vector<B> > board;        //sudoku game board, vector of vectors
};
#endif

//constructor
template<typename B>
Puzzle<B>::Puzzle(string in)
{
  B value;
  vector<B> tempVec;
  ifstream infile;
  infile.open(in.c_str());
  while(!infile.eof())
  {
    for(int j = 0; j < 9; j++)
    {
      infile >> value;
      tempVec.push_back(value);
    }
    board.push_back(tempVec);
    tempVec.clear();
  }
  board.pop_back();
}

//displays board to cout
template<typename B>
void Puzzle<B>::display()
{
  typename vector< vector<B> >::iterator i;
  typename vector<B>::iterator j;

  cout << " __________________" << endl << "|";
  for(i = board.begin(); i != board.end(); i++)
  {
    for(j = (*i).begin(); j != (*i).end(); j++)
    { 
      if((*j) == 0 || (*j) == '0')
        cout << "  ";
      else
        cout << (*j) << " ";
    }
    cout << "|" << endl << "|";
  }
  cout << "------------------|";
}

//checks if val is in col
template<typename B>
int Puzzle<B>::checkCol(B val, int col) 
{
  //typename vector< vector<B> >::iterator i;
  //typename vector<B>::iterator j;

  int good = 1;
  for(int i = 0; i < 9; i++)
  {
    if(board[col][i] == val)
      good = 0;
  }
  return good;
}

//checks if val is in row
template<typename B>
int Puzzle<B>::checkRow(B val, int row)
{
  //typename vector< vector<B> >::iterator i = board.begin() + row;
  //typename vector<B>::iterator j;

  int good = 1;
  for(int i = 0; i < 9; i++)
  {
    if (board[row][i] == val)
      good = 0;
  }
  return good;
}

//checks if val is in box
template<typename B>
int Puzzle<B>::checkBox(B val, int box)
{
  //typename vector< vector<B> >::iterator i;
  //typename vector<B>::iterator j;
  int i, j;
  int good = 1;
  switch(box)
  {
    case 0:
      for(i = 0; i < 3; i++)
      {
        for(j = 0; j < 3; j++)
        {
          if(board[i][j] == val)
            good = 0;
        }
      }
      break;
    case 1:
      for(i = 3; i < 6; i++)
      {
        for(j = 0; j < 3; j++)
        {
          if(board[i][j] == val)
            good = 0;
        }
      }
      break;
    case 2:
      for(i = 6; i < 9; i++)
      {
        for(j = 0; j < 3; j++)
        {
          if(board[i][j] == val)
            good = 0;
        }
      }
      break;
    case 3:
      for(i = 0; i < 3; i++)
      {
        for(j = 3; j < 6; j++)
        {
          if(board[i][j] == val)
            good = 0;
        }
      }
      break;
    case 4:
      for(i = 3; i < 6; i++)
      {
        for(j = 3; j < 6; j++)
        {
          if(board[i][j] == val)
            good = 0;
        }
      }
      break;
    case 5:
      for(i = 6; i < 9; i++)
      {
        for(j = 3; j < 6; j++)
        {
          if(board[i][j] == val)
            good = 0;
        }
      }
      break;
    case 6:
      for(i = 0; i < 3; i++)
      {
        for(j = 6; j < 9; j++)
        {
          if(board[i][j] == val)
            good = 0;
        }
      }
      break;
    case 7:
      for(i = 3; i < 6; i++)
      {
        for(j = 6; j < 9; j++)
        {
          if(board[i][j] == val)
            good = 0;
        }
      }
      break;
    case 8:
      for(i = 6; i < 9; i++)
      {
        for(j = 6; j < 9; j++)
        {
          if(board[i][j] == val)
            good = 0;
        }
      }
      break;
    default:
      good = 0;
      break;
  }
  return good;
}

//returns the box to check based on row and col
//boxes numbered as below
//0 1 2
//3 4 5
//6 7 8
template<typename B>
int Puzzle<B>::getBox(int row, int col)
{
  int box;
  if(row >= 0 && row <= 2)
  {
    if(col >= 0 && col <=2)
      box = 0;
    else if(col >= 3 && col <=5)
      box = 1;
    else
      box = 2;
  }
  else if(row >= 3 && row <= 5)
  {
   if(col >= 0 && col <=2)
      box = 3;
    else if(col >= 3 && col <=5)
      box = 4;
    else
      box = 5; 
  }
  else
  {
    if(col >= 0 && col <=2)
      box = 6;
    else if(col >= 3 && col <=5)
      box = 7;
    else
      box = 8;
  }
  return box;
}

//calls all checking functions and returns an int 
//corresponding to which if any failed or 0 if they all pass
template<typename B>
int Puzzle<B>::check(B val, int row, int col)
{
  int good;
  if(checkRow(val, row) == 0)
    good = 1;
  else if(checkCol(val, col) == 0)
    good = 2;
  else if(checkBox(val, getBox(row, col)) == 0)
    good = 3;
  else
    good = 0;
  return good;
}

//checks if there are any 0's on the board
//if there are game is not over
template<typename B>
int Puzzle<B>::finished()
{
  int i, j;
  for(i = 0; i < 9; i++)
  {
    for(j = 0; j != 9; j++)
    {
      if(board[i][j] == 0 || board [i][j] == '0')
        return 0;
    }
  } 
  return 1;
}

//checks if there is a value in the spot, calls check
//then either puts proper value in or displays error #
template<typename B>
void Puzzle<B>::inputValue(B val, int row, int col)
{
  if(board[row][col] != 0 && board[row][col] != '0')
    cout << "Cannot replace values already inputed" << endl;
  else if(check(val, row, col) == 0)
    board[row][col] = val;
  else
    cout << check(val, row, col) << endl;
}
