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
#include <string.h>
#include "graph.h"
#include "stack.cpp"
#include "queue.cpp"

graph::graph()
{
	count = 0;
	first = NULL;

}


void graph::insertVertex(user data)
{
	vertex* newPtr;
	vertex* locPtr;
	vertex* prePtr;
	newPtr = new vertex;

	newPtr->pNextVertex = NULL;
	newPtr->data = data;
	newPtr->inDegree = 0;
	newPtr->outDegree = 0;
	newPtr->pArc = NULL;
	count++;

	locPtr = first;
	if(!locPtr)
		first = newPtr;
	else
	{
		prePtr = NULL;
		while(locPtr && strcmp(data.name,locPtr->data.name)!=0)
		{
			prePtr = locPtr;
			locPtr = locPtr->pNextVertex;
		}

		if(!prePtr)
			first = newPtr;
		else
			prePtr->pNextVertex = newPtr;
		newPtr->pNextVertex = locPtr;
	}
	return ;
}


int graph::insertEdge(char pFromKey[20], char pToKey[20])
{
	arc* newPtr;
	arc* arcPrePtr;
	arc* arcWalkPtr;
	vertex* vertFromPtr;
	vertex* vertToPtr;

	newPtr = new arc;

	vertFromPtr = first;

	while(vertFromPtr && strcmp(pFromKey,vertFromPtr->data.name)!=0)
		vertFromPtr = vertFromPtr->pNextVertex;

	if(!vertFromPtr || strcmp(pFromKey,vertFromPtr->data.name)!=0)
		return -2;

	vertToPtr = first;

	while(vertToPtr && strcmp(pToKey,vertToPtr->data.name)!=0)
		vertToPtr = vertToPtr->pNextVertex;

	if(!vertToPtr || strcmp(pToKey,vertToPtr->data.name)!=0)
		return -3;

	++vertFromPtr->outDegree;
	++vertToPtr->inDegree;

	newPtr->destinition = vertToPtr;
	if(!vertFromPtr->pArc)
	{
		vertFromPtr->pArc = newPtr;
		newPtr->pNextArc = NULL;
		return 1;
	}

	arcPrePtr = NULL;
	arcWalkPtr = vertFromPtr->pArc;
	while(arcWalkPtr && strcmp(pToKey,arcWalkPtr->destinition->data.name)!=0)
	{
		arcPrePtr = arcWalkPtr;
		arcWalkPtr = arcWalkPtr->pNextArc;
	}

	if(!arcPrePtr)
		vertFromPtr->pArc = newPtr;
	else
		arcPrePtr->pNextArc = newPtr;
	newPtr->pNextArc = arcWalkPtr;
	return 1;
}


int graph::deleteVertex(user data)
{
	vertex* walkPtr;
	vertex* prePtr;

	if(!first)
		return -2;

	prePtr = NULL;
	walkPtr = first;
	while(walkPtr && strcmp(data.name,walkPtr->data.name)!=0)
	{
		prePtr = walkPtr;
		walkPtr = walkPtr->pNextVertex;
	}

	if(!walkPtr || strcmp(data.name,walkPtr->data.name)!=0)
		return -2;

	if(walkPtr->inDegree > 0 || walkPtr->outDegree > 0)
		return -1;

	if(!prePtr)
		first = walkPtr->pNextVertex;
	else
		prePtr->pNextVertex = walkPtr->pNextVertex;
	count--;
	delete walkPtr;
	return 1;
}


int graph::deleteEdge(char fromKey[20], char toKey[20])
{
	vertex* fromVertexPtr;
	vertex* toVertexPtr;
	arc* preArcPtr;
	arc* arcWalkPtr;

	if(!first)
		return -1;

	fromVertexPtr = first;

	while(fromVertexPtr && strcmp(fromKey,fromVertexPtr->data.name)!=0)
		fromVertexPtr = fromVertexPtr->pNextVertex;

	if(!fromVertexPtr || strcmp(fromKey,fromVertexPtr->data.name)!=0)
		return -2;

	if(!fromVertexPtr->pArc)
		return -3;

	preArcPtr = NULL;
	arcWalkPtr = fromVertexPtr->pArc;

	while(arcWalkPtr && strcmp(toKey,arcWalkPtr->destinition->data.name)!=0)
	{
		preArcPtr = arcWalkPtr;
		arcWalkPtr = arcWalkPtr->pNextArc;
	}

	if(!arcWalkPtr || strcmp(toKey,arcWalkPtr->destinition->data.name)!=0)
		return -3;

	toVertexPtr = arcWalkPtr->destinition;

	--fromVertexPtr->outDegree;
	--toVertexPtr->inDegree;

	if(!preArcPtr)
		fromVertexPtr->pArc = arcWalkPtr->pNextArc;
	else
		preArcPtr->pNextArc = arcWalkPtr->pNextArc;

	delete arcWalkPtr;
	return 1;
}


