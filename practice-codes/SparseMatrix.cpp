/*
  Developer : Bhagesh Dhankher
  Objective : Sparse matrix implementation
  
*/
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<stdio.h>
using namespace std;
int r=0;
int c=0;

struct node
{
	int value;
	node *rownext;
	node *columnnext;

};
int main()
{
	int p,q,w=0;
	string s;
	string l;
	fstream f;
	int a[10][10];
	f.open("m.dat");
	if(!f)
	{
		cout<<"File cannot be openned";
	}
	int x;
	while(f.good())
	{
		while(getline(f,l))
		{
			stringstream stream(l);
			c=0;
			while(stream>>x)
			{
				a[r][c]=x;
				c++;
			}
			r++;
		}
	}
	node *head,*row,*column,*t;
	head =((node*)malloc(sizeof(node)));
	head->rownext=NULL;
	head->columnnext=NULL;
	t=head;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(a[i][j]==0)
			{
				cout<<"0\t";
			}
			else
			{
				p=i;
				q=j;
				w++;
				break;
			}
		}
			if(w!=0)
			{
				row = ((node*)malloc(sizeof(node)));
				row->rownext=NULL;
				head->rownext=row;
				head=row;
				for(int k=q;k<c;k++)
				{
					if(a[p][k]==0)
						cout<<"0\t";
					else
					{
						column = ((node*)malloc(sizeof(node)));
						column->value=a[p][k];
						column->columnnext=NULL;
						head->columnnext=column;
						head=column;
						cout<<column->value<<"\t";
					}

				}
				head=row;
				w=0;
			}
				cout<<"\n";
		}
}
