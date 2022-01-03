#include<stdio.h>
void display(int arr[],int n)
{
    int i;
  for(i=0;i<n;i++)
  {
      printf("%d\t",arr[i]);
  }
}
void indDeletion(int arr[],int size,int index)
{
    int i;
    for(i=index;i<size-1;i++)
    {
        arr[i]=arr[i+1];
    }
}
int main()
{
    int arr[100]={7,8,12,27,88};
    int size=5,index=1;
    display(arr,size);
    indDeletion(arr,size,index);
    size-=1;
    printf("\n");
    display(arr,size);
    return 0;
}