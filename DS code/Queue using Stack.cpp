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
 
//#define maxsize 1001;
//ll s1[maxsize],s2[maxsize];

ll n;
vector<ll>v1,v2;
ll top1=-1;
ll top2=-1;
ll cnt=0;

void push1(ll x)
{
	if(top1==n-1)
	{
		cout<<"Stack Overflow"<<endl;
		return;
	}
	else
	{
		top1++;
		v1[top1]=x;
	}
}

void push2(ll x)
{
	if(top2==n-1)
	{
		cout<<"Stack Overflow"<<endl;
		return;
	}
	else
	{
		top2++;
		v2[top2]=x;
	}
}

ll pop1()
{
	return v1[top1--];
}

ll pop2()
{
	return v2[top2--];
}

void enqueue(ll x)
{
	push1(x);
	cnt++;
    
}

void dequeue()
{
	if(top1==-1 && top2==-1)
	{
		cout<<"Both Stack is empty"<<endl;
	}
	for(ll i=0;i<cnt;i++)
	{
         ll a=pop1();
         push2(a);
	}
	ll b=pop2();
	//cout<<"Dequeued element is: "<<b<<endl;
	cnt--;
	for(ll i=0;i<cnt;i++)
	{
		ll a=pop2();
		push1(a);
	}
    
}

void display()
{
    if(cnt==0)
    {
        cout<<"Size:0 elements: Null"<<endl;
        return;
    }
    else
	{
        cout<<"Size:"<<cnt<<" elements:";
        for(ll i=0;i<=top1;i++)
        {
            cout<<v1[i]<<" ";
        }
        cout<<endl;
        return;

    }
}

int main()
{

   init();
   
   cin>>n;
   v1.resize(n);
   v2.resize(n);
   ll t;
   cin>>t;
   while(t--)
   { 
      ll a;
      cin>>a;
      if(a==1)
      {
        ll x;
        cin>>x;
        if(top1==n-1)
        {
            cout<<"Overflow!"<<endl;

        }
        else
        {
            enqueue(x);
            display();
        }
      }
      else if(a==2)
      {
        dequeue();
        display();
      }
   }


}