#include<iostream>
#include<algorithm>
using namespace std;
void move_x_end(char *a,int i){
    if(a[i+1]=='\0' || a[i]=='\0'){
        return;
    }
    if(a[i+1]=='x'){
        int j=0;
        while(a[j+1]!='\0'){
            j++;
        }
        int k=i+1;
        while(k!=j){
            swap(a[k],a[k+1]);
            k++;
        }
         move_x_end(a,i+1);
    }
    if(a[i]=='x'){
        int j=0;
        while(a[j+1]!='\0'){
            j++;
        }
        int k=i;
        while(k!=j){
            swap(a[k],a[k+1]);
            k++;
        }
       move_x_end(a,i+1);
    }
    else{
        move_x_end(a,i+1);
    }
}
int main(){
    char a[1000];
    cin>>a;
    cout<<a<<endl;
    move_x_end(a,0);
    cout<<a;
    return 0;
}