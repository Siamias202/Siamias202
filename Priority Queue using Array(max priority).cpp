#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1001
ll arr[N],pr[N];
ll rear = -1,front = -1;
void enqueue(ll data,ll p)//Enqueue function to insert data and its priority in queue
{
    ll i;
    if((front==0)&&(rear==N-1)) //Check if Queue is full
        cout<<"Queue is full"<<endl;
    else
    {
        if(front==-1)//if Queue is empty
        {
            front = rear = 0;
            arr[rear] = data;
            pr[rear] = p;

        }
        else if(rear == N-1)//if there there is some elemets in Queue
        {
            for(i=front; i<=rear; i++)
            {
                arr[i-front] = arr[i];
                pr[i-front] = pr[i];
                rear= rear-front;
                front = 0;
                for(i = rear; i>front; i--)
                {
                    if(p>pr[i])
                    {
                        arr[i+1] = arr[i];
                        pr[i+1] = pr[i];
                    }
                    else
                        break;
                    arr[i+1] = data;
                    pr[i+1] = p;
                    rear++;
                }
            }
        }
        else
        {
            for(i = rear; i>=front; i--)
            {
                if(p>pr[i])
                {
                    arr[i+1] = arr[i];
                    pr[i+1] = pr[i];
                }
                else
                    break;
            }
            arr[i+1] = data;
            pr[i+1] = p;
            rear++;
        }
    }

}
void print() //print the data of Queue
{
    ll i;
    for(i=front; i<=rear; i++)
    {
        cout<<"Element: "<<arr[i]<<"   Priority: "<<pr[i]<<endl;
    }
    cout<<endl;
}
void dequeue() //remove the data from front
{
    if(front == -1)
    {
        cout<<"Queue is Empty"<<endl;
    }
    else
    {
        cout<<"Dequeued Element is: "<<arr[front]<<endl;
        if(front==rear)
            front = rear = -1;
        else
            front++;
    }
    cout<<endl;

}

int main()
{
    enqueue(2,8);
    enqueue(10,9);
    enqueue(11,2);
    enqueue(12,12);
    print();

    dequeue();
    print();

}
