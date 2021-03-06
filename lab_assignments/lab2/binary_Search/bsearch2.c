#include<stdio.h>
void main() {
  
  int search(int a[],int lb,int ub,int key);
  int a[50],key,lb,ub,n,mid,temp;
  int i,j;
 
  printf("Enter number of elements in array: ");
  scanf("%d",&n);
  printf("Enter array: ");
 
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);

//sorting
  for(i=0;i<n;i++) {
    for(j=0;j<n-i-1;j++) {
      if(a[j]>a[j+1]) {
	temp=a[j];
	a[j]=a[j+1];
	a[j+1]=temp;
      }//if
    }
  }
 
  lb=0;
  ub=n-1;
 
  int flag=-1;
  printf("Enter element to be searched: ");
  scanf("%d",&key);
  flag=search(a,lb,ub,key);

  if(flag==-1)
    printf("Element not found\n");

  else
    printf("Element found\n");
}//main

int search(int a[],int lb,int ub, int key) {
  int mid;
  int flag=-1;
  if(lb<=ub) {
    mid=(lb+ub)/2;
    if(a[mid]==key)
      flag=1;
    else if(key<a[mid])
      flag=search(a,lb,mid-1,key);
    else
      flag=search(a,mid+1,ub,key);
  }//if
  return flag;
}//search()
