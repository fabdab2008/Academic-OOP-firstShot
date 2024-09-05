#include<bits/stdc++.h>
using namespace std;

int maxwt;

int maxprofit;

class item
{
public:

    int price;
    int wt;
    int ratio_;
};
class node
{
public:
    int v;
    int wt;
    int ub;

};
int findingub(int v, int w, int vnext, int wnext) {
    return v + (maxwt - w) * (vnext / static_cast<double>(wnext));
}


item *arr;
int main()
{
 cout<<"maxxwt"<<endl;
 cin>>maxwt;
     int no;
    cout<<"no of item"<<endl;
    cin>>no;
    arr=new item[no];

    for(int i=0;i<no;i++)
    {
        cin>>arr[i].wt;
        cin>>arr[i].price;
        arr[i].ratio_=arr[i].price/arr[i].wt;

    }

    for(int i=0;i<no;i++)
    {
        for(int i=0;i<no-1;i++)
        {
               if(arr[i].ratio_<arr[i+1].ratio_)
               {
                   swap(arr[i],arr[i+1]);
               }
        }
    }

    for(int i=0;i<no;i++)
    {
        cout<<arr[i].price<<"  "<<arr[i].wt<<"  "<<arr[i].ratio_<<endl;
    }

    queue<node>q;

    int level=0;
    node n;
    n.v=0;
    n.wt=0;
    n.ub=findingub(0,0,arr[0].price,arr[0].wt);
    q.push(n);
    while(!q.empty())
    {
        node a=q.front();
        q.pop();

        node b1;
        node b2;

        b1.v=a.v;
        b1.wt=a.wt;
        b1.ub=findingub(b1.v,b1.wt,arr[level].price,arr[level].wt);

        b2.v=a.v+arr[level].price;
        b2.wt=arr[level].wt+a.wt;
        b2.ub=findingub(b2.v,b2.wt,arr[level].price,arr[level].wt);




        if(b1.ub>maxprofit &&b1.wt<=maxwt)
        {
            q.push(b1);
            maxprofit=max(maxprofit,b1.v);
        }
        if(b2.ub>maxprofit &&b2.wt<=maxwt)
        {
            q.push(b2);
             maxprofit=max(maxprofit,b2.v);
        }
        level++;
    }


    cout<<maxprofit<<endl;
}
