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

#ifndef QUEUE_H_
#define QUEUE_H_

template<class T>
class queue
{
	private:
		T *data;
		int count;
		int front;
		int rear;
		int size;
	public:

		queue(int n);//Constructor

		void enqueue(T temp);//FUnction to insert element into queue from rear
		T dequeue();//Function to delete element from fromt
		int isEmpty();//Function to see is queue empty or not
		int isFull();//Function to see is queue full or not

		~queue();

};


#endif /* QUEUE_H_ */
