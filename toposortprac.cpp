#include<bits/stdc++.h>

using namespace std;
map<char,int>dep;

vector<char >v;
     int n;
queue<char>q;

int graph[100][100];


void toposort()
{
    for(auto it=dep.begin();it!=dep.end();it++)
    {
        if(it->second==0)
        {
            q.push(it->first);
        }
    }

    while(!q.empty())
    {
        char f=q.front();
         v.push_back(f);
        q.pop();


        int ff=f-65;


            for(int j=0;j<100;j++)
            {
                if(graph[ff][j]==1)
                {  char fff=65+j;
                dep[fff]--;
                if(dep[fff]==0)
                {


                    q.push(fff);


                }
            }

    }


}
}

int main()

{


      cin>>n;
      cout<<"subjects";
      for(int i=0;i<n;i++)
      {  char ch;
          cin>>ch;
          dep[ch]=0;
      }
cout<<"no of edge"<<endl;
int e;
cin>>e;
    for(int i=0;i<e;i++)
    {
        cout<<"first sub"<<endl;
        char ch1;
        cin>>ch1;
        cout<<"2nd sub"<<endl;
        char ch2;
        cin>>ch2;
        dep[ch2]++;

        int m=ch1-65;
        int k=ch2-65;
        graph[m][k]=1;

    }

    toposort();
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<"  ";
    }

}
