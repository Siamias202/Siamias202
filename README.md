/*
 Kawsar Ahmed Siam
 Damian Forever
 IUT CSE-19
*/
#include<bits/stdc++.h>
using namespace std;

#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long



 
#define maxsize 1001
ll arr[maxsize];

ll front=-1;
ll rear=-1;

void enqueue(ll x)
{
    if(rear==maxsize-1)
    {
    	cout<<"Overflow"<<endl;
    	return;
    }
    else if(rear ==-1 && front==-1)
    {
        front=rear=0;
        arr[rear]=x;
    }
    else
    {
    	rear++;
    	arr[rear]=x;
    }
}

void dequeue()
{
	if(rear==-1 && front==-1)
	{
		cout<<"Queue is empty"<<endl;
		return;
	}
	else if(front==rear)
	{
       rear=front=-1;
	}
	else
	{
		//cout<<"Dequeued Element is: "<<arr[front]<<endl;
		front++;
	}
}

void display()
{
	if(front==-1 && rear==-1)
	{
		cout<<"Queue is empty"<<endl;
		return;
	}
	else 
	{
		cout<<"Queue :";
		for(ll i=front;i<=rear;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
}

void peek()
{
	if(front==-1 && rear==-1)
	{
		cout<<"Queue is empty"<<endl;
		return;
	}
	else
	{
		cout<<arr[front]<<endl;
	}
}

void isfull()
{
	if(rear==maxsize-1)
    {
    	cout<<"Queue is full"<<endl;
    	return;
    }
    else
    {
    	cout<<"Queue is not full"<<endl;
    }
}

void isempty()
{
	if(front==-1 && rear==-1)
	{
		cout<<"Queue is empty"<<endl;
		return;
	}
	else
	{
		cout<<"Queue is not empty"<<endl;
		return;
	}
}

int main()
{

   init();
   enqueue(1);
   enqueue(2);
   display();
   dequeue();
   display(); 
   
}
