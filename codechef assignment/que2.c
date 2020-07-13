#include<stdio.h>
int max(int a[],int n){
	int i;
	int mx = a[0];
	for(i=1;i<n;i++){
		if(a[i]>mx){
			mx = a[i];
		}
	}
	return mx;
}

void display(int a[],int n){
int i;
for(i=0;i<n;i++){
	printf("%d ",a[i]);
}
printf("\n");	
}

void countingSort(int a[],int n,int pos){
	int b[n];
	int i,j,l;
	int count[10] = {0};
	
	for(i=0;i<n;i++){
		++count[9-((a[i]/pos)%10)];
	}

	for(j=1;j<10;j++){
		count[j]=count[j]+count[j-1];
	}

	
	for(l=n-1;l>=0;l--){
		b[--count[9-((a[l]/pos)%10)]]=a[l];
	}
	for(i=0;i<n;i++){
		a[i]=b[i];
	}	
	display(a,n);
}

void redixSort(int a[],int n){
int mx = max(a,n);
int pos;
for(pos=1;mx/pos>0;pos=pos*10){
	countingSort(a,n,pos);
  }	
}




int main(){
    int i;
    int n;
    scanf("%d",&n);
    int a[n];
	for(i=0;i<n;i++){
	   scanf("%d",&a[i]);
	}
    
	redixSort(a,n);

return 0;	
}
