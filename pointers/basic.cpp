#include<iostream>
using namespace std;
int main(){
    int x=10;
    cout<<&x<<endl;
    char ch='a';
    cout<<&ch<<endl;
    cout<<(void *)&ch<<endl;

    int *ptr;
    ptr=&x;
    cout<<ptr<<endl;
    return 1;
}