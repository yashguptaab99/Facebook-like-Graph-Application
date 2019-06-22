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

#ifndef GRAPH_H_
#define GRAPH_H_

struct user
{
	char name[20]={};
	struct dob
	{
		int date=0;
		int month=0;
		int year=0;
	}birthdate;
	int commentCount=0;
};


class graph
{
	struct arc;

	struct vertex
	{
		vertex* pNextVertex;
		user data;
		int inDegree;
		int outDegree;
		arc* pArc;
		int processed;
	};

	struct arc
	{
		vertex* destinition;
		arc* pNextArc;
	};

	int count;
	vertex* first;

	public:
	graph();

	void insertVertex(user);
	int insertEdge(char[],char[]);
	int deleteVertex(user);
	int deleteEdge(char[],char[]);
	int depthFirstTraversal(user*,char[],int);
	int breadthFirstTraversal(user*,int);
	int process(vertex*,char[],int);
	int isEdgePresent(char[],char[]);
	virtual ~graph();
};

#endif /* GRAPH_H_ */









