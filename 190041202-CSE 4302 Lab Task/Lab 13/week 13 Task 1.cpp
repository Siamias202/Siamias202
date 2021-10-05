#include<bits/stdc++.h>
using namespace std;

int main()
{
    array<int,5>even{2,4,6,8,10};
    set<int>odd{1,3,5,7,9};
    vector<int>v(even.size()+odd.size());
    merge(even.begin(),even.end(),odd.begin(),odd.end(),v.begin());
    for(auto x:v)
    {
        cout<<x<<" ";
    }
}
