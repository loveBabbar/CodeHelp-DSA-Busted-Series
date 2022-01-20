#include<iostream>
using namespace std;
void selection(int *arr,int n)
{
    if(n==0 || n==1)
    {
        return ;
    }
    for(int i=0;i<n-1;i++)
    {
        int curr_index=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[curr_index])
            {
                curr_index=j;
            }
            swap(arr[curr_index], arr[i]);
        }
    }
    selection(arr,n-1);
}
int main()
{
    int arr[5]={41,53,12,1,4};
    int n=5;
    selection(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
