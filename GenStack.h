//Jane Yang
//2317614
//huayang@chapman.edu
//CPSC350-01
//Assignment 3
#include <iostream>
#include <sstream>
#include<fstream>
#include<string>
#include<stack>
//#include<boost/any.hpp>
//#include<boost/type_index.hpp>

using namespace std;
template<class t>
class GenStack{
  public:
    int m_Size;
    int m_Top;
    t *m_Array;
    GenStack();
    GenStack(int size);
    ~GenStack();
    void push(t data);
    t pop();
    t peek();
    int getSize();
    bool isFull();
    bool isEmpty();
  };
    template<class t>
    GenStack<t>::GenStack()
    {
      m_Array= new t[10];
      m_Size = 0;
      m_Top = -1;
    }

    template<class t>
    GenStack<t>::GenStack(int size)
    {
      m_Array=new t[size];
      m_Size = size;
      m_Top = -1;
    }

    template<class t>
    GenStack<t>::~GenStack()
    {
      delete m_Array;
    }

    template<class t>
    void GenStack<t>::push(t data)
    {
      //if the stack is full, add ten more space to the stack
      if(isFull())
      {
        m_Size+=10;
        m_Array = new t[m_Size];
      }
      m_Array[++m_Top]=data;
    }
    //template<class t>
    //GenStack<t>::pop()
    template<class t>
    t GenStack<t>::pop()
    {
      if(isEmpty())
      {
        //cout<<"stack is empty"<<endl;
        cout<<"stack is empty"<<endl;
        exit(1);
      }
      return m_Array[m_Top--];
    }
    //template<class t>
  //GenStack<t>::peek()
    template<class t>
    t GenStack<t>::peek()
    {
      return m_Array[m_Top];
    }

    template<class t>
    int GenStack<t>::getSize()
    {
      return m_Size;
    }

    template<class t>
    bool GenStack<t>::isFull()
    {
      return (m_Top==m_Size-1);
    }

    template<class t>
    bool GenStack<t>::isEmpty()
    {
      return (m_Top==-1);
    }
