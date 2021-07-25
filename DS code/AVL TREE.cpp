

/*
 Kawsar Ahamed  Siam
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
#define pb push_back


#define all(a)          a.begin(),a.end()
#define SORT(v)         sort(all(v))
#define rev(v)          reverse(v.begin(),v.end())
#define UNIQUE(a)       sort(all(a)),a.erase(unique(all(a)),a.end())
#define INDEX(a,b)      find(a.begin(), a.end(), b) - a.begin();
#define print(v)        for(auto x:v) {cout<<x<<" ";}





typedef struct bt
{
    ll data;
    struct bt *left_child;
    struct bt *right_child;
    struct bt *parent;
    ll bf;
    ll height;
} node;

node *root=NULL;

node *createnode(ll x)
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp->data=x;
    temp->left_child=NULL;
    temp->right_child=NULL;
    temp->parent=NULL;
    temp->bf=0;
    temp->height=0;

    return temp;
}


ll height(node *x)
{

    if(x==NULL)
        return -1;
    else
        return x->height;

}

void update_height(node *x)
{
    x->height=1+max(height(x->left_child),height(x->right_child));
}

ll balance_factor(node *x)
{
    return height(x->left_child)- height(x->right_child);
}

void inorder_iterative()
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
            cout<<cur->data<<"("<<cur->bf<<") ";
            cur=cur->right_child;
        }
    }
    cout<<endl;
}


void right_rotate(node *z)
{
    node *y=z->left_child;
    node *T3=y->right_child;
    y->parent=z->parent;
    if(z==root)
    {
        root=y;
    }
    else
    {
        if(z==z->parent->left_child)
        {
            z->parent->left_child=y;
        }
        else
        {
            z->parent->right_child=y;
        }
    }
    y->right_child=z;
    z->parent=y;
    z->left_child=T3;
    if(T3!=NULL)
    {
        T3->parent=z;
    }

    node *temp=z;
    node *temp1=z;
    while(temp!=NULL)
    {
        update_height(temp);
        temp=temp->parent;
    }
    while(temp1!=NULL)
    {
        ll bf=balance_factor(temp1);
        temp1->bf=bf;
        temp1=temp1->parent;
    }
}

void left_rotate(node *z)
{

    node* y=z->right_child;
    node* T3=y->left_child;
    y->parent=z->parent;
    if(z==root)
    {
        root=y;
    }
    else
    {
        if(z==z->parent->left_child)
        {
            z->parent->left_child=y;
        }
        else
        {
            z->parent->right_child=y;
        }
    }
    y->left_child=z;
    z->parent=y;
    z->right_child=T3;
    if(T3!=NULL)
    {
        T3->parent=z;
    }

    node *temp=z;
    node *temp1=z;
    while(temp!=NULL)
    {
        update_height(temp);
        temp=temp->parent;
    }
    while(temp1!=NULL)
    {
        ll bf=balance_factor(temp1);
        temp1->bf=bf;
        temp1=temp1->parent;
    }

}



bool check_balance(node *x,ll key)
{
    bool ok=true;
    while(x!=NULL)
    {
        if(x->bf>1)    //jhamela ase ll/lr case
        {
            cout<<"Imbalanced at node:"<<x->data<<endl;
            if(key<x->left_child->data)
            {
                cout<<"LL Case"<<endl;
                cout<<"Right_rotate:("<<x->data<<")"<<endl;
                right_rotate(x);
                cout<<"Status:";
                inorder_iterative();
                cout<<"Root="<<root->data<<endl;
            }
            else if(key>x->left_child->data)
            {
                cout<<"LR Case"<<endl;
                cout<<"Left_rotate:("<<x->left_child->data<<"), "<<"Right_rotate:("<<x->data<<")"<<endl;
                left_rotate(x->left_child);
                right_rotate(x);
                cout<<"Status:";
                inorder_iterative();
                cout<<"Root="<<root->data<<endl;
            }
            ok=false;
            break;
        }
        else if(x->bf<-1)
        {
            cout<<"Imbalanced at node:"<<x->data<<endl;
            if(key>x->right_child->data)
            {
                cout<<"RR Case"<<endl;
                cout<<"Left_rotate:("<<x->data<<")"<<endl;
                left_rotate(x);
                cout<<"Status:";
                inorder_iterative();
                cout<<"Root="<<root->data<<endl;
            }
            else if(key<x->right_child->data)
            {
                cout<<"RL Case"<<endl;
                cout<<"Right_rotate:("<<x->right_child->data<<"), "<<"Left_rotate:("<<x->data<<")"<<endl;
                right_rotate(x->right_child);
                left_rotate(x);
                cout<<"Status:";
                inorder_iterative();
                cout<<"Root="<<root->data<<endl;
            }
            ok=false;
            break;
        }
        else
        {
            x=x->parent;
        }
    }
    return ok;
}

void insert_iterative(ll key)
{
    node *newnode=createnode(key);
    node *temp1=newnode;
    node *temp2=newnode;
    if(root==NULL)
    {
        root=newnode;
        inorder_iterative();
        cout<<"Balanced"<<endl;
        cout<<"Root="<<root->data<<endl;
        return;
    }
    node *cur=root;
    node *present_node=NULL;
    while(cur!=NULL)
    {
        present_node=cur;
        if(key<cur->data)
        {
            cur=cur->left_child;
        }
        else
        {
            cur=cur->right_child;
        }
    }
    if(key<present_node->data)
    {
        present_node->left_child=newnode;
        newnode->parent=present_node;
        temp1->parent=present_node;
        temp2->parent=present_node;
    }
    else
    {
        present_node->right_child=newnode;
        newnode->parent=present_node;
        temp1->parent=present_node;
        temp2->parent=present_node;
    }

    while(temp1!=NULL)
    {
        update_height(temp1);
        temp1=temp1->parent;
    }
    while(temp2!=NULL)
    {
        ll bf=balance_factor(temp2);
        temp2->bf=bf;
        temp2=temp2->parent;
    }

    inorder_iterative();
    newnode=newnode->parent;
    if(check_balance(newnode,key))
    {
        cout<<"Balanced"<<endl;
        cout<<"Root="<<root->data<<endl;
    }
}

int main()
{

    while(1)
    {
        ll x;
        cin>>x;
        if(x!=-1)
        {
            insert_iterative(x);

        }
        else
        {
            break;
        }
    }
    cout<<"Status:";
    inorder_iterative();
    cout<<"Root="<<root->data<<endl;
}

