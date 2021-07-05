/*
 Kawsar Ahmed Siam
 Damian Forever
 IUT CSE-19
*/
#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
#define pi acos(-1.0)
#define forn(i,n) for(int i=0 ; i<(n) ; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define fup_s(i, a, b, s) for (ll i = a, foc = b; i <= foc; i += s)
#define fup(i, a, b) fup_s(i, a, b, 1)
#define pb push_back
#define pop pop_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define fi first
#define se second
#define in insert



#define maxsize 1001
ll arr[maxsize];
ll top=-1;

void push(ll x)
{
	if(top==maxsize-1)
	{
        cout<<"Stack Overflow"<<endl;
        return;
	}
	else
	{
		
		arr[++top]=x;
	}
}

void print_stack()
{
	cout<<"Stack: ";
	for(ll i=0;i<=top;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

}

void pop()
{
	if(top==-1)
	{
		cout<<"No element to pop"<<endl;
		return;
	}
	else
	{
		//cout<<"Poped Item is: "<<arr[top]<<endl;
		top--; 
	}
}

void peek()
{
	if(top==-1)
	{
		cout<<"Stack is empty"<<endl;
		return;
	}
	else
	{
		cout<<"Peek value is "<<arr[top]<<endl;
	}
}


void isempty()
{
  if(top==-1)
  {
  	cout<<"Stack is empty"<<endl;

  }
  else
  {
  	cout<<"Stack is not empty"<<endl;
  }
}


void isfull()
{
	if(top==maxsize-1)
	{
		cout<<"Stack is full"<<endl;
	}
	else
	{
		cout<<"Stack isn't full"<<endl;
	}
}

int main()
{
   init();
   push(1);
   push(2);
   push(3);
   
   print_stack();
   push(4);
   print_stack();
   push(6);
   print_stack();
   isfull();
   

}