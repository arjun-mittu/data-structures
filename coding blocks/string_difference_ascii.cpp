#include<iostream>
using namespace std;
void diff_asci(char *a,int i){
    if(a[i]=='\0'){
        return;
    }
    int diff=a[i+1]-a[i];
    int j=i;
    while(a[j]!='\0'){
        j++;
    }
    /*int k=j+1;
    while(k!=i){
        a[k]=a[k-1];
        k--;
    }*/
   // a[i+1]=diff+'0';
    if(diff>0){
        int k=j+1;
        while(k!=i){
            a[k]=a[k-1];
            k--;
        }
        a[i+1]=diff+'0';
    }
    else if(diff<0){
        int k=j;
        while(k!=i){
            a[k]=a[k-1];
            k--;
        }
        a[i+1]=diff+'0';
    }
    diff_asci(a,i+2);
}
int main(){
    char a[1000];
    cin>>a;
    diff_asci(a,0);
    cout<<a;

    return 0;
}