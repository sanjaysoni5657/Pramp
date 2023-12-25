#import <iostream>
#import <vector>

using namespace std;
int abs(int a)
{
  if(a<0)
  {
    a=a*-1;
  }
  return a;
}
bool cmp(int a,int b)
{
  if(abs(a)==abs(b))
  {
    return a<=b;
  }
  if(abs(a)<abs(b))
  {
    return true;
  }
  return false;
  
}
void merge(vector<int>&arr,int low,int mid,int high)
{
  int i=low,j=mid+1;
  vector<int> temp(high-low+1);
  int k=0;
  while(i<=mid && j<=high)
  {
    if(cmp(arr[i],arr[j])) // comeback
    {
      temp[k]=arr[i++];
    }
    else
    {
      temp[k]=arr[j++];
    }
    k++;
  }
  while(i<=mid)
  {
    temp[k++]=arr[i++];
  }
  while(j<=high)
  {
    temp[k++]=arr[j++];
  }
  for(i=0;i<k;i++)
  {
    arr[i+low]=temp[i];
  }
}
void mergeSort(vector<int> &arr,int low,int high)
{
  if(low<high)
  {
    int mid=(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
  }
}
vector<int> absSort(const vector<int>& arr)
{
	// your code goes here
}

int main() 
{
	return 0;
}

// TC - O(nlogn), SC - O(n)
