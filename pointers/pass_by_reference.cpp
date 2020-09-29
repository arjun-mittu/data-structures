#include<iostream>
using namespace std;
void increment(int *a){
    *a=*a+1;
    cout<<*a<<endl;
}
int main(){
    int a=10;
    increment(&a);
    cout<<a;
    return 0;
}