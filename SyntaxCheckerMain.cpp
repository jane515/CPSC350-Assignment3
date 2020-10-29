//Jane Yang
//2317614
//huayang@chapman.edu
//CPSC350-01
//Assignment 3

#include "SyntaxChecker.h"

int main(int argc, char const *argv[])
{
  while(true)
  {
    cout<<"enter the name of input file: "<<endl;
    std::string filePath;
    cin>>filePath;
    SyntaxChecker *check = new SyntaxChecker();
    int number = check->readFile(filePath);
    //check->reverseFile("jane.txt")
    //check->printStack();
    //int number = check->process(filePath);
    char exp = check->getExp();
    char act = check->getAct();
    //cout<<"act"<<act<<endl;
    //cout<<"exp"<<exp<<endl;
    if(number!=-1&&number!=-2)
    {
      cout<<"There is a missing delimiter before line: "<<number<<endl;
      cout<<"Need "<<check->missingChar()<<endl;
      //cout<<"missing closing part for "<<act<<endl;
      cout<<"Found "<<exp<<endl;
      //";Expect "<<exp<<" and found "<<act<<", exiting program now"<<endl;
      break;
    }
    else if(number == -1)
    {
      cout<<"there is no syntax error in the file, would you like to analysis anothe file? 'y' or 'n'"<<endl;
      char answer;
      cin>>answer;
      if(answer=='n'||answer=='N')
      {
        cout<<"Bye"<<endl;
        break;
      }
    }
    else
    {
      cout<<"reach the end of file，missing: "<<check->missingChar()<<endl;
      break;
    }
  }
  return 0;
}
