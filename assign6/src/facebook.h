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


#ifndef FACEBOOK_H_
#define FACEBOOK_H_
#include "graph.h"

class facebook
{
	graph g;
	int totalUser;

	public:
	facebook();

	void setdata();
	void login(char[]);
	void findFriend(user,char[],int);
	void maxComment();
	void maxFriends();

	virtual ~facebook();
};

#endif /* FACEBOOK_H_ */
