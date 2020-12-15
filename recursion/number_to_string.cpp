#include<iostream>
using namespace std;
char words[][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
void printspell(int n){
    if(n==0){
        return;
    }
    printspell(n/10);
    cout<<words[n%10]<<" ";
    return;
}
int main(){
    int n=2048;
    printspell(n);
    return 0;
}