#include<iostream>
#include<string>
using namespace std;
int main(){
    string s="nfpdmpi";
    int len=s.length();
    int left=0;
    int right=0;
    int max=0;
    int mx;
    while(right<len){
     
        for(int i=left;i<right;i++){
            if(s[i]==s[right]){
                left++;
            }
        }
        if(left==right || s[left]!=s[right]){
            right++;
        }
        /*if(s[left]!=s[right]){
            right++;
        }*/
        if(left>right){
            break;
        }
        mx=right-left;
        if(max<mx){
            max=mx;
        }
        cout<<left<<" "<<right<<endl;
    }
   
    cout<<max;
    return 0;
}