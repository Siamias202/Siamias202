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

#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define fi first
#define se second
#define in insert


#define all(a)          a.begin(),a.end()
#define SORT(v)         sort(all(v))
#define rev(v)          reverse(v.begin(),v.end())
#define UNIQUE(a)       sort(all(a)),a.erase(unique(all(a)),a.end())
#define INDEX(a,b)      find(a.begin(), a.end(), b) - a.begin();
#define print(v)        for(auto x:v) {cout<<x<<" ";}

#define mp make_pair
#define LCM(a,b)    (a/__gcd(a,b))*b
#define GCD(a,b) __gcd(a,b);
#define endl "\n"
#define FRU freopen("out.txt","w",stdout)
#define FRO freopen("in.txt","r",stdin)
#define INFLL 9223372036854775807
#define debug 0
#define MAXN   100001
const int MOD=1e9+7;
const int N = 1e5 + 5;

bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 
void init()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	boost;
}



typedef struct bt
{
  ll data;
  struct bt *left_child;
  struct bt *right_child; 	
}node;



node *createnode(ll x)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->data=x;
	temp->left_child=NULL;
	temp->right_child=NULL;

	return temp;
}

void insert_iterative(node*& root,ll x)
{
	
	node *cur=root;
	node *parent=NULL;
	if(root==NULL)
	{
		root=createnode(x);
		return;
	}

	while(cur!=NULL)
	{
		parent=cur;
		if(x<cur->data)
		{
			cur=cur->left_child;
		}
		else
		{
			cur=cur->right_child;
		}
	}
	if(x<parent->data)
	{
        parent->left_child=createnode(x);
	}
	else
	{
		parent->right_child=createnode(x);
	}
}

void insert_recursive(node*& root,ll x )
{
	if(root==NULL)
	{
		root=createnode(x);
		return;
	}
	if(x<root->data)
	{
		insert_iterative(root->left_child,x);
	}
	else
	{
		insert_iterative(root->right_child,x);
	}
}

void inorder_iterative(node *root)
{
	stack<node*>st;
	node *cur=root;

	while(!st.empty() || cur!=NULL)
	{
		if(cur!=NULL)
		{
			st.push(cur);
			cur=cur->left_child;
		}
		else
		{
			cur=st.top();
			st.pop();
			cout<<cur->data<<" ";
			cur=cur->right_child;
		}
	}
}

void inorder_recursive(node *root)//get  a sorted list
{
	if(root==NULL)
	{
		return;
	}
	inorder_recursive(root->left_child);
	cout<<root->data<<" ";
	inorder_recursive(root->right_child);
}


void preorder_recursive(node *root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	preorder_recursive(root->left_child);
	preorder_recursive(root->right_child);

}

void preorder_iterative(node *root)
{
	if(root==NULL)
	{
		return;
	}
	stack<node*>st;
	st.push(root);
	while(!st.empty())
	{
		node *cur=st.top();
		st.pop();
		cout<<cur->data<<" ";
		if(cur->right_child)
		{
			st.push(cur->right_child);
		}
		if(cur->left_child)
		{
			st.push(cur->left_child);
		}
	}
}

void postorder_recursive(node *root)
{
	if(root==NULL)
	{
		return;
	}
	postorder_recursive(root->left_child);
	postorder_recursive(root->right_child);
	cout<<root->data<<" ";
}

void postorder_iterative(node *root)
{
	stack<node*>st;
	st.push(root);
	stack<ll>s;
    while(!st.empty())
    {
    	node *cur=st.top();
    	st.pop();
    	s.push(cur->data);
    	if(cur->left_child)
    	{
           st.push(cur->left_child);
    	}
    	if(cur->right_child)
    	{
    		st.push(cur->right_child);
    	}

    }
    while(!s.empty())
    {
    	cout<<s.top()<<" ";
    	s.pop();
    }
}

void levelorder_iterative(node *root)
{
	queue<node*>q;
	q.push(root);
	node *cur=NULL;
	while(q.size())
	{
		cur=q.front();
		q.pop();
		cout<<cur->data<<" ";
		if(cur->left_child)
		{
			q.push(cur->left_child);
		}
		if(cur->right_child)
		{
			q.push(cur->right_child);
		}
	}
}

ll height_recursive(node *root)
{
	if(root==NULL)
	{
		return -1;
	}
	return max(height_recursive(root->left_child),height_recursive(root->right_child))+1;
}

