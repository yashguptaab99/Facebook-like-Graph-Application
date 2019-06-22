//===============================================================================================
// Class            : SE9
// Batch            : F9
// Roll No.         : 23121
// Author           : Yash Gupta
// Assignment No.   : 1
// Problem Statement: Consider a friends‘ network on face book social web site. Model it as a
//					  graph to represent each node as a user and a link to represent the friend
//					  relationship between them. Store data such as date of birth, number of
//					  comments for each user.
//
// 					  1. Find who is having maximum friends
//					  2. Find who has post maximum and minimum comments
//					  3. Find users having birthday in this month
//
//					  Hint: (Use adjacency list representation and perform DFS and BFS
//					        traversals)
//===============================================================================================


#include <iostream>
using namespace std;
#include"queue.h"

template<class T>
queue<T> :: queue(int n)
{
	size = n;
	data = new T[n];
	count = 0;
	front = -1;
	rear = -1;
}

template<class T>
void queue<T> :: enqueue(T temp)
{
	if(front == -1 && rear == -1)
	{
		data[0] = temp;
		front = 0;
		rear = 0;
		count++;
	}
	else if(rear == size-1 && isFull()!=1 )
	{
		data[0] = temp;
		rear = 0;
		count++;
	}
	else if(isFull()!=1)
	{
		rear++;
		data[rear] = temp;
		count++;
	}
}

template<class T>
T queue<T> :: dequeue()
{
	if(isEmpty() == 1)
	{
		cout<<"Cannot dequeue from empty queue !";
	}
	else if(front != size-1)
	{
		front++;
		count--;
		return data[front-1];
	}
	else if(front == size-1)
	{
		front = 0;
		count--;
		return data[size-1];
	}
}

template<class T>
int queue<T> :: isEmpty()
{
	if(front == -1 && rear == -1)
	{
		return 1;
	}
	else if(count == 0)
	{
		return 1;
	}
	else
		return 0;
}

template<class T>
int queue<T> :: isFull()
{
	if(count == size)
	{
		return 1;
	}
	else
		return 0;
}

template<class T>
queue<T> :: ~queue()
{
	delete []data;
}
