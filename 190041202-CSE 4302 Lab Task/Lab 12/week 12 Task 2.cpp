#include<bits/stdc++.h>
using namespace std;

template<class T>
T Max(T *arr,int n)
{
    T res=arr[0];
    for(int i=1;i<n;i++)
    {
        if(res<arr[i])
        {
            res=arr[i];
        }
    }
    return res;
}

int main()
{
    int num[]={2,4,10,6,9,1};
    int n=6;
    cout<<Max(num,n)<<endl;

    double num1[]={2.4,4.4,10.4,6.4,9.4,1.4};
    int k=6;
    cout<<Max(num1,k)<<endl;
}