ll height_iterative(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	list<node*>q;
	q.push_back(root);
	ll height=-1;
	node *front=NULL;
	while(!q.empty())
	{
		ll size=q.size();
		while(size--)
		{
			front=q.front();
			q.pop_front();
			if(front->left_child)
			{
				q.push_back(front->left_child);
			}
			if(front->right_child)
			{
				q.push_back(front->right_child);
			}
		}
		height++;
	}
	return height;
}

ll find_min_iterative(node *root)
{
	while(root->left_child!=NULL)
	{
		root=root->left_child;
	}
	return root->data;
}

ll find_min_recursive(node *root)
{
	if(root->left_child==NULL)
	{
		return root->data;
	}
	return find_min_recursive(root->left_child);
}

ll find_max_iterative(node *root)
{
	while(root->right_child!=NULL)
	{
		root=root->right_child;
	}
	return root->data;
}

ll find_max_recursive(node *root)
{
	if(root->right_child==NULL)
	{
		return root->data;
	}
	return find_max_recursive(root->right_child);
}

void search_iterative(node *root,ll key)
{
	node *cur=root;
	while(cur!=NULL && cur->data!=key)
	{
		if(key<cur->data)
		{
			cur=cur->left_child;
		}
		else
		{
			cur=cur->right_child;
		}
	}
	if(cur==NULL)
	{
		cout<<"Not found"<<endl;
	}
	else
	{
		cout<<"found"<<endl;
	}
}


void search_recursive(node *root,ll key)
{
	if(root==NULL)
	{
		cout<<"Not found"<<endl;
		return;
	}
    if(root->data==key)
	{
		cout<<"found"<<endl;
		return;
	}
	if(key<root->data)
	{
		return search_recursive(root->left_child,key);
	}
	return search_recursive(root->right_child,key);

}

bool printlevel(node *root,ll level)
{
	if(root==NULL)
	{
		return false;
	}
	if(level==1)
	{
		cout<<root->data<<" ";
		return true;
	}
	bool left=printlevel(root->left_child,level-1);
	bool right=printlevel(root->right_child,level-1);

	return (level || right);
}

void levelorder_recurisve(node *root)
{
	ll level=1;
	while(printlevel(root,level))
	{
		level++;
	}
}

 vector<ll>v;

void leaf_node(node *root)
{
    if(!root)
    {
        return;
    }
    if(!root->left_child && !root->right_child)
    {
        v.pb(root->data);
        return;
    }
    if(root->left_child)
    {
        leaf_node(root->left_child);
    }
    if(root->right_child)
    {
        leaf_node(root->right_child);
    }
}

int main()
{

   init();
   node *root=NULL;
   cout<<"insert_iterative: "<<endl;
   insert_iterative(root,15);
   insert_iterative(root,10);
   insert_iterative(root,20);
   insert_iterative(root,8);
   insert_iterative(root,12);
   insert_iterative(root,16);
   insert_iterative(root,25);
   inorder_recursive(root);
   cout<<endl;

   cout<<"insert_recursive: "<<endl;
   node *root1=NULL;
   insert_recursive(root1,15);
   insert_recursive(root1,10);
   insert_recursive(root1,20);
   insert_recursive(root1,8);
   insert_recursive(root1,12);
   insert_recursive(root1,16);
   insert_recursive(root1,25);
   inorder_recursive(root1);

   node *root2=NULL;
   node *root3=NULL;

   cout<<"height_iterative: "<<height_iterative(root)<<endl;
   cout<<"height_recursive: "<<height_recursive(root)<<endl;
   
   cout<<"find_max_recursive: "<<find_max_recursive(root)<<endl;
   cout<<"find_max_iterative: "<<find_max_recursive(root)<<endl;

   cout<<"find_min_recursive: "<<find_min_recursive(root)<<endl;
   cout<<"find_min_iterative: "<<find_min_recursive(root)<<endl;

    search_iterative(root,21);
    search_recursive(root,12);

    inorder_iterative(root);
    cout<<endl;

    preorder_recursive(root);
    cout<<endl;

    preorder_iterative(root);
    cout<<endl;

    postorder_recursive(root);
    cout<<endl;
    postorder_iterative(root);

    cout<<endl;

    levelorder_iterative(root);
    cout<<endl;
    
    





        

}
