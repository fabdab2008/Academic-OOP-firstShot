
#include<bits/stdc++.h>
using namespace std;

void merge(int a[],int left,int mid,int right)
{
    int i,index_a,index_l,index_r,size_l,size_r;

    size_l=mid-left+1;
    size_r=right-mid;

    int l[size_l],r[size_r];

    for(i=0;i<size_l;i++)
    {
        l[i]=a[left+i];
    }

    for(i=0;i<size_r;i++)
    {
        r[i]=a[mid+i+1];
    }

    index_l=0;
    index_r=0;
    index_a=left;
    while(index_l<size_l && index_r<size_r)
    {
        if(l[index_l]<r[index_r])
        {
            a[index_a]=l[index_l];
            index_l+=1;
            index_a++;
        }
        else
        {
            a[index_a]=r[index_r];
            index_r+=1;
            index_a++;
        }
    }

    while(index_l<size_l)
    {
        a[index_a]=l[index_l];
        index_l+=1;
        index_a+=1;
    }

    while(index_r<size_r)
    {
        a[index_a]=r[index_r];
        index_r+=1;
        index_a+=1;
    }
}
void mergeSort(int a[],int left,int right)
{
    if(left>=right)
        return;

    int mid = left+(right-left)/2;

    mergeSort(a,left,mid);
    mergeSort(a,mid+1,right);
    merge(a,left,mid,right);
}

int main()
{
    int n,i,c=0;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    mergeSort(a,0,n-1);
    /*for(i=0;i<n-1;i++)
    {
        if(a[i+1]!=a[i]+1)
        {
            while(a[i]!=a[i+1]-1)
            {
                a[i]++;
                c++;
            }
        }
    }
    cout<<c<<endl;*/
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