int graph::depthFirstTraversal(user *u,char data[20], int c)
{
	int flag =0;
	vertex* walkPtr;
	vertex* vertexPtr;
	vertex* vertToPtr;
	stack<vertex*> Stack;
	arc* arcWalkPtr;

	if(!first)
		return 0;
	walkPtr=first;
	while(walkPtr)
	{
		walkPtr->processed=0;
		walkPtr=walkPtr->pNextVertex;
	}
	walkPtr=first;
	while(walkPtr)
	{
		if(walkPtr->processed<2)
		{
			if(walkPtr->processed<1)
			{
				Stack.push(walkPtr);
				walkPtr->processed=1;
			}
		}

		while(!Stack.isEmpty())
		{
			vertexPtr=Stack.pop();
			flag=process(vertexPtr,data,c);
			vertexPtr->processed=2;
			if(flag==1)
			{
				*u=vertexPtr->data;
				return flag;
			}

			arcWalkPtr = vertexPtr->pArc;
			while(arcWalkPtr)
			{
				vertToPtr = arcWalkPtr->destinition;
				if(vertToPtr->processed==0)
				{
					Stack.push(vertToPtr);
					vertToPtr->processed=1;
				}
				arcWalkPtr=arcWalkPtr->pNextArc;
			}
		}
		walkPtr=walkPtr->pNextVertex;
	}
	return flag;
}

int graph::process(vertex* vertexPtr, char data2[20], int c)
{
	int flag1,flag2,a,friendCount=0;
	arc* arcWalkPtr;
	switch(c)
	{
		case 1://login dfs traversal
			if(strcmp(vertexPtr->data.name,data2)==0)
				return 1;
			break;

		case 2://pending friend request dfs traversal
			if(strcmp(data2,vertexPtr->data.name)==0)
				return 3;
			else
			{
				flag1=isEdgePresent(data2,vertexPtr->data.name);
				if(flag1==0)
				{
					flag2=isEdgePresent(vertexPtr->data.name,data2);
					if(flag2==1)
					{
						cout<<"\n\n\t\t\t"<<vertexPtr->data.name<<"\n\n";
						cout<<"\t\t\tDo you want to accept friend request::\n\t\t\tPress 1 - for Confirm\n\t\t\tPress 2 - for Not now\n\t\t\t-->";
						cin>>c;
						if(c==1)
						{
							insertEdge(data2,vertexPtr->data.name);
							cout<<"\n\n\t\t\tSUCCESSFULLY ACCEPTED FRIEND REQUEST";
						}
						else
						{
							deleteEdge(vertexPtr->data.name,data2);
							cout<<"\n\n\t\t\tFRIEND REQUEST REJECTED SUCCESSFULLY";
						}
					}
					else
					{
						return 3;
					}
				}
				else
				{
					return 3;
				}
			}
			break;

		case 3://Friend request dfs traversal
				if(strcmp(data2,vertexPtr->data.name)==0)
					return 3;
				else
				{
					flag1=isEdgePresent(data2,vertexPtr->data.name);
					if(flag1==0)
					{
						flag2=isEdgePresent(vertexPtr->data.name,data2);
						if(flag2==0)
						{
							cout<<"\n\n\t\t\t"<<vertexPtr->data.name<<"\n\n";
							cout<<"\t\t\tDo you want to send friend request::\n\t\t\tPress 1 - for yes\n\t\t\tPress 2 - for no\n\t\t\t-->";
							cin>>c;
							if(c==1)
							{
								insertEdge(data2,vertexPtr->data.name);
								cout<<"\n\n\t\t\tSUCCESSFULLY SENT FRIEND REQUEST";
							}
							else
								return 3;

						}
						else
							return 3;
					}
					else
						return 3;
				}
				break;

		case 4://Displaying friends dfs traversal
			if(strcmp(data2,vertexPtr->data.name)==0)
				return 3;
			else
			{
				flag1=isEdgePresent(data2,vertexPtr->data.name);
				if(flag1==1)
				{
					flag2=isEdgePresent(vertexPtr->data.name,data2);
					if(flag2==1)
					{
						cout<<"\n\n\t\t\t\t"<<vertexPtr->data.name;
					}
					else
						return 3;
				}
				else
					return 3;
			}
			break;

		case 5://Deactivating account dfs traversal
			if(strcmp(data2,vertexPtr->data.name)==0)
				return 3;
			else
			{
				flag1=isEdgePresent(data2,vertexPtr->data.name);
				if(flag1)
					deleteEdge(data2,vertexPtr->data.name);
				flag2=isEdgePresent(vertexPtr->data.name,data2);
				if(flag2)
					deleteEdge(vertexPtr->data.name,data2);
			}
			break;

		case 6://Deleting Friend dfs traversal
			if(strcmp(data2,vertexPtr->data.name)==0)
				return 3;
			else
			{
				flag1=isEdgePresent(data2,vertexPtr->data.name);
				if(flag1==1)
				{
					flag2=isEdgePresent(vertexPtr->data.name,data2);
					if(flag2==1)
					{
						cout<<"\n\n\t\t\t\t"<<vertexPtr->data.name<<"\n\n";
						cout<<"\t\t\tDo you want to delete friend ::\n\t\t\tPress 1 - for yes\n\t\t\tPress 2 - for no\n\t\t\t-->";
						cin>>c;
						if(c==1)
						{
							deleteEdge(data2,vertexPtr->data.name);
							deleteEdge(vertexPtr->data.name,data2);
							cout<<"\n\n\t\t\tSUCCESSFULLY DELETED FRIEND";
						}
						else
							return 3;


					}
					else
						return 3;
				}
				else
					return 3;
			}
			break;

		case 7://max Comment bfs traversal
			a=vertexPtr->data.commentCount;
			return a;
			break;

		case 8://max friends bfs traversal
			arcWalkPtr=vertexPtr->pArc;
			while(arcWalkPtr!=NULL)
			{
				arcWalkPtr=arcWalkPtr->pNextArc;
				friendCount++;
			}
			return friendCount;
			break;

		case 9:
			if(strcmp(vertexPtr->data.name,data2)==0)
				vertexPtr->data.commentCount++;
			break;

	}
	return 0;
}


