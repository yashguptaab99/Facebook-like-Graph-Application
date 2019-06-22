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
#include "facebook.h"
#include <string.h>

using namespace std;

facebook::facebook()
{
	totalUser = 0;
}

void facebook::setdata()
{
	user person;
	cout<<"\n\n\tEnter Name::";
	cin.ignore();
	cin.getline(person.name,20);
	cout<<"\n\n\tEnter Birth date::";
	cout<<"\n\tDATE::";
	cin>>person.birthdate.date;
	cout<<"\n\tMONTH::";
	cin>>person.birthdate.month;
	cout<<"\n\tYEAR::";
	cin>>person.birthdate.year;
	g.insertVertex(person);
	totalUser++;
	cout<<"\n\n\t\t\tACCOUNT CREATED SUCCESSFULLY!!!!";
}


void facebook::login(char user1[20])
{
	user u;
	int flag;
	char c;
	flag=g.depthFirstTraversal(&u,user1,1);
	if(flag==1)
	{
		cout<<"\n\n\t\t\tSuccessFully Logged in!!!!";
		do
		{
			cout<<"\n\n\t\t1.See profile\n\n\t\t2.Pending Friend Requests\n\n\t\t3.Find Friends\n\n\t\t4.Comment\n\n\t\t5.Delete friend\n\n\t\t6.Deactivate Account\n\n\t\t7.Log Out";
			cout<<"\n\nEnter the Choice::";
			cin>>c;
			switch(c)
			{
				case '1'://Profile
					cout<<"\n\n\t\t\tName::";
					cout<<u.name;
					cout<<"\n\n\t\t\tBirthdate::";
					cout<<u.birthdate.date<<"/"<<u.birthdate.month<<"/"<<u.birthdate.year;
					cout<<"\n\n\t\t\tTotal Comment::"<<u.commentCount;
					cout<<"\n\n\t\t\tFriends-->";
					g.depthFirstTraversal(&u,user1,4);
					break;

				case '2'://Accept Friend request
					findFriend(u,user1,2);
					break;

				case '3'://Send friend request
					findFriend(u,user1,3);
					break;

				case '4'://Comment
					g.depthFirstTraversal(&u,user1,9);
					cout<<"\n\n\t\t\tSUCCESSFULLY COMMENTED ON POST";
					break;

				case '5'://Deleting Friend
					g.depthFirstTraversal(&u,user1,6);
					break;

				case '6'://Deactivate account
					g.depthFirstTraversal(&u,user1,5);
					g.deleteVertex(u);
					cout<<"\n\n\t\t\tACCOUNT DEACTIVATED SUCCESSFULLY!!!!!";
					return;
					break;

				case '7':
					cout<<"\n\n\t\t\tSigning Out....";
					break;

				default:
					cout<<"\n\n\t\tPlease enter valid choice!!!";
					break;


			}
		}while(c!='7');
	}
	else
		cout<<"\n\n\t\tLogin Failed!!! Please Enter valid login ID";

}


void facebook::findFriend(user u1, char user1[20],int c)
{
	switch(c)
	{
		case 2:
			cout<<"\n\n\t\tFRIEND REQUEST-->";
			g.depthFirstTraversal(&u1,user1,c);
			break;
		case 3:
			cout<<"\n\n\t\t\tADD FRIENDS-->";
			g.depthFirstTraversal(&u1,user1,c);
			break;

	}
}


void facebook::maxComment()
{
	user u;
	g.breadthFirstTraversal(&u,7);
	cout<<"\n\n\t\tMAX COMMENT DONE BY THIS USER-->";
	cout<<"\n\t\tName::"<<u.name;
	cout<<"\n\t\tComment Count::"<<u.commentCount;
}

void facebook::maxFriends()
{
	user u;
	int count=0;
	count=g.breadthFirstTraversal(&u,8);
	cout<<"\n\n\t\tTHIS USER HAVE MAX FRIEND-->";
	cout<<"\n\t\tName::"<<u.name;
	cout<<"\n\t\tFriend Count::"<<count;

}

facebook::~facebook()
{

}

