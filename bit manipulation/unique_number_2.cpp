#include<iostream>
using namespace std;
int main(){
    int n;
    int a[10];
    cin>>n;
    int no;
    int xo=0;
    for(int i=0;i<n;i++){
        cin>>no;
        a[i]=no;
        xo=xo^no;
    }
    int temp=xo;
    int pos=0;
    while((temp&1)!=1){
        pos++;
        temp=temp>>1;
    }
    //first bit im xor is at position 'pos'
    int mask=(1<<pos);

    int x=0;
    int y=0;
    //find those numbers which contain set bit at position pos
    for(int i=0;i<n;i++){
        if((a[i]&mask)>0){
            x=x^a[i];
        }
    }
    y=xo^x;
    cout<<x<<y;
    return 0;
}