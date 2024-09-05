#include<bits/stdc++.h>

using namespace std;
int n;
int board[100][100];
void init()
{
    for(int i=0; i<100; i++)
    {
        for(int j=0; j<100; j++)
        {
            board[i][j]=0;
        }
    }
}
bool issafe(int i,int j)
{
    //cout<<"hello";
    for(int k=0; k<i; k++)
    {
        if(board[k][j]==1)
        {
            return false;
        }


    }

    int a=i;
    int b=j;
    while(i>=0 || j>=0)
    {
        if(board[i][j]==1)
        {
            return false;
        }
        i--;
        j--;
    }
    i=a;
    j=b;
    while(i>=0 || j<n)
    {
        if(board[i][j]==1)
        {
            return false;
        }
        i--;
        j++;
    }
    return true;
}
void backtrack(int i,int n)
{
    //init();
    if(i==n)
    {
        for(int m=0; m<n; m++)
        {
            for(int l=0; l<n; l++)
            {
                if(board[m][l]==1)
                {


                    cout<<"("<<m<<")"<<l<<"   ";
                }
            }
        }
        cout<<endl;
        //init();
    }




    for(int j=0; j<n; j++)

    {
        if(issafe(i,j))
        {
            //cout<<"hello";

            board[i][j]=1;
            backtrack(i+1,n);
            board[i][j]=0;

        }

    }

}





int main()
{
    init();
    cout<<"n"<<endl;
    cin>>n;
    backtrack(0,n);
}
