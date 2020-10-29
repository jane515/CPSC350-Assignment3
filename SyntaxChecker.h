//Jane Yang
//2317614
//huayang@chapman.edu
//CPSC350-01
//Assignment 3
#include <iostream>
#include <sstream>
#include<fstream>
#include<string>
#include<cmath>
#include<algorithm>
#include<thread>
#include<chrono>
#include<vector>
#include "GenStack.h"
using namespace std;

class SyntaxChecker{

public:
  SyntaxChecker();
  ~SyntaxChecker();

  int readFile(string input);
  int process(string input);
  char getExp();
  char getAct();
  int getm_line();
  char missingChar();
  void printStack();
  void totalLine();
  //void reverseFile(string filename);


  int m_line;
  GenStack<char>* myStack;
  char expected;
  char m_actual;
  //int totalLine;
};
