//============================================================================
// Class            : SE9
// Batch            : F9
// Roll No.         : 23121
// Author           : Yash Gupta
// Assignment No.   : 1
// Problem Statement: Create Binary tree and perform following operations:
//					  a.Insert
//                    b.Display
//					  c.Depth of a tree
//					  d.Display leaf-nodes
//					  e.Create a copy of a tree
//============================================================================
#include "stack.h"
#include <iostream>
#include <iomanip>

using namespace std;

template<class T>
stack<T>::stack()
{
	top = NULL;
	count=0;
}

template<class T>
stack<T>::~stack()
{

}

template<class T>
void stack<T>::push(T x)
{
	node* ptr;
	ptr = new node;
	ptr->data = x;
	ptr->link = top;
	top = ptr;
	count++;
}

template<class T>
T stack<T>::pop()
{
	node* temp;
	T x;
	if(isEmpty()==0)
	{
		temp = top;
		top = top->link;
		x = temp->data;
		count--;
		delete temp;
		return x;
	}
}


template<class T>
bool stack<T>::isEmpty()
{
	if(top==NULL)
		return 1;
	else
		return 0;
}



template<class T>
T stack<T>::peep()
{
	T x;
	if(isEmpty()==0)
	{
		x = top->data;
		return x;
	}
}


template<class T>
void stack<T>::display()
{
	node* temp;
	char stacklist[10];
	int i=0;
	if(isEmpty()==0)
	{
		temp=top;
		while(temp!=NULL)
		{
			stacklist[i]=temp->data;
			temp=temp->link;
			i++;
		}
		stacklist[i]='\0';
		cout<<setw(20)<<left<<stacklist;
	}
}

