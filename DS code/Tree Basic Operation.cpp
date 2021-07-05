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



void init()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	boost;
}


 
char tree[]={'\0', 'D', 'A', 'F', 'E', 'B', 'R', 'T', 'G', 'Q', '\0', '\0', 'V', '\0', 'J', 'L'};


ll complete_node=15;


ll get_left_child(ll index)
{
    if(tree[index]!='\0' && (2*index)<=complete_node)
    {
        return 2*index;
    }
    else
    {
        return -1;
    }
}




ll get_right_child(ll index)
{
    if(tree[index]!='\0' && ((2*index+1)<=complete_node) )
        return (2*index)+1;
    else
        return -1;
}

bool is_leaf(ll index)
{
    if(!get_left_child(index) && !get_right_child(index))
    {
       return true;
    }
    else if(tree[get_left_child(index)]=='\0' && tree[get_right_child(index)] )
    {
        return true;
    }
    else
    {
        return false;
    }
}


ll get_height(ll index)
{
    if(tree[index]=='\0' || index<=0 || is_leaf(index))
    {
        return 0;
    }
    else
    {
        return (max(get_height(get_left_child(index)),get_height(get_right_child(index)))+1);
    }
}

void preorder(ll index)
{
    if(index>0 && tree[index]!='\0')
    {
        cout<<tree[index]<<" ";
        preorder(get_left_child(index));
        preorder(get_right_child(index));
    }
    
}


void inorder(ll index)
{
    if(index>0 && tree[index]!='\0')
    {
        inorder(get_left_child(index));
        cout<<tree[index]<<" ";
        inorder(get_right_child(index));
    }
}

void postorder(ll index)
{
    if(index>0 && tree[index]!='\0')
    {
        postorder(get_left_child(index));
        postorder(get_right_child(index));
        cout<<tree[index]<<" ";
    }
}


int main()
{

   init();
   inorder(2);
   
}