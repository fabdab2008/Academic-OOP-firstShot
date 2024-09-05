#include<bits/stdc++.h>

using namespace std;

int n;
int arr[100];
int target;
vector<int>q;


void backtrack(int i,int t,vector<int>q)
{
    if(t==0)
    {
        for(int i=0;i<q.size();i++)
        {
            cout<<q[i]<<" ";
        }

        while(!q.empty())
        {
            q.pop_back();
        }
         cout<<endl;
    }
    if(i==n)
    {
        return;
    }
    backtrack(i+1,t,q);
      if(arr[i]<=t)
      {


    q.push_back(arr[i]);
    backtrack(i+1,t-arr[i],q);
    q.pop_back();
      }

}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

cout<<"max sum:"<<endl;
 cin>>target;

 backtrack(0,target,q);
}
