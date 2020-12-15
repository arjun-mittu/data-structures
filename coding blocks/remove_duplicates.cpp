#include<iostream>
#include<cstring>
using namespace std;
void remove_duplicates(char *a,int i){
    if(a[i]=='\0' || a[i+1]=='\0'){
        return;
    }
    if(a[i]==a[i+1]){
        /*int j=i+1;
        while(a[j]!='\0'){
            a[j]=a[j+1];
            j++;
        }*/
        int j=i;
        while(a[j]==a[j+1]){
            j++;
        }
        int dist=j-i;
        j=i+1;
        while(a[j]!='\0'){
            a[j]=a[j+dist];
            j++;
        }
    }
    remove_duplicates(a,i+1);
    return;
}
int main(){
    char a[10000];
    cin>>a;
    remove_duplicates(a,0);
    cout<<a<<" "<<strlen(a);
    return 0;
}