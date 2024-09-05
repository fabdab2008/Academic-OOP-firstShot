#include<bits/stdc++.h>

using namespace std;

int m[1001][1001];
int s[1001][1001];

int d[1001];


printans(int i,int j)
{
    if(i==j)
    {
        cout<<"A"<<i;
    }
    else{
    cout<<"(";
    printans(i,s[i][j]);
    printans(s[i][j]+1,j);
    cout<<")";
    }
}

int mcm(int i,int j)
{
    if(i==j)
    {
        m[i][j]=0;

        return 0;
    }

    if(m[i][j]!=999999)
    {
        return m[i][j];
    }
      int p=999999;
      int q=999999;
      int k;
    for( k=i;k<j;k++)
    {
        int val=mcm(i,k)+mcm(k+1,j)+d[i-1]*d[k]*d[j];
        if(val<p)
        {
            p=val;
            q=k;
        }
    }

    m[i][j]=p;
    s[i][j]=q;
    return m[i][j];
}




int main()
{

    for(int i=0;i<1001;i++)
    {
        for(int j=0;j<1001;j++)
        {
            m[i][j]=999999;
            s[i][j]=999999;
        }
    }
    int no;
    cout<<"No:"<<endl;
    cin>>no;
    for(int i=0;i<no;i++)
    {
        cout<<"row"<<endl;
        cin>>d[i];
        cout<<"coloumn"<<endl;
        cin>>d[i+1];
    }

    cout<<mcm(1,no)<<endl;
    //cout<<s[1][no];
    printans(1,no);
}
