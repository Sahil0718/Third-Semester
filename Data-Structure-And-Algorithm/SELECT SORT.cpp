#include<iostream>
using namespace std;
void select_sort(int arr[],int n)
{
		for(int i=0;i<n-1;i++)
		{
		int si=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[si])
			{
				si=j;
			}
		}
			if(si!=i){
				int temp=arr[si];
				arr[si]=arr[i];
				arr[i]=temp;
			}
	}
}
	

int main(){
	const int n=7;
	int array[n]={4,1,7,5,6,9,0};
	cout<<"Before"<<endl;
	for(int i=0;i<n;i++){
		cout<<array[i]<<"\t";
		cout<<endl;
	}
	select_sort(array,n);
	cout<<"After Sorting"<<endl;
	for(int i=0;i<n;i++){
		cout<<array[i]<<"\t";
		cout<<endl;
	}
	return 0;
}

