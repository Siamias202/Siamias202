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

vector<ll>v;


void heapify(ll n,ll i)
{
    ll largest=i;
    ll left=2*i+1;//left node
    ll right=2*i+2;//right node
    if(left<n && v[left]>v[largest])
    {
        largest=left;
    }
    if(right<n && v[right]>v[largest])
    {
        largest=right;
    }

    if(largest!=i)
    {
        swap(v[i],v[largest]);
        heapify(n,largest);
    }
}

void build_max_heap(ll n)
{

    ll k=(n/2)-1;
    for(ll i=k; i>=0; i--)
    {
        heapify(n,i);
    }

}


void heap_sort()
{
    cout<<"Heap sort:";
    ll n=v.size();
    for(ll i=n-1; i>=0; i--)
    {
        swap(v[0],v[i]);
        heapify(i,0);
    }
}

void print_max_heap()
{
    print(v);
}



void insert_node_max_heap(ll x)
{
    v.pb(x);// push
    ll n=v.size();
    ll i=n-1;
    while(i>0)
    {
        ll parent=floor(i/2);
        if(v[parent]<v[i])
        {
            swap(v[parent],v[i]);
            i=parent;
        }
        else
        {
            break;
        }

    }
}

ll check(ll x,ll y)
{
    if(v[x]>v[y])
    {
        return x;
    }
    else
    {
        return y;
    }
}

void delete_node_max_heap_index(ll x)
{
    if(x==0)
    {
        cout<<"Root node is deleted"<<endl;
        ll y=v[v.size()-1];
        v[x]=y;
        v.pop_back();
        ll n=v.size();
        ll i=0;
        while(i<n/2)
        {
            ll left=2*i+1;
            ll right=2*i+2;
            ll max_child=check(left,right);

            if(v[i]<v[max_child])
            {
                swap(v[i],v[max_child]);
                i=max_child;
            }
            else
            {
                break;
            }
        }
    }
    else if(x==v.size()-1)
    {
        v.pop_back();
        return;
    }
    else if(x>0 && x<v.size())
    {
        ll y=v[v.size()-1];
        v[x]=y;
        v.pop_back();
        ll n=v.size();
        ll i=0;
        if(v[x]<max(v[2*x+1],v[2*x+2]))
        {
            ll j=x;

            while(j<(v.size()/2))
            {
                ll left=2*j+1;
                ll right=2*j+2;
                ll max_child=check(left,right);
                if(v[j]<v[max_child])
                {
                    swap(v[j],v[max_child]);
                    j=max_child;
                }
                else
                {
                    return;
                }
            }
        }
        else if(v[floor(x/2)]<v[x])
        {
            ll j=v.size()-1;
            while(j>0)
            {
                ll parent=floor(x/2);
                if(v[parent]<v[j])
                {
                    swap(v[parent],v[j]);
                    j=parent;
                }
                else
                {
                    return;
                }
            }
        }
    }
    else
    {
        cout<<"Invalid Index"<<endl;
        return;
    }
}

void update_node_max_heap_index(ll idx,ll x)
{
    ll i;
    v[idx]=x;
    ll n=v.size();
    idx=i;
    if(idx==0)
    {
        ll y=idx;
        ll n=v.size();
        ll left=2*idx+1;
        ll right=2*idx+2;
        ll max_child=check(left,right);

        if(v[idx]<v[max_child])
        {
            while(y<n/2)
            {
                ll left=2*idx+1;
                ll right=2*idx+2;
                ll max_child=check(left,right);

                if(v[i]<v[max_child])
                {
                    swap(v[i],v[max_child]);
                    i=max_child;
                }
                else
                {
                    break;
                }
            }
        }
    }

}




int main()
{


    v= {3,10,4,2,6,7,8,9,5};
    ll a=v.size();
    build_max_heap(a);
    print_max_heap();
    cout<<endl;

    insert_node_max_heap(60);
    print(v);
    cout<<endl;

    delete_node_max_heap_index(1);
    print(v);

}

