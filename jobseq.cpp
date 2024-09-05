#include<bits/stdc++.h>

using namespace std;
int n;
class job
{
public:
    char name;
    int deadline;
    int value;
};
int main()
{
    cout<<"no of job"<<endl;
    cin>>n;
    job *arr;
    arr=new job[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].name;
        cin>>arr[i].deadline;
        cin>>arr[i].value;
    }

    for(int i=0;i<n;i++)
    {
        for(int i=0;i<n-1;i++)
        {
            if(arr[i].value<arr[i+1].value)
            {
                swap(arr[i],arr[i+1]);
            }
        }
    }
    for(int i=0;i<n;i++)
        {
           cout<<arr[i].value<<"  ";
        }

}
