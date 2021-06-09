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

#define N 1001
ll d[N];
ll front=-1;
ll rear=-1;

void enqueue_front(ll x)
{
	if((front==0 && rear==N-1) || (front==rear+1))
	{
		cout<<"Queue is full"<<endl;
		return;
	}
	else if(front==-1 && rear==-1)
	{
		front=rear=0;
		d[front]=x;
	}
	else if(front==0)
	{
		front=N-1;
		d[front]=x;
	}
	else
	{
		front--;
		d[front]=x;
	}
}


void enqueue_rear(ll x)
{
	if((front==0 && rear==N-1) || (front==rear+1))
	{
		cout<<"Queue is full"<<endl;
		return;
	}
	else if(front==-1 && rear==-1)
	{
		front=rear=0;
		d[rear]=x;
	}
	else if(rear==N-1)
	{
      rear=0;
      d[rear]=x;
	}
	else
	{
		rear++;
		d[rear]=x;
	}
}

void dequeue_front()
{
	if(front==-1 && rear==-1)
	{
		cout<<"Queue is empty"<<endl;
		return;
	}
	else if(front==rear)
	{
		front=rear=-1;
	}
	else if(front==0)
	{
		//cout<<d[front]<<endl;
		front=0;
	}
	else
	{
		//cout<<d[front]<<endl;
		front++;
	}
}

void dequeue_rear()
{
	if(front==-1 && rear==-1)
	{
		cout<<"Queue is empty"<<endl;
		return;
	}
	else if(front==rear)
	{
		front=rear=-1;
	}
	else if(rear==0)
	{
		cout<<d[rear]<<endl;
		rear=N-1;
	}
	else
	{
		cout<<d[rear]<<endl;
		rear--;
	}
}

void display()
{
	ll i=front;
	while(i!=rear)
	{
		cout<<"Dequeue is :"<<d[i]<<" ";
		i=(i+1)%N;
	}
	cout<<d[rear]<<endl;
}

void getfront()
{
	cout<<d[front]<<endl;
	return;
}

void getrear()
{
	cout<<d[rear]<<endl;
	return;
}


int main()
{


   enqueue_rear(7);
   enqueue_rear(2);
   display();

}
