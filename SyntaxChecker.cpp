//Jane Yang
//2317614
//huayang@chapman.edu
//CPSC350-01
//Assignment 3

#include "SyntaxChecker.h"
SyntaxChecker::SyntaxChecker()
{
  m_line = 0;
  myStack = new GenStack<char>(10);
  expected = '\0';
  m_actual = '\0';
  //totalLine = 0;
}

//read in the file
int SyntaxChecker::readFile(string input)
{
  std::ifstream file;
  file.open(input);
  //int totalLine;
  if(file.is_open())
  {
    std::string line;
    while(std::getline(file,line))
    {
      m_line++;
      for(char x : line)
      {
        if(x=='('||x=='['||x=='{')
        {
          //add to array
          myStack->push(x);
          //cout<<"x: "<<x<<endl;
        }

        else if(x==')'||x==']'||x=='}')
        {
          //cout<<m_line<<endl;
          m_actual = myStack->pop();
          //cout<<m_actual<<endl;
          if(x==')')
          {
            expected = '(';
          }
          else if(x==']')
          {
            expected = '[';
          }
          else
          {
            expected = '{';
          }
          if(m_actual!=expected)
          {
            return m_line;
          }
        }
      }
    }
  }
  if(myStack->isEmpty())
  {
    return -1;
  }
  return -2;
  file.close();
}

void SyntaxChecker::printStack()
{
  while(!myStack->isEmpty())
  {
    cout<<myStack->pop()<<" ";
  }
  cout<<"\n";
}

int SyntaxChecker::getm_line()
{
  return m_line;
}

/*
void SyntaxChecker::totalLine(string input)
{
  totalLine = 0;
  std::ifstream file;
  file.open(input);
  if(file.is_open())
  {
    while(std::getline(file,line))
    {
      totalLine++;
    }
  }
  file.close();
}
/*
void SyntaxChecker::reverseFile(string filename)
{
  std::ofstream out;
  out.open(filename);
  std::vector<std::string> line_in_reverse;
  while(std::getline(file,line))
  {
    line_in_reverse.insert((line_in_reverse.begin(),line))；
  }
  for(int i = 0;i<line_in_reverse.size();i++)
  {
    out<<line_in_reverse.at(i)<<endl;
  }
}*/
int SyntaxChecker::process(string input)
{
  std::ifstream file;
  file.open(input);
  int position = 1;
  if(file.is_open())
  {
    std::string line;
    while(std::getline(file,line))
    {
      //if the last line of the file is not }
      for(int i = 0;i<line.size();i++)
      {
        if(position==m_line&&i==line.size()-1)
        {
          if(line[i]!='}')
          {
            return -2;
          }
        }
        if(line[i]==')')
        {
          expected = '(';
          m_actual = myStack->pop();
          if(m_actual!='(')
          {
            //position = totalLine-position;
            return position;
          }
        }
        else if(line[i]==']')
        {
          expected = '[';
          m_actual = myStack->pop();
          if(m_actual!='[')
          {
            //position = totalLine-position;
            return position;
          }
        }
        else if(line[i]=='}')
        {
          expected = '{';
          m_actual = myStack->pop();
          if(m_actual!='{')
          {
            //position = totalLine-position;
            return position;
          }
        }
      }
      ++position;
    }
  }
  if(myStack->isEmpty())
  {
    return -1;
  }
  return -2;
}

char SyntaxChecker::missingChar()
{
  if(m_actual =='(')
  {
    return ')';
  }
  else if(m_actual == '[')
  {
    return ']';
  }
  return '}';
}

char SyntaxChecker::getExp()
{
  return expected;
}

char SyntaxChecker::getAct()
{
  return m_actual;
}