int graph::breadthFirstTraversal(user* u, int c)
{
	int a,max=0;
	vertex* walkPtr;
	vertex* vertexPtr;
	vertex* vertToPtr;
	queue<vertex*> Queue(20);
	arc* arcWalkPtr;

	if(!first)
		return 0;

	walkPtr=first;
	while(walkPtr)
	{
		walkPtr->processed=0;
		walkPtr=walkPtr->pNextVertex;
	}

	walkPtr=first;

	while(walkPtr)
	{
		if(walkPtr->processed<2)
		{
			if(walkPtr->processed<1)
			{
				Queue.enqueue(walkPtr);
				walkPtr->processed=1;
			}
		}

		while(!Queue.isEmpty())
		{
			vertexPtr=Queue.dequeue();
			a=process(vertexPtr,vertexPtr->data.name,c);
			if(a>max)
			{
				max=a;
				*u=vertexPtr->data;
			}

			vertexPtr->processed=2;

			arcWalkPtr=vertexPtr->pArc;
			while(arcWalkPtr)
			{
				vertToPtr=arcWalkPtr->destinition;
				if(vertToPtr->processed==0)
				{
					Queue.enqueue(vertToPtr);
					vertToPtr->processed=1;
				}
				arcWalkPtr=arcWalkPtr->pNextArc;
			}
		}
		walkPtr=walkPtr->pNextVertex;
	}
	return max;
}


int graph::isEdgePresent(char pFromKey[20], char pToKey[20])
{
	vertex* vertFromPtr;
	vertex* vertToPtr;
	arc* arcWalkPtr=NULL;

	vertFromPtr = first;

	while(vertFromPtr && strcmp(pFromKey,vertFromPtr->data.name)!=0)
		vertFromPtr = vertFromPtr->pNextVertex;

	if(!vertFromPtr || strcmp(pFromKey,vertFromPtr->data.name)!=0)
		return -2;

	vertToPtr = first;

	while(vertToPtr && strcmp(pToKey,vertToPtr->data.name)!=0)
		vertToPtr = vertToPtr->pNextVertex;

	if(!vertToPtr || strcmp(pToKey,vertToPtr->data.name)!=0)
		return -3;

	arcWalkPtr=vertFromPtr->pArc;
	if(arcWalkPtr==NULL)
		return 0;
	while(arcWalkPtr!=NULL)
	{
		if(arcWalkPtr->destinition==vertToPtr)
			return 1;
		arcWalkPtr=arcWalkPtr->pNextArc;
	}
	return 0;

}

graph::~graph()
{

}

