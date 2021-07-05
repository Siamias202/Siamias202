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
    for(int i=1; i<=b; i++)
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
    for(ll i=2; i<n-1; i++)
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

typedef struct linkedlist
{
    ll data;
    struct linkedlist *next;
} node;

node *root =NULL;


void append(ll num)
{
    if(root==NULL)
    {
        node *temp;
        temp = (node *)malloc(sizeof(node));
        temp->data = num;
        temp->next = NULL;
        root = temp;
    }
    else
    {
        node *temp;
        temp=root;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        node *newnode;
        newnode=(node *)malloc(sizeof(node));
        newnode->data=num;
        newnode->next=NULL;
        temp->next=newnode;
    }
}

void delete_node_value(ll x)
{
    bool ok=0;
    node *cur=root;
    node *pre =NULL;
    while(cur!=NULL)
    {
        if(cur->data==x)
        {
            ok=1;
            break;
        }
        else
        {
            pre=cur;
            cur=cur->next;
        }
    }
    if(ok)
    {
        if(cur==root)
        {
            node *temp=root;
            root=root->next;
            free(temp);
        }
        else
        {
            pre->next=cur->next;
            free(cur);
        }
    }
    else
    {
        cout<<"There is no such node"<<endl;
    }
}

void printList_forward_iterative_approach()
{
    if(root == NULL)
    {
        cout<<"Linked List is empty"<<endl;
        return;
    }
    else
    {
        node *temp;
        temp=root;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}

void printList_forward_recursive_approach(node *p)
{
    if(p==NULL)
    {
        cout<<endl;
        return;
    }
    cout<<p->data<<" ";
    printList_forward_recursive_approach(p->next);

}

void printList_backward_iterative_approach()
{
   vector<ll>v;
   node *temp=root;
   while(temp!=NULL)
   {
       v.push_back(temp->data);
   }
   rev(v);
   for(auto x:v)
   {
       cout<<x<<" ";
   }
   cout<<endl;
}

void printList_backward_recursive_approach(node *p)
{
    if(p==NULL)
    {
        cout<<endl;
        return;
    }
    printList_backward_recursive_approach(p->next);
    cout<<p->data<<" ";
}

void delete_node_index(ll x)
{
    bool ok=0;
    ll cnt=1;
    node *cur=root;
    node *pre=NULL;
    while(cur!=NULL)
    {
        if(cnt==x)
        {
            ok=1;
            break;
        }
        else
        {
            cnt++;
            pre=cur;
            cur=cur->next;
        }
    }
    if(ok)
    {
        if(cur==root)
        {
            node *temp=root;
            root=root->next;
            free(temp);
        }
        else
        {
            pre->next=cur->next;
            free(cur);
        }
    }
    else
    {
        cout<<"There is no such node"<<endl;
    }

}




void update(ll x)// add x to every data
{
    if(root==NULL)
    {
        cout<<"Linked List is empty"<<endl;
        return;
    }
    else
    {
        node *cur=root;
        while(cur!=NULL)
        {
            ll temp=cur->data;
            temp+=x;
            cur->data=temp;
            cur=cur->next;
        }

    }
}

void swap_element(ll x,ll y)
{

    node *prevnode1=NULL,*prevnode2=NULL,*temp=NULL,*node1=root,*node2=root;


    if((root==NULL) || (x==y))// List is empty or values are same
    {
        return;
    }

    while(node1!=NULL && node1->data!=x)
    {
        prevnode1=node1;
        node1=node1->next;
    }
    while(node2!=NULL && node2->data!=y)
    {
        prevnode2=node2;
        node2=node2->next;
    }

    if(node1!=NULL && node2!=NULL)
    {
        if(prevnode1!=NULL)
        {
            prevnode1->next=node2;
        }
        else
        {
            root=node2;
        }

        if(prevnode2!=NULL)
        {
            prevnode2->next=node1;
        }
        else
        {
            root=node1;
        }
        temp=node1->next;
        node1->next=node2->next;
        node2->next=temp;
    }
    else
    {
        cout<<"Swap Operation is not possible"<<endl;
        return;
    }
}

void sort_ascending()
{
    node *cur=root,*pos=NULL;
    ll temp;

    if(root==NULL)
    {
        return;
    }
    else
    {
        while(cur!=NULL)
        {
            pos=cur->next;
            while(pos!=NULL)
            {
                if(cur->data > pos->data)
                {
                    swap(cur->data,pos->data);
                }
                pos=pos->next;
            }
            cur=cur->next;
        }
    }
}

void sort_decending()
{
    node *cur=root,*pos=NULL;
    ll temp;

    if(root==NULL)
    {
        return;
    }
    else
    {
        while(cur!=NULL)
        {
            pos=cur->next;
            while(pos!=NULL)
            {
                if(cur->data < pos->data)
                {
                    swap(cur->data,pos->data);
                }
                pos=pos->next;
            }
            cur=cur->next;
        }
    }
}

void append_ascending(ll num)
{
    node *temp=root;
    if(root==NULL)
    {
        node *newnode=(node*)malloc(sizeof(node));
        newnode->data=num;
        newnode->next=NULL;
        root=newnode;
    }
    else
    {
        if(num<temp->data)
        {
            node *newnode=(node*)malloc(sizeof(node));
            newnode->data=num;
            newnode->next=root;
            root=newnode;
        }
        else
        {
            while(temp->next!=NULL && !(num<temp->next->data && num>=temp->data))
            {
                temp=temp->next;
            }
            if(temp->next==NULL)// x will go to the end
            {
                node *newnode=(node*)malloc(sizeof(node));
                newnode->data=num;
                newnode->next=NULL;
                temp->next=newnode;
            }
            else
            {
                node *newnode=(node*)malloc(sizeof(node));
                newnode->data=num;
                newnode->next=temp->next;
                temp->next=newnode;
            }
        }
    }
}

void append_decending(ll num)
{
    node *temp=root;
    if(root==NULL)
    {
        node *newnode=(node*)malloc(sizeof(node));
        newnode->data=num;
        newnode->next=NULL;
        root=newnode;
    }
    else
    {
        if(num>temp->data)
        {
            node *newnode=(node*)malloc(sizeof(node));
            newnode->data=num;
            newnode->next=root;
            root=newnode;
        }
        else
        {
            while(temp->next!=NULL && !(num>temp->next->data && num<=temp->data))
            {
                temp=temp->next;
            }
            if(temp->next==NULL)
            {
                node *newnode=(node*)malloc(sizeof(node));
                newnode->data=num;
                newnode->next=NULL;
                temp->next=newnode;
            }
            else
            {
                node *newnode=(node*)malloc(sizeof(node));
                newnode->data=num;
                newnode->next=temp->next;
                temp->next=newnode;
            }
        }
    }


}

void reverse_iterative_approach()
{
    node *prev,*cur,*nextnode;
    prev=NULL;
    cur=nextnode=root;
    while(nextnode!=NULL)
    {
        nextnode=nextnode->next;
        cur->next=prev;
        prev=cur;
        cur=nextnode;
    }
    root=prev;
}

void reverse_recursive_approach(node *p)
{
    if(p->next==NULL)
    {
        root=p;
        return;
    }

    reverse_recursive_approach(p->next);
    node *q=p->next;
    q->next=p;
    p->next=NULL;
}
int main()
{


    append_decending(3);
    append_decending(5);
    append_decending(4);
    append_decending(2);
    append_decending(8);
    append_decending(7);
    printList_backward_iterative_approach();




}
