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
using namespace std;

int main()
{
	facebook k;
	char c,user[20]={};
	do
	{
		cout<<"\n\n\t****Welcome Menu!****";
		cout<<"\n\n\t1.Create Account\n\n\t2.Login\n\n\t3.Person having maximum friends\n\n\t4.Person having maximum comments\n\n\t5.Exit";
		cout<<"\n\nEnter the choice::";
		cin>>c;

		switch(c)
		{
			case '1'://Creating account
				k.setdata();
				break;

			case '2'://login
				cout<<"\n\n\tEnter Name to login::";
				cin.ignore();
				cin.getline(user,20);
				k.login(user);
				break;

			case '3'://Finding maximum friends
				k.maxFriends();
				break;

			case '4'://finding maximum comments
				k.maxComment();
				break;

			case '5'://exit
				cout<<"\n\n\tExiting....";
				break;
			default:
				cout<<"\n\tPlease enter valid option!!!!";
				break;
		}
	}while(c!='5');

}
