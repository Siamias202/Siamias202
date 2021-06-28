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

ll gcd(ll a, ll b)
{
	return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b)
{
	return a / gcd(a, b) * b;
}

ll bincoff(ll a, ll b)
{
    double res=1;
    for(int i=1;i<=b;i++)
    {
        res*=(a-b+i)/i;
    }
    return (ll)(res);
}


ll binpow(ll a,ll b)
{
    ll res=1;
    while(b>0)
    {
        if(b & 1)
            res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}

ll bigmod(ll a,ll b)
{
    ll ans=1;
    while(b>0)
    {
        if(b&1)
            ans=((ans%MOD)*(a%MOD))%MOD;
        b=b>>1;
        a=((a%MOD)*(a%MOD))%MOD;

    }

    return ans;
}


vector<ll>eulertotient(ll n)
{
    vector<ll>v;
    v.pb(1);
    v.pb(n-1);
    for(ll i=2;i<n-1;i++)
    {
        if(gcd(i,n)==1)
            v.pb(i);
    }
    sort(v.begin(),v.end());

    return v;

}

vector<ll> normal_factor(ll n)
{
    vector<ll> res;
    for (ll fac = 1; fac * fac <= n; ++fac)
    {
        if (n % fac == 0)
        {
            res.pb(fac);
            if (fac ^ n / fac)
                res.pb(n / fac);
        }
    }
    sort(res.begin(),res.end());
    return res;
}

map<ll, ll> prime_factor(ll n)
{
    map<ll, ll> res;
    for (ll fac = 2; fac * fac <= n; ++fac)
    {
        while (n % fac == 0)
        {
            ++res[fac];
            n /= fac;
        }
    }
    if (n ^ 1)
        res[n] = 1;
    return res;
}


vector<ll> prime_sieve(ll n)
{
	vector<ll> ret;
	vector<bool> rm(n + 1, 0);
	int bsz = max(3, int(ceil(sqrt(n))));
	rm[1] = 1;
	fup (fac, 2, bsz) if (!rm[fac])
		for (ll g = 1ll * fac * fac; g <= n; g += fac)
			rm[g] = 1;
	fup (x, 2, n) if (!rm[x])
		ret.pb(x);
	return ret;
}

vector<bool> segmentedSieve(ll a,ll b)
{
    
    ll lim = sqrt(b);
    vector<bool> mark(lim + 1, false);
    vector<ll> primes;
    for (ll i = 2; i <= lim; ++i)
    {
        if (!mark[i])
        {
            primes.eb(i);
            for (ll j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<bool> isPrime(b - a + 1, true);
    for (ll i : primes)
        for (ll j = max(i * i, (a + i - 1) / i * i); j <= b; j += i)
            isPrime[j - a] = false;
    if (a == 1)
        isPrime[0] = false;
    return isPrime;
}

vector<ll> remove_dup(vector<ll> v)
{
    auto end = v.end();
    for (auto i = v.begin(); i != end; ++i)
    {
        end = remove(i + 1, end, *i);
    }
    v.erase(end, v.end());

    return v;
}

pair<ll, ll> fib (ll n)
{
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    ll c = p.first * (2 * p.second - p.first);
    ll d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
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