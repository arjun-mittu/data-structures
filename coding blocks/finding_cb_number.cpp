#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int cb_count=0;
void check_cb(int num){
    if(num==0 || num==1){
        return;
    }
    else{
        int arr[] = { 2, 3,5,7,11,13,17,19,23,29 };
        if (num == 2 || num == 3 || num == 5 || num == 7 || num == 11 || num == 13 || num == 17 || num == 19 || num == 23 || num ==29){
            cb_count++;
            cout<<num<<endl;
            return;
        }
        else if (num % 2 != 0 && num % 3 != 0 && num % 5 != 0 && num % 7 != 0 && num % 11 != 0 && num % 13 != 0 && num % 17 != 0 && num % 19 != 0 && num % 23 != 0 && num % 29 != 0){
            cb_count++;
            cout<<num<<endl;
            return;
        }
        else{
            return;
        }
    }
}
int get_integer(string s,int n){
    if(n==0){
        return 0;
    }
    int digit=s[n-1]-'0';
    int small_ans=get_integer(s,n-1);
    return small_ans*10+digit;
}
void generate_substring(string s,int n){
    string substr_;
    for(int i=0;i<n;i++){
        for(int j=1;j<=n-i;j++){
            substr_=s.substr(i,j);
            int num=get_integer(substr_,substr_.length());
            check_cb(num);
        }
    }
}
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(s.length()==n){
        generate_substring(s,n);
    }
    cout<<cb_count;
    return 0;
}