#include<iostream>
using namespace std;
void merge(int arr[],int l, int m,int r){
  int i = l;
  int j = m + 1;
  int k = l;
  int temp[12];
   while (i <= m && j <= r) {
    if (arr[i] <= arr[j]) {
      temp[k] = arr[i];
      i++;
      k++;
    } else {
      temp[k] = arr[j];
      j++;
      k++;
    }
   }
 
  while (i <= m) {
    temp[k] = arr[i];
    i++;
    k++;
 }
  while (j <= r) {
    temp[k] = arr[j];
    j++;
    k++;
  }
  for (int p = l; p <= r; p++) {
    arr[p] = temp[p];
  }
}
void merge_sort(int a[],int l,int r){
	if(l<r){
		int m=(l+r)/2;
		merge_sort(a,l,m);
		merge_sort(a,m+1,r);
		merge(a,l,m,r);
	}
}
int main(){
	int arr[12]={12,11,10,9,8,7,6,5,4,3,2,1};
	merge_sort(arr,0,11);
	for(int x=0;x<12;x++){
		cout<<arr[x]<<" ";
	}
	return 0;
}
/*int i=l;
	int j=m+1;
	int k=l;
	int temp[12];
	while(i<m && j<=r){
		if(a[i]<=a[j]){
			temp[k]=a[i];
			i++;
			k++;
		}
		else{
			temp[k]=a[j];
			j++;
			k++;
		}
	}
	while(i<=m){
		temp[k]=a[i];
		i++;
		k++;
	}
	while(j<=r){
		temp[k]=a[j];
		j++;
		k++;
	}
	for(int x=l;x<=r;x++){
		a[x]=temp[x];
	}*/
